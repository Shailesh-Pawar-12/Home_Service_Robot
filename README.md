# Home_Service_Robot

@author       : Shailesh Pawar
@date         : 6 December 2020
@email        : shaileshpawar320@gmail.com

The goal of this project is to program a robot than can autonomously map an environment and navigate to pick up and drop off virtual objects. 


List of the steps in this project :

* Design a simple environment with the Building Editor in Gazebo.

* Teleoperate robot and manually test SLAM.
   
* Use the ROS navigation stack and manually commands robot using the 2D Nav Goal arrow in rviz to move to 2 different desired positions and orientations.

* Write a pick_objects node that commands robot to move to the desired pickup and drop off zones.

* Write an add_markers node publishes markers to rviz.

* Write a modified_add_markers node that subscribes to robot odometry, keeps track of robot pose, and publishes markers to rviz.


List of folders this project includes are as follows:

1. add_markers
2. maps
3. my_robot
4. pick_objects
5. rvizConfig
6. scripts
7. slam_gmapping
8. teleop_twist_keyboard
9. turtlebot_interactions
10. turtlebot_simulator
11. where_am_i



* add_markers :- 

This folder contain mainly two files in src folder add_markers.cpp and modified_add_markers.cpp


add_markers.cpp file follows this algorithm:

    - Publish the marker at the pickup zone
    - Pause 5 seconds
    - Hide the marker
    - Pause 5 seconds
    - Publish the marker at the drop off zone


modified_add_markers.cpp file follows this algorithm:

    - Initially show the marker at the pickup zone
    - Hide the marker once your robot reaches the pickup zone
    - Wait 5 seconds to simulate a pickup
    - Show the marker at the drop off zone once your robot reaches it


* maps :-

This folder contains the map of the environment which is in map.pgm file.
Along with that it also include meta file in map.yaml file.


* my_robot :-

This folder contain multiple launch files like world.launch file, robot_description.launch file etc.
It also includes meshes folder for hokuyo sensor. Along with that it has URDF file for the robot and world file which is designed in Gazebo.


* pick_objects :-

This folder contain mainly pick_objects.cpp file

pick_objects.cpp file follows this algorithm:

    - Command the robot to travel to pickup zones.
    - Pause 5 second after reaching the pickup zone.
    - Command the robot to travel to drop off zones.


* rvizConfig :-

This folder contain config_file.rviz file to easily load the setup in Rviz


* scripts :-

This folder contain Shell script file which are 

    - add_markers.sh 
    - home_service.sh
    - pick_objects.sh
    - test_navigation.sh
    - test_slam.sh

Respective files are used to easily run and setup the environment.


* slam_gmapping:-

slam_gmapping contains a wrapper around gmapping which provides SLAM capabilities.With the gmapping_demo.launch file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.

For more info please explore http://wiki.ros.org/slam_gmapping


* teleop_twist_keyboard:-

Generic keyboard teleop for twist robots.With the keyboard_teleop.launch file, you can manually control a robot using keyboard commands.

For more info please explore http://wiki.ros.org/teleop_twist_keyboard


* turtlebot_interactions:- 

It mainly inlcudes turtlebot_rviz_launchers: With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you. 

For more info please explore http://wiki.ros.org/turtlebot_rviz_launchers


* turtlebot_simulator:-

It mainly inlcudes turtlebot_gazebo: With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to it. 

For more info please explore http://wiki.ros.org/turtlebot_gazebo


* where_am_i:-

This folder contain amcl.launch file.
amcl is a probabilistic localization system for a robot moving in 2D. It implements the adaptive (or KLD-sampling) Monte Carlo localization approach (as described by Dieter Fox), which uses a particle filter to track the pose of a robot against a known map.

For more info please explore http://wiki.ros.org/amcl

 
