// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice

#ifndef NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__STRUCT_HPP_
#define NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__nxp_cup_interfaces__msg__NxpAim __attribute__((deprecated))
#else
# define DEPRECATED__nxp_cup_interfaces__msg__NxpAim __declspec(deprecated)
#endif

namespace nxp_cup_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NxpAim_
{
  using Type = NxpAim_<ContainerAllocator>;

  explicit NxpAim_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ull;
      this->eagle_stop = 0;
      this->eagle_left = 0;
      this->eagle_right = 0;
      this->eagle_straight = 0;
      this->eagle_green = 0;
      this->eagle_red = 0;
    }
  }

  explicit NxpAim_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0ull;
      this->eagle_stop = 0;
      this->eagle_left = 0;
      this->eagle_right = 0;
      this->eagle_straight = 0;
      this->eagle_green = 0;
      this->eagle_red = 0;
    }
  }

  // field types and members
  using _timestamp_type =
    uint64_t;
  _timestamp_type timestamp;
  using _eagle_stop_type =
    uint8_t;
  _eagle_stop_type eagle_stop;
  using _eagle_left_type =
    uint8_t;
  _eagle_left_type eagle_left;
  using _eagle_right_type =
    uint8_t;
  _eagle_right_type eagle_right;
  using _eagle_straight_type =
    uint8_t;
  _eagle_straight_type eagle_straight;
  using _eagle_green_type =
    uint8_t;
  _eagle_green_type eagle_green;
  using _eagle_red_type =
    uint8_t;
  _eagle_red_type eagle_red;

  // setters for named parameter idiom
  Type & set__timestamp(
    const uint64_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__eagle_stop(
    const uint8_t & _arg)
  {
    this->eagle_stop = _arg;
    return *this;
  }
  Type & set__eagle_left(
    const uint8_t & _arg)
  {
    this->eagle_left = _arg;
    return *this;
  }
  Type & set__eagle_right(
    const uint8_t & _arg)
  {
    this->eagle_right = _arg;
    return *this;
  }
  Type & set__eagle_straight(
    const uint8_t & _arg)
  {
    this->eagle_straight = _arg;
    return *this;
  }
  Type & set__eagle_green(
    const uint8_t & _arg)
  {
    this->eagle_green = _arg;
    return *this;
  }
  Type & set__eagle_red(
    const uint8_t & _arg)
  {
    this->eagle_red = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator> *;
  using ConstRawPtr =
    const nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__nxp_cup_interfaces__msg__NxpAim
    std::shared_ptr<nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__nxp_cup_interfaces__msg__NxpAim
    std::shared_ptr<nxp_cup_interfaces::msg::NxpAim_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NxpAim_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->eagle_stop != other.eagle_stop) {
      return false;
    }
    if (this->eagle_left != other.eagle_left) {
      return false;
    }
    if (this->eagle_right != other.eagle_right) {
      return false;
    }
    if (this->eagle_straight != other.eagle_straight) {
      return false;
    }
    if (this->eagle_green != other.eagle_green) {
      return false;
    }
    if (this->eagle_red != other.eagle_red) {
      return false;
    }
    return true;
  }
  bool operator!=(const NxpAim_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NxpAim_

// alias to use template instance with default allocator
using NxpAim =
  nxp_cup_interfaces::msg::NxpAim_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace nxp_cup_interfaces

#endif  // NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__STRUCT_HPP_
