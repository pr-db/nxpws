// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "nxp_cup_interfaces/msg/detail/nxp_aim__struct.h"
#include "nxp_cup_interfaces/msg/detail/nxp_aim__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool nxp_cup_interfaces__msg__nxp_aim__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("nxp_cup_interfaces.msg._nxp_aim.NxpAim", full_classname_dest, 38) == 0);
  }
  nxp_cup_interfaces__msg__NxpAim * ros_message = _ros_message;
  {  // timestamp
    PyObject * field = PyObject_GetAttrString(_pymsg, "timestamp");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->timestamp = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // eagle_stop
    PyObject * field = PyObject_GetAttrString(_pymsg, "eagle_stop");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->eagle_stop = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // eagle_left
    PyObject * field = PyObject_GetAttrString(_pymsg, "eagle_left");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->eagle_left = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // eagle_right
    PyObject * field = PyObject_GetAttrString(_pymsg, "eagle_right");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->eagle_right = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // eagle_straight
    PyObject * field = PyObject_GetAttrString(_pymsg, "eagle_straight");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->eagle_straight = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // eagle_green
    PyObject * field = PyObject_GetAttrString(_pymsg, "eagle_green");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->eagle_green = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // eagle_red
    PyObject * field = PyObject_GetAttrString(_pymsg, "eagle_red");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->eagle_red = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nxp_cup_interfaces__msg__nxp_aim__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NxpAim */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nxp_cup_interfaces.msg._nxp_aim");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NxpAim");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nxp_cup_interfaces__msg__NxpAim * ros_message = (nxp_cup_interfaces__msg__NxpAim *)raw_ros_message;
  {  // timestamp
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->timestamp);
    {
      int rc = PyObject_SetAttrString(_pymessage, "timestamp", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eagle_stop
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->eagle_stop);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eagle_stop", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eagle_left
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->eagle_left);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eagle_left", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eagle_right
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->eagle_right);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eagle_right", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eagle_straight
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->eagle_straight);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eagle_straight", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eagle_green
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->eagle_green);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eagle_green", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // eagle_red
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->eagle_red);
    {
      int rc = PyObject_SetAttrString(_pymessage, "eagle_red", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
