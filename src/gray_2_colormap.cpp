/*
 * utilities.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: akshay
 */
#include "gray2colormap.h"

gray2colormap::gray2colormap()
{
	ir_8bit = nh.subscribe("/camera/lepton/image_8bit",1000,gray2colormap::callback8bitimage,this);
	ir_16bit = nh.subscribe("/camera/lepton/image_16bit",1000,gray2colormap::callback16bitimage,this);
	image_mono = nh.advertise<sensor_msgs::Image>("/camera/lepton/image_mono",100);
	image_raw = nh.advertise<sensor_msgs::Image>("/camera/lepton/image_raw",100);

}

void gray2colormap::callback8bitimage(const sensor_msgs::Image::ConstPtr& msg)
{
	cv_bridge::CvImage cv_image;
	cv_image.encoding = "mono8";
	cv::Mat image(msg->height*SCALE_FACTOR,msg->width*SCALE_FACTOR);


}

void gray2colormap::callback16bitimage(const sensor_msgs::Image::ConstPtr& msg)
{

}



