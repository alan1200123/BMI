#include"ros/ros.h"
#include"std_msgs/Float32.h"
#include"std_msgs/Int32.h"
void IDcallback(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("ID:%d",msg->data);
}
void bmicallback(const std_msgs::Float32::ConstPtr& msg)
{
	ROS_INFO("BMI:%f\n",msg->data);
}
int main(int argc,char **argv)
{
	ros::init(argc,argv,"output");
	ros::NodeHandle o;
	ros::NodeHandle id;
	ros::Subscriber id_sub = id.subscribe("ID2",1000,IDcallback);
	ros::Subscriber o_sub = o.subscribe("BMI",1000,bmicallback); 	
	ros::spin();
	return 0;
}
