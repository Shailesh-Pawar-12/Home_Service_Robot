#!/bin/sh
xterm  -e  "   cd ~/catkin_ws; source devel/setup.bash; roslaunch my_robot world.launch" &
sleep 5
xterm  -e  "   cd ~/catkin_ws; source devel/setup.bash; rosrun teleop_twist_keyboard teleop_twist_keyboard.py " &
sleep 5
xterm  -e  "   cd ~/catkin_ws; source devel/setup.bash; roslaunch my_robot mapping.launch " 

