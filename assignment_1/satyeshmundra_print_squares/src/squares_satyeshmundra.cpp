#include "ros/ros.h"
#include "std_msgs/Int32.h"


std_msgs::Int32 msg1;
ros::Publisher chatter_pub;
void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
  msg1.data=msg->data*msg->data;
  ROS_INFO("the no. subscribed is %d ",(int)msg->data);
 if(ros::ok())
  {
  ROS_INFO("the no. published is %d",msg1.data);
  chatter_pub.publish(msg1);
  }
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "squares");

 
  ros::NodeHandle n;

chatter_pub = n.advertise<std_msgs::Int32>("topic_squares", 1000);
  ros::Subscriber sub = n.subscribe("topic_numbers", 1000, chatterCallback);
  
  
  ros::Rate loop_rate(1);
  loop_rate.sleep();

  ros::spin();

  return 0;
}
