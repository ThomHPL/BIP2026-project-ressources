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

# Documentation
## Wave Rover JSON interface
- Wiki
  - https://www.waveshare.com/wiki/08_Sub-controller_JSON_Command_Set#Composition_of_JSON_Commands 1/10

## Decawave module 
- Module documentation
  - https://www.e-kom.com/Documents/Products/161/DWM1001(2).pdf
- C API code example
  - https://github.com/clout26/DWM1001-DEV/blob/master/DWM1001_host_api/dwm1001_host_api/dwm_driver/dwm_api/dwm_api.c
- List of command types
  - https://github.com/clout26/DWM1001-DEV/blob/master/DWM1001_host_api/dwm1001_host_api/include/dwm1001_tlv.h
