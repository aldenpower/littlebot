// Copyright 2022 Nestor

#ifndef LITTLEBOT_BASE_LITTLEBOT_TALKER_HPP_
#define LITTLEBOT_BASE_LITTLEBOT_TALKER_HPP_

#include <string>
#include <libserial/serial.hpp>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#define LITTLEBOT_TALKER_PUBLIC __attribute__ ((visibility("default")))

namespace littlebot_base {
class Talker : public rclcpp::Node {
 public:
  LITTLEBOT_TALKER_PUBLIC
  explicit Talker(const rclcpp::NodeOptions & options);

 protected:
  void on_timer();

 private:
  size_t count_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
  std::string message_;

};

}  // namespace littlebot_base

#endif  // LITTLEBOT_BASE_LITTLEBOT_TALKER_HPP_
