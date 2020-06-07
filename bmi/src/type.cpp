#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"
#include <sstream>
using namespace std;

int main(int argc, char **argv)
{
	ros::init(argc,argv,"type");
	ros::NodeHandle hh;
	ros::NodeHandle ww;
	ros::NodeHandle i;
	ros::Publisher h_pub = hh.advertise<std_msgs::Float32>("HEIGHT",1000);
	ros::Publisher w_pub = ww.advertise<std_msgs::Float32>("WEIGHT",1000);
	ros::Publisher id_pub = i.advertise<std_msgs::Int32>("ID1",1000);
	ros::Rate loop_rate(0.1);

	int count = 1;
	srand(time(NULL));
	while(ros::ok())
	{
		float h = rand()%50+150;
		float w = rand()%60+40;
		std_msgs::Float32 height;
		std_msgs::Float32 weight;
		std_msgs::Int32 ID;
				
		height.data = h;
		weight.data = w;
		ID.data = count;

		id_pub.publish(ID);
		h_pub.publish(height);
		w_pub.publish(weight);

		ROS_INFO("ID:%d",ID.data);
		ROS_INFO("height:%f",height.data);
		ROS_INFO("weight:%f\n",weight.data);
		ros::spinOnce();
		loop_rate.sleep();
		count++;
	}
	return 0;
}
