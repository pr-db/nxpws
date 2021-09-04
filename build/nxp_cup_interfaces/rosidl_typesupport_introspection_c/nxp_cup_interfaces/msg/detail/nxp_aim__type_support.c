// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "nxp_cup_interfaces/msg/detail/nxp_aim__rosidl_typesupport_introspection_c.h"
#include "nxp_cup_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "nxp_cup_interfaces/msg/detail/nxp_aim__functions.h"
#include "nxp_cup_interfaces/msg/detail/nxp_aim__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void NxpAim__rosidl_typesupport_introspection_c__NxpAim_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  nxp_cup_interfaces__msg__NxpAim__init(message_memory);
}

void NxpAim__rosidl_typesupport_introspection_c__NxpAim_fini_function(void * message_memory)
{
  nxp_cup_interfaces__msg__NxpAim__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember NxpAim__rosidl_typesupport_introspection_c__NxpAim_message_member_array[7] = {
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nxp_cup_interfaces__msg__NxpAim, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "eagle_stop",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nxp_cup_interfaces__msg__NxpAim, eagle_stop),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "eagle_left",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nxp_cup_interfaces__msg__NxpAim, eagle_left),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "eagle_right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nxp_cup_interfaces__msg__NxpAim, eagle_right),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "eagle_straight",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nxp_cup_interfaces__msg__NxpAim, eagle_straight),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "eagle_green",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nxp_cup_interfaces__msg__NxpAim, eagle_green),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "eagle_red",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(nxp_cup_interfaces__msg__NxpAim, eagle_red),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers NxpAim__rosidl_typesupport_introspection_c__NxpAim_message_members = {
  "nxp_cup_interfaces__msg",  // message namespace
  "NxpAim",  // message name
  7,  // number of fields
  sizeof(nxp_cup_interfaces__msg__NxpAim),
  NxpAim__rosidl_typesupport_introspection_c__NxpAim_message_member_array,  // message members
  NxpAim__rosidl_typesupport_introspection_c__NxpAim_init_function,  // function to initialize message memory (memory has to be allocated)
  NxpAim__rosidl_typesupport_introspection_c__NxpAim_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t NxpAim__rosidl_typesupport_introspection_c__NxpAim_message_type_support_handle = {
  0,
  &NxpAim__rosidl_typesupport_introspection_c__NxpAim_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_nxp_cup_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, nxp_cup_interfaces, msg, NxpAim)() {
  if (!NxpAim__rosidl_typesupport_introspection_c__NxpAim_message_type_support_handle.typesupport_identifier) {
    NxpAim__rosidl_typesupport_introspection_c__NxpAim_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &NxpAim__rosidl_typesupport_introspection_c__NxpAim_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
