// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice

#ifndef NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__STRUCT_H_
#define NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/NxpAim in the package nxp_cup_interfaces.
typedef struct nxp_cup_interfaces__msg__NxpAim
{
  uint64_t timestamp;
  uint8_t eagle_stop;
  uint8_t eagle_left;
  uint8_t eagle_right;
  uint8_t eagle_straight;
  uint8_t eagle_green;
  uint8_t eagle_red;
} nxp_cup_interfaces__msg__NxpAim;

// Struct for a sequence of nxp_cup_interfaces__msg__NxpAim.
typedef struct nxp_cup_interfaces__msg__NxpAim__Sequence
{
  nxp_cup_interfaces__msg__NxpAim * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nxp_cup_interfaces__msg__NxpAim__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__STRUCT_H_
