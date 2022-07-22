#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define INETADDR 10.10.141.34
#define PORT 5000

void error_handling(const char *message);



move_base_msgs::MoveBaseGoal goal1;
move_base_msgs::MoveBaseGoal goal2;
//Goal 1 - goal_pose
goal1.target_pose.pose.position.x = 9.5;
goal1.target_pose.pose.position.y = 1.5;
goal1.target_pose.pose.position.z = 1.5;
  	
goal1.target_pose.pose.orientation.x = 1.0;
goal1.target_pose.pose.orientation.y = 1.0;
goal1.target_pose.pose.orientation.z = 1.0;
goal1.target_pose.pose.orientation.w = 1.0;

//Goal 2 - initial pose
goal2.target_pose.pose.position.x = 9.5;
goal2.target_pose.pose.position.y = 1.5;
goal2.target_pose.pose.position.z = 1.5;
  	
goal2.target_pose.pose.orientation.x = 1.0;
goal2.target_pose.pose.orientation.y = 1.0;
goal2.target_pose.pose.orientation.z = 1.0;
goal2.target_pose.pose.orientation.w = 1.0;


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
	//flag=0 then start_point to goal_point, flag=1 then goal_point to start_point
	int flag = 0;
//socket client
	int sock=socket(PF_INET, SOCK_STREAM, 0);
	if(sock == -1)
		error_handling("socket() error");
	//addr init
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr(INETADDR);
	serv_addr.sin_port(htons(PORT));
	//connect
	if(connect(sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr))==-1)
		error_handling("connect() error");

	char message[30];
	int str_len;
//ROS part
	//register node
	ros::init(argc, argv, "simple_navigation_goals");
	  
	//tell the action client that we want to spin a thread by default
	MoveBaseClient ac("move_base", true);
	
	//wait for the action server to come up
	while(!ac.waitForServer(ros::Duration(5.0))){
		ROS_INFO("Waiting for the move_base action server to come up");
	}
	while(1){
		
		goal.target_pose.header.frame_id = "base_link";
		goal.target_pose.header.stamp = ros::Time::now();
	
		// change mode go to goal_point or to start_point
		str_len=read(sock, message, sizeof(message)-1);
		if(str_len==-1)
			error_handling("read() error!");
		if(message=="go")
			flag = !flag;
		else
			continue;


		//flag =0 then s_pt -> g_pt else g_pt -> s_pt
		if(flag==0)
			ac.sendGoal(goal1);
		else
			ac.sendGoal(goal2);
		
		ROS_INFO("Sending goal");
		
		ac.waitForResult();
		
		if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
			ROS_INFO("arrived");
	  	else
	    	ROS_INFO("failed");
	}

	close(sock);
	return 0;
}
