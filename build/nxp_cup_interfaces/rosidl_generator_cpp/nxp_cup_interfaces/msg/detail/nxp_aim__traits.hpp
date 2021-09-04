// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from nxp_cup_interfaces:msg/NxpAim.idl
// generated code does not contain a copyright notice

#ifndef NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__TRAITS_HPP_
#define NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__TRAITS_HPP_

#include "nxp_cup_interfaces/msg/detail/nxp_aim__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<nxp_cup_interfaces::msg::NxpAim>()
{
  return "nxp_cup_interfaces::msg::NxpAim";
}

template<>
inline const char * name<nxp_cup_interfaces::msg::NxpAim>()
{
  return "nxp_cup_interfaces/msg/NxpAim";
}

template<>
struct has_fixed_size<nxp_cup_interfaces::msg::NxpAim>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<nxp_cup_interfaces::msg::NxpAim>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<nxp_cup_interfaces::msg::NxpAim>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // NXP_CUP_INTERFACES__MSG__DETAIL__NXP_AIM__TRAITS_HPP_
