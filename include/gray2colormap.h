/*
 * utilities.h
 *
 *  Created on: Aug 7, 2016
 *      Author: akshay
 */

#ifndef GRAY2COLORMAP_INCLUDE_GRAY2COLORMAP_H_
#define GRAY2COLORMAP_INCLUDE_GRAY2COLORMAP_H_
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <limits.h>
#include "ros/ros.h"
#include "ros/time.h"
#include "std_msgs/String.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/image_encodings.h"

//OPencv + cv_bridge
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include "opencv2/opencv.hpp"

//Camerainfo
#include <image_transport/image_transport.h>
#include <camera_info_manager/camera_info_manager.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/SetCameraInfo.h>

#define SCALE_FACTOR 8

class gray2colormap
{
private:
	ros::NodeHandle nh;
	ros::Subscriber ir_8bit;
	ros::Subscriber ir_16bit;
	ros::Subscriber ir_struct;
	ros::Publisher image_mono;
	ros::Publisher image_raw;
	ros::Publisher image_struct;

public:
	gray2colormap();
	void callback8bitimage(const sensor_msgs::Image::ConstPtr &msg);
	void callback16bitimage(const sensor_msgs::Image::ConstPtr &msg);
	void callbackstructimage(const sensor_msgs::Image::ConstPtr &msg);
	sensor_msgs::Image mono_image;
	sensor_msgs::Image raw_image;
	sensor_msgs::Image structure_image;
};




#endif /* GRAY2COLORMAP_INCLUDE_GRAY2COLORMAP_H_ */

