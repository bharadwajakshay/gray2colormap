/*
 * utilities.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: akshay
 */
#include "gray2colormap.h"

gray2colormap::gray2colormap()
{
	ir_8bit = nh.subscribe("/camera/lepton/image_8bit",1000,&gray2colormap::callback8bitimage,this);
	ir_16bit = nh.subscribe("/camera/lepton/image_16bit",1000,&gray2colormap::callback16bitimage,this);
	//ir_struct = nh.subscribe("/structure/ir/image",1000,&gray2colormap::callbackstructimage,this);
	image_mono = nh.advertise<sensor_msgs::Image>("/camera/lepton/image_mono",100);
	image_raw = nh.advertise<sensor_msgs::Image>("/camera/lepton/image_raw",100);
	image_struct = nh.advertise<sensor_msgs::Image>("/structure/ir/image_mono",100);

}

void gray2colormap::callback8bitimage(const sensor_msgs::Image::ConstPtr& msg)
{
	cv_bridge::CvImage cv_image;
	cv_bridge::CvImagePtr img_ptr;
	cv_image.encoding = "mono8";
	cv::Mat image(msg->height*SCALE_FACTOR,msg->width*SCALE_FACTOR,CV_8UC1);
	img_ptr = cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::MONO8);
	cv::resize(img_ptr->image,image,image.size(),0,0,CV_INTER_CUBIC);
	cv_image.image = image;
	cv_image.header = msg->header;
	cv_image.toImageMsg(mono_image);
	image_mono.publish(mono_image);

	//adding colormap
/*	cv_bridge::CvImage cv_color_img;
	cv::Mat colorimg;
	cv::applyColorMap(image,colorimg,cv::COLORMAP_JET);
	cv_color_img.header = msg->header;
	cv_color_img.image = colorimg;
	cv_color_img.encoding = sensor_msgs::image_encodings::RGB8;
	cv_color_img.toImageMsg(raw_image);
	image_raw.publish(raw_image);*/
}

void gray2colormap::callback16bitimage(const sensor_msgs::Image::ConstPtr& msg)
{
	cv_bridge::CvImage cv_image;
	cv_bridge::CvImagePtr img_ptr;
	//cv_image.encoding = "rbg8";
	cv::Mat image(msg->height*SCALE_FACTOR,msg->width*SCALE_FACTOR,CV_8UC1);
	cv::Mat image_temp;
	img_ptr = cv_bridge::toCvCopy(msg,sensor_msgs::image_encodings::MONO16);
	cv::normalize(img_ptr->image,image_temp,0,255,cv::NORM_MINMAX,CV_8UC1);
	cv::resize(image_temp,image,image.size(),0,0,CV_INTER_CUBIC);
	cv::applyColorMap(image,image,cv::COLORMAP_RAINBOW);
	cv_image.header = msg->header;
	cv_image.image = image;
	cv_image.encoding = sensor_msgs::image_encodings::RGB8;
	cv_image.toImageMsg(raw_image);
	image_raw.publish(raw_image);
}

void gray2colormap::callbackstructimage(const sensor_msgs::Image::ConstPtr &msg)
{
	structure_image.header = msg->header;
	structure_image.encoding = msg->encoding;
	structure_image.data = msg->data;
	image_struct.publish(structure_image);
}



