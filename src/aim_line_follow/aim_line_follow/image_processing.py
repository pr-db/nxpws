#!/usr/bin/python
from threading import local
import rclpy
from rclpy.node import Node
import os
import numpy as np

from rclpy.qos import qos_profile_sensor_data
from rclpy.exceptions import ParameterNotDeclaredException
from rcl_interfaces.msg import Parameter
from rcl_interfaces.msg import ParameterType
from rcl_interfaces.msg import ParameterDescriptor
from sensor_msgs.msg import Image, CameraInfo
from datetime import datetime
import cv2
from cv_bridge import CvBridge
from nxp_cup_interfaces.msg import NxpAim


class Testmain(Node):

    def __init__(self):
        super().__init__('test')
        self.get_logger().info('Started')

        self.bridge = CvBridge()

        self.contour_no = 1
        self.stop_sign_no = 0

        self.image_process = NxpAim()

        self.camera_input_topic = "/trackImage0/image_raw"

        # Path of the files used for sign detection in YOLO
        self.net = cv2.dnn.readNet(
            "src/aim_line_follow/aim_line_follow/sign_detect.weights", "src/aim_line_follow/aim_line_follow/sign_detect.cfg")

        self.classes = []
        with open("src/aim_line_follow/aim_line_follow/obj.names", "r") as f:
            self.classes = [line.strip() for line in f.readlines()]

        self.layer_names = self.net.getLayerNames()
        self.output_layers = [self.layer_names[i[0] - 1]
                              for i in self.net.getUnconnectedOutLayers()]
        self.colors = np.random.uniform(0, 255, size=(len(self.classes), 3))
        self.stop_sign_no = 0
        # -----------------------------------------SUBSCRIBERS-----------------------------------------

        # subscriber for traffic light detection
        self.CV_subscriber = self.create_subscription(
            Image,
            self.camera_input_topic,
            self.CV_callback,
            qos_profile_sensor_data)

        # subscriber for sign detection
        self.sign_subscriber = self.create_subscription(
            Image,
            self.camera_input_topic,
            self.sign_detect,
            qos_profile_sensor_data)

        # -----------------------------------------PUBLISHERS-----------------------------------------

        # publisher for visualising sign detection
        self.cv_image_publisher = self.create_publisher(
            Image,
            '/sign_detect_image',
            0)

        # Publisher for the publishing data using custom message
        self.image_process_publisher = self.create_publisher(
            NxpAim,
            '/image_process',
            0)

    # ================================================== SIGN DETECTION ==================================================
    # function to detect sign LEFT RIGHT STRAIGHT AND STOP

    def sign_detect(self, img):
        self.right = 0
        self.straight = 0
        cv_img = self.bridge.imgmsg_to_cv2(img, "bgr8")

        #### mask the bottom area to read the selected area ####
        maskWhite = np.ones(cv_img.shape[:2], dtype="uint8") * 255
        mask_ratio_array = [1.0, 0.4]
        maskRectRatioWidthHeight = np.array(
            [float(mask_ratio_array[0]), float(mask_ratio_array[1])])
        imageHeight, imageWidth = cv_img.shape[:2]
        maskVehicleBoxTopLeftXY = (int(imageWidth*(1.0-maskRectRatioWidthHeight[0])/2.0), int(
            imageHeight*(1.0-maskRectRatioWidthHeight[1])))
        maskVehicleBoxBottomRightXY = (int(imageWidth*(1.0+maskRectRatioWidthHeight[0])/2.0),
                                       int(imageHeight))
        maskVehicle = cv2.rectangle(maskWhite, maskVehicleBoxTopLeftXY,
                                    maskVehicleBoxBottomRightXY, color=0, thickness=-1)
        cv_img = cv2.bitwise_and(
            cv_img, cv_img, mask=maskVehicle)

        #### Implementation of YOLO for sign Detection###
        height, width, channels = cv_img.shape
        blob = cv2.dnn.blobFromImage(
            cv_img, 0.00392, (416, 416), (0, 0, 0), True, crop=False)  # create a four dimensional blob from image
        self.net.setInput(blob)  # sets a layer of output blob
        # detect the boxes in the region
        outs = self.net.forward(self.output_layers)
        class_ids = []
        confidences = []
        boxes = []

        for out in outs:
            for detection in out:
                scores = detection[5:]
                class_id = np.argmax(scores)
                confidence = scores[class_id]
                if confidence > 0.5:  # defining confidence threshold to 0.5
                    # Object detected
                    center_x = int(detection[0] * width)
                    center_y = int(detection[1] * height)
                    w = int(detection[2] * width)
                    h = int(detection[3] * height)

                    # Rectangle coordinates
                    x = int(center_x - w / 2)
                    y = int(center_y - h / 2)
                    boxes.append([x, y, w, h])
                    confidences.append(float(confidence))
                    class_ids.append(class_id)
        indexes = cv2.dnn.NMSBoxes(boxes, confidences, 0.4, 0.6)
        font = cv2.FONT_HERSHEY_PLAIN
        label = ""
        for i in range(len(boxes)):
            if i in indexes:
                x, y, w, h = boxes[i]
                label = str(self.classes[class_ids[i]])
                confidence = confidences[i]
                color = self.colors[class_ids[i]]
                # drawing rectangle around the detected sign
                cv2.rectangle(cv_img, (x, y), (x+w, y+h), color, 1)
                cv2.putText(cv_img, label+" "+str(round(confidence, 2)),  # labeling the name of sign detected
                            (x, y-5), font, 1, (0, 0, 0), 1)

        cv_img_ros = self.bridge.cv2_to_imgmsg(cv_img, "bgr8")
        cv_img_ros.header.stamp = img.header.stamp
        self.cv_image_publisher.publish(cv_img_ros)
        if label == "Stop_Sign":
            self.stop_sign_no = 1
        elif label == "Right_Sign":
            self.right = 1
        elif label == "Left_Sign":
            self.right = 1
        elif label == "Straight_Sign":
            self.straight = 1
        self.image_process.eagle_stop = self.stop_sign_no
        self.image_process.eagle_right = self.right
        self.image_process.eagle_straight = self.straight
        self.image_process_publisher.publish(self.image_process)

    # ================================================== SIGN DETECTION END==================================================

    # ================================================== TRAFFIC LIGHT DETECTION ==================================================

    # function to detect traffic light
    def CV_callback(self, msg):

        self.image_process.eagle_green = 0
        self.image_process.eagle_red = 0
        cv_img = self.bridge.imgmsg_to_cv2(msg, "bgr8")

        """
        1) Convert bgr image to hsv for filtering different colours
        2) Detecting the number of Contours from hsv image
        3) Computing the area of the above contours and giving a threshold for this value
        """
        # ------------------------------------------GREEN-----------------------------------------

        hsv = cv2.cvtColor(cv_img, cv2.COLOR_BGR2HSV)
        greenLower = (59, 255, 126)  # 59 61 255 255 126 129
        greenUpper = (61, 255, 129)

        green_img = cv2.inRange(hsv, greenLower, greenUpper)
        green_img_ros = self.bridge.cv2_to_imgmsg(green_img, "8UC1")

        contours_green, heir = cv2.findContours(
            green_img.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)

        contour_no_green = len(contours_green)

        for cnt in contours_green:
            area = cv2.contourArea(cnt)

            if abs(area) > 1000:
                if(contour_no_green > 0):

                    self.image_process.eagle_green = 1
                    self.image_process.eagle_red = 0

        # --------------------------------------------RED--------------------------------------------

        redLower = (0, 255, 125)  # 0 0 255 255 125 129
        redUpper = (0, 255, 129)

        red_img = cv2.inRange(hsv, redLower, redUpper)
        red_img_ros = self.bridge.cv2_to_imgmsg(red_img, "8UC1")

        contours_red, heir = cv2.findContours(
            red_img.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
        contour_no_red = len(contours_red)

        for cnt in contours_red:
            area = cv2.contourArea(cnt)

            if abs(area) > 100:
                if(contour_no_red > 0):

                    self.image_process.eagle_red = 2
            if abs(area) > 7000:
                if(contour_no_red > 0):

                    self.image_process.eagle_red = 1

        # ------------------------------------------------------------------------------------------
        self.image_process_publisher.publish(self.image_process)

    # ================================================== TRAFFIC LIGHT DETECTION END==================================================


def main(args=None):
    rclpy.init(args=args)

    testmain = Testmain()
    rclpy.spin(testmain)

    testmain.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
