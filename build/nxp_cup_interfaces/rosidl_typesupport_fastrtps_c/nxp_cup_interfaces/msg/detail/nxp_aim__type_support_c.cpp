// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice
#include "nxp_cup_interfaces/msg/detail/nxp_aim__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "nxp_cup_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "nxp_cup_interfaces/msg/detail/nxp_aim__struct.h"
#include "nxp_cup_interfaces/msg/detail/nxp_aim__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _NxpAim__ros_msg_type = nxp_cup_interfaces__msg__NxpAim;

static bool _NxpAim__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _NxpAim__ros_msg_type * ros_message = static_cast<const _NxpAim__ros_msg_type *>(untyped_ros_message);
  // Field name: timestamp
  {
    cdr << ros_message->timestamp;
  }

  // Field name: eagle_stop
  {
    cdr << ros_message->eagle_stop;
  }

  // Field name: eagle_left
  {
    cdr << ros_message->eagle_left;
  }

  // Field name: eagle_right
  {
    cdr << ros_message->eagle_right;
  }

  // Field name: eagle_straight
  {
    cdr << ros_message->eagle_straight;
  }

  // Field name: eagle_green
  {
    cdr << ros_message->eagle_green;
  }

  // Field name: eagle_red
  {
    cdr << ros_message->eagle_red;
  }

  return true;
}

static bool _NxpAim__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _NxpAim__ros_msg_type * ros_message = static_cast<_NxpAim__ros_msg_type *>(untyped_ros_message);
  // Field name: timestamp
  {
    cdr >> ros_message->timestamp;
  }

  // Field name: eagle_stop
  {
    cdr >> ros_message->eagle_stop;
  }

  // Field name: eagle_left
  {
    cdr >> ros_message->eagle_left;
  }

  // Field name: eagle_right
  {
    cdr >> ros_message->eagle_right;
  }

  // Field name: eagle_straight
  {
    cdr >> ros_message->eagle_straight;
  }

  // Field name: eagle_green
  {
    cdr >> ros_message->eagle_green;
  }

  // Field name: eagle_red
  {
    cdr >> ros_message->eagle_red;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nxp_cup_interfaces
size_t get_serialized_size_nxp_cup_interfaces__msg__NxpAim(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _NxpAim__ros_msg_type * ros_message = static_cast<const _NxpAim__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name timestamp
  {
    size_t item_size = sizeof(ros_message->timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name eagle_stop
  {
    size_t item_size = sizeof(ros_message->eagle_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name eagle_left
  {
    size_t item_size = sizeof(ros_message->eagle_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name eagle_right
  {
    size_t item_size = sizeof(ros_message->eagle_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name eagle_straight
  {
    size_t item_size = sizeof(ros_message->eagle_straight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name eagle_green
  {
    size_t item_size = sizeof(ros_message->eagle_green);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name eagle_red
  {
    size_t item_size = sizeof(ros_message->eagle_red);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _NxpAim__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_nxp_cup_interfaces__msg__NxpAim(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_nxp_cup_interfaces
size_t max_serialized_size_nxp_cup_interfaces__msg__NxpAim(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: timestamp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: eagle_stop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: eagle_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: eagle_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: eagle_straight
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: eagle_green
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: eagle_red
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _NxpAim__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_nxp_cup_interfaces__msg__NxpAim(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_NxpAim = {
  "nxp_cup_interfaces::msg",
  "NxpAim",
  _NxpAim__cdr_serialize,
  _NxpAim__cdr_deserialize,
  _NxpAim__get_serialized_size,
  _NxpAim__max_serialized_size
};

static rosidl_message_type_support_t _NxpAim__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_NxpAim,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, nxp_cup_interfaces, msg, NxpAim)() {
  return &_NxpAim__type_support;
}

#if defined(__cplusplus)
}
#endif
