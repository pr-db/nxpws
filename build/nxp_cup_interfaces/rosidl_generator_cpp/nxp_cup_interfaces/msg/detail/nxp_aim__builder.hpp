// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice

#ifndef NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__BUILDER_HPP_
#define NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__BUILDER_HPP_

#include "nxp_cup_interfaces/msg/detail/nxp_aim__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace nxp_cup_interfaces
{

namespace msg
{

namespace builder
{

class Init_NxpAim_eagle_red
{
public:
  explicit Init_NxpAim_eagle_red(::nxp_cup_interfaces::msg::NxpAim & msg)
  : msg_(msg)
  {}
  ::nxp_cup_interfaces::msg::NxpAim eagle_red(::nxp_cup_interfaces::msg::NxpAim::_eagle_red_type arg)
  {
    msg_.eagle_red = std::move(arg);
    return std::move(msg_);
  }

private:
  ::nxp_cup_interfaces::msg::NxpAim msg_;
};

class Init_NxpAim_eagle_green
{
public:
  explicit Init_NxpAim_eagle_green(::nxp_cup_interfaces::msg::NxpAim & msg)
  : msg_(msg)
  {}
  Init_NxpAim_eagle_red eagle_green(::nxp_cup_interfaces::msg::NxpAim::_eagle_green_type arg)
  {
    msg_.eagle_green = std::move(arg);
    return Init_NxpAim_eagle_red(msg_);
  }

private:
  ::nxp_cup_interfaces::msg::NxpAim msg_;
};

class Init_NxpAim_eagle_straight
{
public:
  explicit Init_NxpAim_eagle_straight(::nxp_cup_interfaces::msg::NxpAim & msg)
  : msg_(msg)
  {}
  Init_NxpAim_eagle_green eagle_straight(::nxp_cup_interfaces::msg::NxpAim::_eagle_straight_type arg)
  {
    msg_.eagle_straight = std::move(arg);
    return Init_NxpAim_eagle_green(msg_);
  }

private:
  ::nxp_cup_interfaces::msg::NxpAim msg_;
};

class Init_NxpAim_eagle_right
{
public:
  explicit Init_NxpAim_eagle_right(::nxp_cup_interfaces::msg::NxpAim & msg)
  : msg_(msg)
  {}
  Init_NxpAim_eagle_straight eagle_right(::nxp_cup_interfaces::msg::NxpAim::_eagle_right_type arg)
  {
    msg_.eagle_right = std::move(arg);
    return Init_NxpAim_eagle_straight(msg_);
  }

private:
  ::nxp_cup_interfaces::msg::NxpAim msg_;
};

class Init_NxpAim_eagle_left
{
public:
  explicit Init_NxpAim_eagle_left(::nxp_cup_interfaces::msg::NxpAim & msg)
  : msg_(msg)
  {}
  Init_NxpAim_eagle_right eagle_left(::nxp_cup_interfaces::msg::NxpAim::_eagle_left_type arg)
  {
    msg_.eagle_left = std::move(arg);
    return Init_NxpAim_eagle_right(msg_);
  }

private:
  ::nxp_cup_interfaces::msg::NxpAim msg_;
};

class Init_NxpAim_eagle_stop
{
public:
  explicit Init_NxpAim_eagle_stop(::nxp_cup_interfaces::msg::NxpAim & msg)
  : msg_(msg)
  {}
  Init_NxpAim_eagle_left eagle_stop(::nxp_cup_interfaces::msg::NxpAim::_eagle_stop_type arg)
  {
    msg_.eagle_stop = std::move(arg);
    return Init_NxpAim_eagle_left(msg_);
  }

private:
  ::nxp_cup_interfaces::msg::NxpAim msg_;
};

class Init_NxpAim_timestamp
{
public:
  Init_NxpAim_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NxpAim_eagle_stop timestamp(::nxp_cup_interfaces::msg::NxpAim::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_NxpAim_eagle_stop(msg_);
  }

private:
  ::nxp_cup_interfaces::msg::NxpAim msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::nxp_cup_interfaces::msg::NxpAim>()
{
  return nxp_cup_interfaces::msg::builder::Init_NxpAim_timestamp();
}

}  // namespace nxp_cup_interfaces

#endif  // NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__BUILDER_HPP_
