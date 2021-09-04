// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice
#include "nxp_cup_interfaces/msg/detail/nxp_aim__rosidl_typesupport_fastrtps_cpp.hpp"
#include "nxp_cup_interfaces/msg/detail/nxp_aim__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace nxp_cup_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nxp_cup_interfaces
cdr_serialize(
  const nxp_cup_interfaces::msg::NxpAim & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: timestamp
  cdr << ros_message.timestamp;
  // Member: eagle_stop
  cdr << ros_message.eagle_stop;
  // Member: eagle_left
  cdr << ros_message.eagle_left;
  // Member: eagle_right
  cdr << ros_message.eagle_right;
  // Member: eagle_straight
  cdr << ros_message.eagle_straight;
  // Member: eagle_green
  cdr << ros_message.eagle_green;
  // Member: eagle_red
  cdr << ros_message.eagle_red;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nxp_cup_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  nxp_cup_interfaces::msg::NxpAim & ros_message)
{
  // Member: timestamp
  cdr >> ros_message.timestamp;

  // Member: eagle_stop
  cdr >> ros_message.eagle_stop;

  // Member: eagle_left
  cdr >> ros_message.eagle_left;

  // Member: eagle_right
  cdr >> ros_message.eagle_right;

  // Member: eagle_straight
  cdr >> ros_message.eagle_straight;

  // Member: eagle_green
  cdr >> ros_message.eagle_green;

  // Member: eagle_red
  cdr >> ros_message.eagle_red;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nxp_cup_interfaces
get_serialized_size(
  const nxp_cup_interfaces::msg::NxpAim & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: timestamp
  {
    size_t item_size = sizeof(ros_message.timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: eagle_stop
  {
    size_t item_size = sizeof(ros_message.eagle_stop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: eagle_left
  {
    size_t item_size = sizeof(ros_message.eagle_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: eagle_right
  {
    size_t item_size = sizeof(ros_message.eagle_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: eagle_straight
  {
    size_t item_size = sizeof(ros_message.eagle_straight);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: eagle_green
  {
    size_t item_size = sizeof(ros_message.eagle_green);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: eagle_red
  {
    size_t item_size = sizeof(ros_message.eagle_red);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_nxp_cup_interfaces
max_serialized_size_NxpAim(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: timestamp
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: eagle_stop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: eagle_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: eagle_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: eagle_straight
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: eagle_green
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: eagle_red
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _NxpAim__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const nxp_cup_interfaces::msg::NxpAim *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _NxpAim__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<nxp_cup_interfaces::msg::NxpAim *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _NxpAim__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const nxp_cup_interfaces::msg::NxpAim *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _NxpAim__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_NxpAim(full_bounded, 0);
}

static message_type_support_callbacks_t _NxpAim__callbacks = {
  "nxp_cup_interfaces::msg",
  "NxpAim",
  _NxpAim__cdr_serialize,
  _NxpAim__cdr_deserialize,
  _NxpAim__get_serialized_size,
  _NxpAim__max_serialized_size
};

static rosidl_message_type_support_t _NxpAim__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_NxpAim__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace nxp_cup_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_nxp_cup_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<nxp_cup_interfaces::msg::NxpAim>()
{
  return &nxp_cup_interfaces::msg::typesupport_fastrtps_cpp::_NxpAim__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, nxp_cup_interfaces, msg, NxpAim)() {
  return &nxp_cup_interfaces::msg::typesupport_fastrtps_cpp::_NxpAim__handle;
}

#ifdef __cplusplus
}
#endif
