from threading import local
import rclpy
from rclpy.node import Node
import os

from rclpy.exceptions import ParameterNotDeclaredException
from rcl_interfaces.msg import Parameter
from rcl_interfaces.msg import ParameterType
from rcl_interfaces.msg import ParameterDescriptor
from cv_bridge import CvBridge
import cv2

from geometry_msgs.msg import Twist
from geometry_msgs.msg import Vector3
from std_msgs.msg import Float64
from nxp_cup_interfaces.msg import PixyVector
from nxp_cup_interfaces.msg import NxpAim

from time import sleep
from datetime import datetime
import numpy as np
from sensor_msgs.msg import PointCloud2
from sensor_msgs.msg import LaserScan
from sensor_msgs.msg import Image, CameraInfo

prev_error = 0


class LineFollow(Node):

    def __init__(self):
        super().__init__('aim_line_follow')

        self.start_delay = 6.0

        self.camera_vector_topic = "/cupcar0/PixyVector"

        self.camera_input_topic = "/Camera_Input"

        # topic for ros ray sensor
        self.lidar_topic = "/rrbot/laser/scan"

        # topic for pulishing data from custom message
        self.image_process_topic = "/image_process"

        self.linear_velocity = 0.6

        self.angular_velocity = 0.2

        self.stop_flag = 0

        self.stop_increment = 0.005

        self.single_line_steer_scale = 2.5

        self.bridge = CvBridge()

        self.state_description = ''

        self.range_min_def = 0
        self.range_max_def = 0
        self.intensities_def = 0
        self.scan_time_def = 0
        self.angle_min_def = 0
        self.angle_max_def = 0
        self.angle_increment_def = 0
        self.time_increment_def = 0
        self.ranges_def = []

        self.image_process = NxpAim()

        self.obstacle_flag = 0.0

        self.timer_flag = 0.0

        # Time to wait before running
        self.get_logger().info(
            'Waiting to start for {:s}'.format(str(self.start_delay)))
        sleep(self.start_delay)
        self.get_logger().info('Started')

        self.start_time = datetime.now().timestamp()
        self.restart_time = True

        # Subscribers
        self.pixy_subscriber = self.create_subscription(
            PixyVector,
            self.camera_vector_topic,
            self.listener_callback,
            10)

        # lidar subscriber
        self.lidar_subscriber = self.create_subscription(
            LaserScan,
            self.lidar_topic,
            self.scan_callback,
            10)
        # custom message topic subscriber
        self.image_process_subscriber = self.create_subscription(
            NxpAim,
            self.image_process_topic,
            self.image_callback,
            10)

        # PublisherspixyImageCallback
        self.cmd_vel_publisher = self.create_publisher(
            Twist, '/cupcar0/cmd_vel', 10
        )

        self.speed_vector = Vector3()
        self.steer_vector = Vector3()
        self.cmd_vel = Twist()

    def get_num_vectors(self, msg):
        num_vectors = 0
        if(not(msg.m0_x0 == 0 and msg.m0_x1 == 0 and msg.m0_y0 == 0 and msg.m0_y1 == 0)):
            num_vectors = num_vectors + 1
        if(not(msg.m1_x0 == 0 and msg.m1_x1 == 0 and msg.m1_y0 == 0 and msg.m1_y1 == 0)):
            num_vectors = num_vectors + 1
        return num_vectors

    """
    This function is used for applying brakes either for stop sign or red light
    It can be further customised for a dynamic braking system that changes the linear and
    angular velocities according to the argument of the function
    """

    def brake(self, br):
        if(br == 0):
            self.linear_velocity = 0.0
            self.angular_velocity = 0.0

        self.speed_vector.x = self.linear_velocity
        self.steer_vector.z = self.angular_velocity

        self.cmd_vel.linear = self.speed_vector
        self.cmd_vel.angular = self.steer_vector

    """
    Scan_callback is the callback function for the subscriber of the lidar data
    It takes data from the lidar topic and stores it in the class variables so that they 
    can be used in all the functions
    """

    def scan_callback(self, msg):

        self.range_min_def = msg.range_min
        self.range_max_def = msg.range_max
        self.intensities_def = msg.intensities
        self.scan_time_def = msg.scan_time
        self.angle_min_def = msg.angle_min
        self.selangle_max_def = msg.angle_max

        self.ranges_def = msg.ranges
        self.angle_max_def = msg.angle_max
        self.angle_increment_def = msg.angle_increment
        self.time_increment_def = msg.time_increment

    """
    image_callback is the callback function for our custom message.
    It takes data from the image process topic and stores it in class variables to be further used
    """

    def image_callback(self, msg):

        self.image_process.eagle_green = msg.eagle_green
        self.image_process.eagle_red = msg.eagle_red
        self.image_process.eagle_left = msg.eagle_left
        self.image_process.eagle_right = msg.eagle_right
        self.image_process.eagle_straight = msg.eagle_straight
        self.image_process.eagle_stop = msg.eagle_stop

    """
    listener_callback is the callback function for the pixy subscriber.
    It is our main function where all the data is used for decision making, object detection, image
    processing and motion control.
    With correct conditions the logic switches between line following, obstacle avoidance, light
    detection and sign detection for uninterrupted flow of control..
    """

    def listener_callback(self, msg):

        ####################################################################################################################################################################################

        # ===============================================LINE FOLLOWING======================================================

        # prev_error is a global variable that stores the error value of the previous iteration, and it is updated after
        # each iteration.
        global prev_error

        # Kp is the proportional gain
        # Increasing the proportional gain (Kp) proportionally increases the control signal for the same level of error.
        kp = 0.03

        # Kd is the derivative gain
        # The derivative control changes with the change in the error value. More change implies more steer
        kd = 0.6

        # Ki is the Integral gain
        # The integrator builds with a persistent, steady error thereby increasing the control signal and
        # driving the error down.
        ki = 0.02

        self.angular_velocity = 0.2
        self.linear_velocity = 0.40

        if(msg.m0_x1 == 0):

            msg.m0_x1, msg.m0_x0 = msg.m0_x0, msg.m0_x1
            msg.m0_y1, msg.m0_y0 = msg.m0_y0, msg.m0_y1

        # if(msg.m1_x1 == 0):

        #     msg.m1_x1, msg.m1_x0 = msg.m1_x0, msg.m1_x1
        #     msg.m1_y1, msg.m1_y0 = msg.m1_y0, msg.m1_y1

        current_time = datetime.now().timestamp()
        frame_width = 100
        frame_height = 68
        window_center = (frame_width / 2)
        x = 0
        y = 0
        steer = 0
        speed = 0
        num_vectors = self.get_num_vectors(msg)
        if(num_vectors == 0):
            if self.restart_time:
                self.start_time = datetime.now().timestamp()
                self.restart_time = False
            if (self.start_time+4.0) > current_time:
                speed = self.linear_velocity * \
                    (4.0-(current_time-self.start_time))/4.0
            if (self.start_time+4.0) <= current_time:
                speed = 0
            steer = 0

        if(num_vectors == 1):
            if not self.restart_time:
                self.start_time = datetime.now().timestamp()
                self.restart_time = True
            if(msg.m0_x1 > msg.m0_x0):
                x = (msg.m0_x1 - msg.m0_x0) / frame_width
                y = (msg.m0_y1 - msg.m0_y0) / frame_height
            else:
                x = (msg.m0_x0 - msg.m0_x1) / frame_width
                y = (msg.m0_y0 - msg.m0_y1) / frame_height
            if(msg.m0_x0 != msg.m0_x1 and y != 0):
                steer = (self.angular_velocity) * (x / y) * \
                    self.single_line_steer_scale
                if (self.start_time+1.0) > current_time:
                    speed = self.linear_velocity * \
                        ((current_time-self.start_time)/4.0)
                if (self.start_time+1.0) <= current_time:
                    speed = self.linear_velocity
            else:
                steer = 0
                if (self.start_time+4.0) > current_time:
                    speed = self.linear_velocity * \
                        ((current_time-self.start_time)/4.0)*0.4
                if (self.start_time+4.0) <= current_time:
                    speed = self.linear_velocity*0.7

        if(num_vectors == 2):

            if not self.restart_time:
                self.start_time = datetime.now().timestamp()
                self.restart_time = True

            # ----------------------------------------------PID ALgorithm implementation----------------------------------------------

            # ideal values for PID
            m0_xi = 30
            m1_xi = 67

            # error is calculated as the diference between ideal and the current values
            # the error from both the vectors is summed for the total error
            error1 = (m0_xi-msg.m0_x1)
            error2 = (m1_xi-msg.m1_x1)
            error = error1+error2

            # the final error for the PID control is calculated as P = Kp*E + Kd*Ed + Ki*Ei
            # where E, Ed and Ei are error differential error and integral error respectively
            total_error = kp * (error) + kd * (error -
                                               prev_error) + ki * (error)
            prev_error = error

            steer = self.angular_velocity * (total_error)

            # ---------------------------------------------------------------------------------------------------------------------------

            if (self.start_time+1.0) > current_time:
                speed = self.linear_velocity * \
                    ((current_time-self.start_time)/9.0)
            if (self.start_time+1.0) <= current_time:
                speed = self.linear_velocity

            # Manual steering control for precise traversing
            if (self.image_process.eagle_red == 2):
                steer = -self.angular_velocity * 2
            else:
                if(msg.m0_x0 == 0 and msg.m0_y0 < 20 and msg.m0_y1 == 0 and msg.m0_x1 > 90 and msg.m1_x0 == 0 and msg.m1_y0 < 35 and msg.m1_x1 == 100 and msg.m1_y1 < 30):
                    steer = self.angular_velocity * 2

                elif(msg.m0_x0 == 0 and msg.m0_y0 < 30 and msg.m0_y1 > 0 and msg.m0_x1 == 100 and msg.m1_x0 == 0 and msg.m1_y0 < 50 and msg.m1_x1 == 100 and msg.m1_y1 < 40):
                    steer = self.angular_velocity * 2

                elif(msg.m0_x0 == 0 and msg.m0_y0 < 30 and msg.m0_y1 >= 0 and msg.m0_x1 < 70 and msg.m1_x1 == 0 and msg.m1_y1 < 24 and msg.m1_x0 < 40 and msg.m1_y0 == 0):
                    steer = self.angular_velocity * 4

                elif(msg.m0_x0 == 0 and msg.m0_y0 < 30 and msg.m0_y1 >= 0 and msg.m0_x1 < 70 and msg.m1_x1 == 100 and msg.m1_y1 < 24 and msg.m1_x0 == 0 and msg.m1_y0 < 40):
                    steer = self.angular_velocity * 4

                elif (msg.m1_y1 == 0 and msg.m1_y0 > 12 and msg.m1_y0 < 40 and msg.m0_x0 == 0 and msg.m0_x1 == 100 and msg.m1_x1 > 76):
                    steer = self.angular_velocity * 2

        self.speed_vector.x = float(speed*(1-np.abs(0.01*steer)))
        self.steer_vector.z = float(steer)

        self.cmd_vel.linear = self.speed_vector
        self.cmd_vel.angular = self.steer_vector

        # ==================================================LINE FOLLOWING END====================================================

        ##########################################################################################################################################################################################

        # ==================================================OBSTACLE AVOIDANCE=====================================================

        """
        Range data from the ray sensor is divided into 6 regions and different cases are formulated based on
        which region or combination of regions the obstacle lies
        """
        regions = {
            'right':  min(min(self.ranges_def[0:53]), 10),
            'rright': min(min(self.ranges_def[53:107]), 10),
            'rfront': min(min(self.ranges_def[107:160]), 10),
            'lfront': min(min(self.ranges_def[160:213]), 10),
            'lleft': min(min(self.ranges_def[213:267]), 10),
            'left':   min(min(self.ranges_def[267:320]), 10),
        }

        if regions['lleft'] > 0.45 and regions['lfront'] > 0.45 and regions['rfront'] > 0.45 and regions['rright'] > 0.45:
            self.state_description = 'case 1 - nothing'  # do nothing

        elif regions['lleft'] < 0.45 and regions['lfront'] > 0.45 and regions['rfront'] > 0.45 and regions['rright'] > 0.45:
            self.state_description = 'case 2 - lleft'  # slight right

        elif regions['lleft'] > 0.45 and regions['lfront'] < 0.45 and regions['rfront'] > 0.45 and regions['rright'] > 0.45:
            self.state_description = 'case 3 - lfront'  # extra right

        elif regions['lleft'] > 0.45 and regions['lfront'] > 0.45 and regions['rfront'] < 0.45 and regions['rright'] > 0.45:
            self.state_description = 'case 4 - rfront'  # extra left

        elif regions['lleft'] > 0.45 and regions['lfront'] > 0.45 and regions['rfront'] > 0.45 and regions['rright'] < 0.45:
            self.state_description = 'case 5 - rright'  # slight left

        elif regions['lleft'] < 0.45 and regions['lfront'] < 0.45 and regions['rfront'] > 0.45 and regions['rright'] > 0.45:
            self.state_description = 'case 6 - lleft + lfront'

        elif regions['lleft'] < 0.45 and regions['lfront'] > 0.45 and regions['rfront'] < 0.45 and regions['rright'] > 0.45:
            self.state_description = 'case 7 - lleft + rfront'

        elif regions['lleft'] < 0.45 and regions['lfront'] > 0.45 and regions['rfront'] > 0.45 and regions['rright'] < 0.45:
            self.state_description = 'case 8 - lleft + rright'

        elif regions['lleft'] > 0.45 and regions['lfront'] < 0.45 and regions['rfront'] < 0.45 and regions['rright'] > 0.45:
            self.state_description = 'case 9 - lfront + rfront'

        elif regions['lleft'] > 0.45 and regions['lfront'] < 0.45 and regions['rfront'] > 0.45 and regions['rright'] < 0.45:
            self.state_description = 'case 10 - lfront + rright'

        elif regions['lleft'] > 0.45 and regions['lfront'] > 0.45 and regions['rfront'] < 0.45 and regions['rright'] < 0.45:
            self.state_description = 'case 11 - rfront + rright'

        elif regions['lleft'] < 0.45 and regions['lfront'] < 0.45 and regions['rfront'] < 0.45 and regions['rright'] > 0.45:
            self.state_description = 'case 12 - lleft + lfront + rfront'

        elif regions['lleft'] < 0.45 and regions['lfront'] < 0.45 and regions['rfront'] > 0.45 and regions['rright'] < 0.45:
            self.state_description = 'case 13 - lleft + lfront + rright'

        elif regions['lleft'] < 0.45 and regions['lfront'] > 0.45 and regions['rfront'] < 0.45 and regions['rright'] < 0.45:
            self.state_description = 'case 14 - lleft + rfront + rright'

        elif regions['lleft'] > 0.45 and regions['lfront'] < 0.45 and regions['rfront'] < 0.45 and regions['rright'] < 0.45:
            self.state_description = 'case 15 - lfront + rfront + rright'

        elif regions['lleft'] < 0.45 and regions['lfront'] < 0.45 and regions['rfront'] < 0.45 and regions['rright'] < 0.45:
            self.state_description = 'case 16 - saare obstacle bhoi heavy driver'

        # elif regions['left'] < 0.45:
        #     self.state_description = 'case 17 - left'

        # elif regions['right'] < 0.45:
        #     self.state_description = 'case 18 - right'

        """
        A function take_action is defined which gives lateral and longitudnal control based on the case in which the
        obstacle is detected. Each case has differnt steer value according to how far the obstacle is from the car
        and how far it needs to turn to avoid it.
        The speed of the car is also decreased according to how close the car is to the obstacle so that the car 
        doesn't collide with the obstacle due to momentum of high speed
        """
        def take_action(regions):

            if self.state_description == 'case 2 - lleft':
              #  self.linear_velocity = 0.4# * (max(regions['lleft'], 0.5))
                self.angular_velocity = -0.0

            elif self.state_description == 'case 3 - lfront':
              #  self.linear_velocity = 0.4#* (max(regions['lfront'], 0.5))
                self.angular_velocity = -0.25

            elif self.state_description == 'case 4 - rfront':
               # self.linear_velocity = 0.4#* (max(regions['rfront'], 0.5))
                self.angular_velocity = 0.25

            elif self.state_description == 'case 5 - rright':
               # self.linear_velocity = 0.4#* (max(regions['rright'], 0.5))
                self.angular_velocity = 0.1

            elif self.state_description == 'case 6 - lleft + lfront':
               # self.linear_velocity = 0.4#* \
                #(max(regions['lfront'], regions['lleft'], 0.5))
                self.angular_velocity = -0.20

            elif self.state_description == 'case 7 - lleft + rfront':
               # self.linear_velocity = 0.4# * \
                # (max(regions['rfront'], regions['lleft'], 0.5))
                self.angular_velocity = 0.1

            elif self.state_description == 'case 8 - lleft + rright':
               # self.linear_velocity = 0.5 * \
                # (max(regions['lleft'], regions['rright'], 0.5))
                self.angular_velocity = 0.0

            elif self.state_description == 'case 9 - lfront + rfront':
               # self.linear_velocity = 0.5 * \
                #(max(regions['lfront'], regions['rfront'], 0.5))
                self.angular_velocity = -0.4

            elif self.state_description == 'case 10 - lfront + rright':
               # self.linear_velocity = 0.5 * \
                # (max(regions['lfront'], regions['rright'], 0.5))
                self.angular_velocity = -0.1

            elif self.state_description == 'case 11 - rfront + rright':
               # self.linear_velocity = 0.5 * \
                # (max(regions['rfront'], regions['rright'], 0.5))
                self.angular_velocity = 0.3

            elif self.state_description == 'case 12 - lleft + lfront + rfront':
               # self.linear_velocity = 0.5 * \
                # (max(regions['lleft'], regions['lfront'],
                #     regions['rfront'], 0.5))
                self.angular_velocity = -0.4

            elif self.state_description == 'case 13 - lleft + lfront + rright':
               # self.linear_velocity = 0.5 * \
                # (max(regions['lleft'], regions['lfront'],
                #     regions['rright'], 0.5))
                self.angular_velocity = -0.1

            elif self.state_description == 'case 14 - lleft + rfront + rright':
               # self.linear_velocity = 0.5 * \
                # (max(regions['lleft'], regions['rfront'],
                #     regions['rright'], 0.5))
                self.angular_velocity = 0.1

            elif self.state_description == 'case 15 - lfront + rfront + rright':
                # self.linear_velocity = 0.5 * \
                # (max(regions['lfront'], regions['rfront'],
                #     regions['rright'], 0.5))
                self.angular_velocity = 0.4

            elif self.state_description == 'case 16 - saare obstacle bhoi heavy driver':
                # self.linear_velocity = -0.5 * \
                # (max(regions['lleft'], regions['lfront'],
                #    regions['rfront'], regions['rright'], 0.5))
                self.angular_velocity = 0.0

            self.speed_vector.x = self.linear_velocity
            self.steer_vector.z = self.angular_velocity

            self.cmd_vel.linear = self.speed_vector
            self.cmd_vel.angular = self.steer_vector

        # ==================================================OBSTACLE AVOIDANCE END=====================================================

        ##########################################################################################################################################################################################

        # ======================================================DECISION MAKING========================================================

        """
        This is the main part of the code in which data from all our code segemnts is published to the actuators
        the logic checks for the condition of red light and stop sign and if neither of them are present 
        then the PID values of the cmd_vel are published by default other wise if an obstacle is detected 
        the values from obstacle avoidance is published
        """

        # if red light is detected then the brake function is called and car is stopped
        if(self.image_process.eagle_red == 1):
            self.brake(0)
            self.cmd_vel_publisher.publish(self.cmd_vel)

        # when stop sign is detected the car slowly decelerates to finally stop at the finishing line
        elif(self.image_process.eagle_stop >= 1):

            if(self.stop_flag < 78):
                self.linear_velocity = self.linear_velocity - self.stop_increment*self.stop_flag
                self.stop_flag += 1

            else:
                self.linear_velocity = 0.0

            self.speed_vector.x = self.linear_velocity
            self.steer_vector.z = self.angular_velocity

            self.cmd_vel.linear = self.speed_vector
            self.cmd_vel.angular = self.steer_vector
            self.cmd_vel_publisher.publish(self.cmd_vel)

        else:

            # if default condition then PID values are published
            if(self.state_description == 'case 1 - nothing'):
                self.cmd_vel_publisher.publish(self.cmd_vel)

            # if an obstacle is detected the values from obstacle avoidance are published
            else:
                take_action(regions)
                self.cmd_vel_publisher.publish(self.cmd_vel)


def main(args=None):
    rclpy.init(args=args)

    line_follow = LineFollow()

    rclpy.spin(line_follow)

    line_follow.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
