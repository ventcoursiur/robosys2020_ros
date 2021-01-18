#include "ros/ros.h"
#include "dice/ndn.h"

int ran = -1;

void chatterCallback(const dice::ndn msg){
	ran = msg.a;
	//printf("r = %d\n", ran);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "normal_d");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("rand_in", 1000, chatterCallback);
	ros::Rate loop_rate(30);
	ros::spinOnce();

	//printf("ran = %d\n", ran);
	int k = 1, s = 6, i, d;
	int ans = 0;
	printf("個数？:");
	scanf("%d", &k);
	printf("面数？:");
	scanf("%d", &s);

	for(i = 0; i < k; i++){
		ros::spinOnce();
		d = (ran % s) + 1;
		ans += d;
		if(i != 0){
			printf("+ ");
		}
		printf("%d ", d);
		loop_rate.sleep();
		ros::spinOnce();
	}
	printf("= %d\n", ans);
	
	return 0;
}
