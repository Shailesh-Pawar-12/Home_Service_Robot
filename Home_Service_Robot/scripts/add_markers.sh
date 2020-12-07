#!/bin/sh
xterm  -e  "  cd ~/catkin_ws; source devel/setup.bash; roslaunch my_robot world.launch" &
sleep 5
xterm  -e  " cd ~/catkin_ws; source devel/setup.bash; roslaunch where_am_i amcl.launch" & 
sleep 5
xterm  -e  " cd ~/catkin_ws; source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 2
xterm  -e  " cd ~/catkin_ws; source devel/setup.bash; rosrun add_markers add_markers" 
