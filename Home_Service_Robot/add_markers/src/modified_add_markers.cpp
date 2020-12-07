#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>

// ROS::Publisher marker_pub;
ros::Publisher marker_pub;
int inital = 0;                   // This is to setup a cube at pickup point initially
float pre_y_pos=0;                // This values are the previous values of y
float pre1_y_pos=0;
float pre2_y_pos=0;
float pre3_y_pos=0;
float pre4_y_pos=0;
float pre5_y_pos=0;







void odomCallback(const nav_msgs::Odometry::ConstPtr &msg){
  float y_pos;

  y_pos = msg->pose.pose.position.y;

  //create_marker_pickup();
  uint32_t shape = visualization_msgs::Marker::CUBE;
  visualization_msgs::Marker marker;
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "/map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "basic_shapes";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;


  if (y_pos > 0.8 && fabs(pre5_y_pos - y_pos)<0.001)      // if current position of y is greater than 0.8 and if values of y are constant for continuous 5th iteration then only condition will become true 
  {
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
  	//marker_hide();
    inital = 1;

  }
  else if(y_pos < -0.8 && fabs(pre5_y_pos - y_pos)<0.001)
  {
  	//create_marker_drop();
    marker.action = visualization_msgs::Marker::ADD;
    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = -1;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;


    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.scale.z = 1;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    //marker.lifetime = ros::Duration();

    // Publish the marker

    marker_pub.publish(marker);
  }
  else if(inital == 0)
  {

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 1;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.scale.z = 1;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker

    marker_pub.publish(marker);

  }
  pre5_y_pos = pre4_y_pos;
  pre4_y_pos = pre3_y_pos;
  pre3_y_pos = pre2_y_pos;
  pre2_y_pos = pre1_y_pos;
  pre1_y_pos = pre_y_pos;
  pre_y_pos = y_pos;

}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "modified_add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  ros::Subscriber sub = n.subscribe("odom",1000, odomCallback);
  // Handle ROS communication events
  ros::spin();

  return 0;

}

