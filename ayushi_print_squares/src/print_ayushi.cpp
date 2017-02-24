#include "ros/ros.h"
#include "std_msgs/Int64.h"

void callback1(const std_msgs::Int64::ConstPtr& num )
{
 ROS_INFO("\nSQUARE OF %ld :  ", num->data);
 return;
}

void callback2(const std_msgs::Int64::ConstPtr& sq)
{
 ROS_INFO("%ld", sq->data);
 return;
}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "print_ayushi");
 ros::NodeHandle n;
 ros::Rate loop_rate(1);

 ros::Subscriber sub_n = n.subscribe("topic_numbers", 1000, callback1);
 ros::Subscriber sub_s = n.subscribe("topic_squares", 1000, callback2);

 ros::spin();
 loop_rate.sleep();
 return 0;
}
