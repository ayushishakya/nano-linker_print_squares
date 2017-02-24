#include "ros/ros.h"
#include "std_msgs/Int64.h"

ros::Publisher pub_sq;

void numCallback(const std_msgs::Int64::ConstPtr& num)
{
 ROS_INFO("RECIEVED %ld\n", num->data);
 std_msgs::Int64 sq;
 sq.data = (num->data)*(num->data);

 if(ros::ok())
 {
  pub_sq.publish(sq);
  ROS_INFO("%ld SENT to TOPIC_SQUARES\n", sq.data);
  ros::spinOnce();
 }

}

int main(int argc, char **argv)
{
 ros::init(argc, argv, "squares_ayushi");
 ros::NodeHandle n1;
 ros::NodeHandle n2;
 ros::Rate loop_rate(1);
 
 pub_sq = n2.advertise<std_msgs::Int64>("topic_squares",1000);
 ros::Subscriber square = n1.subscribe("topic_numbers", 1000, numCallback);
 
 ros::spin();
 return 0;
}
