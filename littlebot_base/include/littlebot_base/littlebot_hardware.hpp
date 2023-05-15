#ifndef LITTLEBOT_BASE__LITTLEBOT_HARDWARE_HPP_
#define LITTLEBOT_BASE__LITTLEBOT_HARDWARE_HPP_

#include <chrono>
#include <memory>
#include <string>
#include <vector>

#include <libserial/serial.hpp>

#include "hardware_interface/base_interface.hpp"
#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "hardware_interface/types/hardware_interface_status_values.hpp"
#include "hardware_interface/visibility_control.h"

#include "rclcpp/clock.hpp"
#include "rclcpp/duration.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "rclcpp_lifecycle/state.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time.hpp"


using namespace std::chrono_literals;

namespace littlebot_base
{
class LittlebotHardware 
: public hardware_interface::BaseInterface<hardware_interface::SystemInterface>
{

public:
  RCLCPP_SHARED_PTR_DEFINITIONS(LittlebotHardware)

  HARDWARE_INTERFACE_PUBLIC
  hardware_interface::return_type configure(const hardware_interface::HardwareInfo & info) override;

  HARDWARE_INTERFACE_PUBLIC
  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;

  HARDWARE_INTERFACE_PUBLIC
  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  HARDWARE_INTERFACE_PUBLIC
  hardware_interface::return_type start() override;

  HARDWARE_INTERFACE_PUBLIC
  hardware_interface::return_type stop() override;

  HARDWARE_INTERFACE_PUBLIC
  hardware_interface::return_type read() override;

  HARDWARE_INTERFACE_PUBLIC
  hardware_interface::return_type write() override;

private:
  // Store the command for the simulated robot
  std::vector<double> commands_velocities_;
  std::vector<double> states_positions_;
  std::vector<double> states_velocities_;

  // ROS Parameters
  std::string left_wheel_name_ = "";
  std::string right_wheel_name_ = "";
  std::string serial_port_ = "";
  int encoder_ppr = 0;

  // Serial device
  serial::Serial serial_device_;
};

}  // namespace littlebot_base

#endif  // LITTLEBOT_BASE__LITTLEBOT_HARDWARE_HPP_