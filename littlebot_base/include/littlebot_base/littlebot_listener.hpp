
// Copyright Nestor 2022

#ifndef LITTLEBOT_BASE_LITTLEBOT_LISTENER_HPP_
#define LITTLEBOT_BASE_LITTLEBOT_LISTENER_HPP_

#include <string>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "std_msgs/msg/string.hpp"

#include "littlebot_base/protocol.hpp"

#define LITTLEBOT_LISTENER_CPP_PUBLIC __attribute__ ((visibility("default")))
#define LITTLEBOT_LISTENER_CPP_LOCAL __attribute__ ((visibility("hidden")))

namespace littlebot_base {
class Listener : public rclcpp::Node {
 public:
  LITTLEBOT_LISTENER_CPP_PUBLIC
  explicit Listener(const rclcpp::NodeOptions & options);

  LITTLEBOT_LISTENER_CPP_PUBLIC
  explicit Listener(const rclcpp::NodeOptions & options, serial::Serial *serial);

 private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_;
  
  serial::Serial *serial_;
};

}  // namespace littlebot_base

#endif  // LITTLEBOT_BASE_LITTLEBOT_LISTENER_HPP_