/*
/	GPL-Ver3.0 License
/
/	Copyright (c) 2021, Souma Yamabe.
/	All rights reserved.
*/

#include "ros/ros.h"
#include "dice/ndn.h"
#include <stdio.h>

int main(int argc, char **argv){
	ros::init(argc, argv, "rand_n");
	ros::NodeHandle n;
	ros::Publisher rand_pub = n.advertise<dice::ndn>("rand_in", 1000);
	ros::Rate loop_rate(60);
	dice::ndn msg;

	//printf("Random_Reset. RAND_MAX = %d\n", RAND_MAX);
	int i = 0;
	int r[100] = {
			61352,
			58313,
			1743,
			59486,
			42824,
			6058,
			34734,
			34948,
			2979,
			58654,
			5183,
			35289,
			50108,
			15146,
			41497,
			6336,
			44938,
			15607,
			15129,
			45229,
			59156,
			33604,
			60309,
			37687,
			16278,
			42215,
			62259,
			59096,
			42378,
			6490,
			3368,
			40513,
			62949,
			37599,
			64692,
			48735,
			21057,
			63310,
			16752,
			13325,
			12583,
			16343,
			27133,
			57858,
			11046,
			37626,
			35313,
			22359,
			41858,
			17528,
			39048,
			28574,
			3362,
			27126,
			13560,
			63985,
			3654,
			63442,
			9976,
			13373,
			6169,
			33502,
			21256,
			35249,
			33300,
			12839,
			9869,
			38685,
			12118,
			13668,
			28687,
			20151,
			46429,
			37290,
			11000,
			56704,
			43266,
			15456,
			13581,
			13698,
			56913,
			58873,
			26230,
			15520,
			16683,
			9605,
			53074,
			33407,
			6261,
			52422,
			17755,
			30416,
			49512,
			61961,
			51745,
			24570,
			18778,
			26504,
			17266,
			4722
	};
	while (ros::ok()){
		msg.a = r[i];
		rand_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		i++;
		if(i >= 100){
			i = 0;
		}
	}
}
