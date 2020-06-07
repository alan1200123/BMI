#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"
#include <sstream>
std_msgs::Float32 height;
std_msgs::Float32 weight;
std_msgs::Int32 ID;
void idcallback(const std_msgs::Int32::ConstPtr& msg)
{
        ROS_INFO("ID:%d",msg->data);
        ID.data = msg->data;
}

void hcallback(const std_msgs::Float32::ConstPtr& msg)
{
	ROS_INFO("height:%f",msg->data);
	height.data = msg->data;
}
void wcallback(const std_msgs::Float32::ConstPtr& msg)
{
        ROS_INFO("weight:%f",msg->data);
	weight.data = msg->data;
}


int main(int argc,char **argv)
{
	ros::init(argc,argv,"calculate");
	ros::NodeHandle hh;
	ros::NodeHandle ww;
	ros::NodeHandle b;
	ros::NodeHandle i;
	ros::Subscriber id_sub = i.subscribe("ID1",1000, idcallback);
	ros::Subscriber h_sub = hh.subscribe("HEIGHT",1000, hcallback);
	ros::Subscriber w_sub = ww.subscribe("WEIGHT",1000, wcallback);
	ros::Publisher id_pub = i.advertise<std_msgs::Int32>("ID2",1000);
	ros::Publisher bmi_pub = b.advertise<std_msgs::Float32>("BMI",1000);
	ros::Rate loop_rate(0.1);

	
	while(ros::ok())
	{
		float h = height.data;
		float w = weight.data;
		float b = w/(h*h)*10000;
		std_msgs::Float32 bmi;
		
		bmi.data = b;

		bmi_pub.publish(bmi);
		id_pub.publish(ID);

		ROS_INFO("bmi:%f\n",bmi.data);
		ros::spinOnce();
		loop_rate.sleep();
	}
	ros::spin();
	return 0;
}
