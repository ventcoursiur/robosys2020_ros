#include "ros/ros.h"
#include "dice/ndn.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "rand_n");
	ros::NodeHandle n;
	ros::Publisher rand_pub = n.advertise<dice::ndn>("rand_in", 1000);
	ros::Rate loop_rate(60);
	dice::ndn msg;

	srand((unsigned int)time(NULL));
	//printf("Random_Reset. RAND_MAX = %d\n", RAND_MAX);
	int r = 0;
	while (ros::ok()){
		r = rand();
		msg.a = r;
		rand_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
}
