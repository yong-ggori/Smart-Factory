#include "ros/ros.h"
#include "my_ros_tutorials/msgTutorial.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "ros_tutorial_msg_publisher");
	ros::NodeHandle nh;

	ros::Publisher ros_tutorial_pub = nh.advertise<my_ros_tutorials::msgTutorial>("ros_tutorial_msg", 100);

	ros::Rate loop_rate(5);

	int count = 0;

	while (ros::ok())
	{
		my_ros_tutorials::msgTutorial msg;
		msg.data = count;

		ROS_INFO("send msg = %d", count);

		ros_tutorial_pub.publish(msg);

		loop_rate.sleep();

		++count;
	}

	return 0;
}
