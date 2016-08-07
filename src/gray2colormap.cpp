#include "gray2colormap.h"


int main(int argc, char **argv)
{
	ros::init(argc,argv,"gray2colormap");
	gray2colormap obj;
	ros::spin();
	return(0);
}
