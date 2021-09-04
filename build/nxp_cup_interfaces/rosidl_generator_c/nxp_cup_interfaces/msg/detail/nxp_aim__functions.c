// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice
#include "nxp_cup_interfaces/msg/detail/nxp_aim__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
nxp_cup_interfaces__msg__NxpAim__init(nxp_cup_interfaces__msg__NxpAim * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // eagle_stop
  // eagle_left
  // eagle_right
  // eagle_straight
  // eagle_green
  // eagle_red
  return true;
}

void
nxp_cup_interfaces__msg__NxpAim__fini(nxp_cup_interfaces__msg__NxpAim * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // eagle_stop
  // eagle_left
  // eagle_right
  // eagle_straight
  // eagle_green
  // eagle_red
}

nxp_cup_interfaces__msg__NxpAim *
nxp_cup_interfaces__msg__NxpAim__create()
{
  nxp_cup_interfaces__msg__NxpAim * msg = (nxp_cup_interfaces__msg__NxpAim *)malloc(sizeof(nxp_cup_interfaces__msg__NxpAim));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nxp_cup_interfaces__msg__NxpAim));
  bool success = nxp_cup_interfaces__msg__NxpAim__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
nxp_cup_interfaces__msg__NxpAim__destroy(nxp_cup_interfaces__msg__NxpAim * msg)
{
  if (msg) {
    nxp_cup_interfaces__msg__NxpAim__fini(msg);
  }
  free(msg);
}


bool
nxp_cup_interfaces__msg__NxpAim__Sequence__init(nxp_cup_interfaces__msg__NxpAim__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  nxp_cup_interfaces__msg__NxpAim * data = NULL;
  if (size) {
    data = (nxp_cup_interfaces__msg__NxpAim *)calloc(size, sizeof(nxp_cup_interfaces__msg__NxpAim));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nxp_cup_interfaces__msg__NxpAim__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nxp_cup_interfaces__msg__NxpAim__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
nxp_cup_interfaces__msg__NxpAim__Sequence__fini(nxp_cup_interfaces__msg__NxpAim__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      nxp_cup_interfaces__msg__NxpAim__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

nxp_cup_interfaces__msg__NxpAim__Sequence *
nxp_cup_interfaces__msg__NxpAim__Sequence__create(size_t size)
{
  nxp_cup_interfaces__msg__NxpAim__Sequence * array = (nxp_cup_interfaces__msg__NxpAim__Sequence *)malloc(sizeof(nxp_cup_interfaces__msg__NxpAim__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = nxp_cup_interfaces__msg__NxpAim__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
nxp_cup_interfaces__msg__NxpAim__Sequence__destroy(nxp_cup_interfaces__msg__NxpAim__Sequence * array)
{
  if (array) {
    nxp_cup_interfaces__msg__NxpAim__Sequence__fini(array);
  }
  free(array);
}
