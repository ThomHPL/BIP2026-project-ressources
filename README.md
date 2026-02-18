# Lab L1.5 micro-ROS setup

## Build and Install
```bash
export ROS_EXPORT=jazzy
source /opt/ros/jazzy/setup.bash
# Create a workspace and download the micro-ROS tools
mkdir microros_ws
cd microros_ws
git clone -b $ROS_DISTRO https://github.com/micro-ROS/micro_ros_setup.git src/micro_ros_setup
rosdep install --from-paths src --ignore-src -r -y --as-root apt:false
colcon build

# Add the microros agent qnd msgs sources
cd ~/
git clone https://github.com/ThomHPL/BIP2026-micro-ROS-Wroclaw.git
cp -R BIP2026-micro-ROS-Wroclaw/microros_ws/src/micro-ros-agent ~/microros_ws/src/
cp -R BIP2026-micro-ROS-Wroclaw/microros_ws/src/micro_ros_msgs ~/microros_ws/src/

cd ~/microros_ws
rosdep install --from-paths src --ignore-src -r -y --as-root apt:false
colcon build

source install/local_setup.bash
```

## Run agent
```bash
ros2 run micro_ros_agent micro_ros_agent serial --dev /dev/ttyUSB0 -b 115200
```