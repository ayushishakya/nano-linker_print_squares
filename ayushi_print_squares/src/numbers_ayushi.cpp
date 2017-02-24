#include "ros/ros.h"
#include "std_msgs/Int64.h"

int main(int argc, char ** argv)
{
 ros::init(argc, argv, "numbers_ayushi");
 ros::NodeHandle n;

 ros::Publisher pub_n = n.advertise<std_msgs::Int64>("topic_numbers", 1000);
 
 ros::Rate loop_rate(1);
 
 int num=1;
 
 while(ros::ok())
 {
  std_msgs::Int64 x;
  x.data=num;
  pub_n.publish(x);

  ROS_INFO("%ld SENT to TOPIC_NUMBERS\n", x.data);

  ros::spinOnce();
  loop_rate.sleep(); 
  ++num;
 }

 return 0;

}
