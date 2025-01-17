
"""Launch a talker and a listener in a component container."""

from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer, Node
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    """Generate launch description with multiple components."""
    container = ComposableNodeContainer(
            name='base_container',
            namespace='littlebot',
            package='rclcpp_components',
            executable='component_container',
            composable_node_descriptions=[
                ComposableNode(
                    package='littlebot_teleop',
                    plugin='littlebot_teleop::Teleop',
                    name='Teleop')
            ],
            output='screen',
    )

    joystick = Node(
        package='joy_linux',
        executable='joy_linux_node',
        name='joystick',
        output='screen',
        arguments=['-p dev_name:="/dev/input/js0"']
        )

    ld = LaunchDescription()
    ld.add_action(container)
    ld.add_action(joystick)

    return ld
