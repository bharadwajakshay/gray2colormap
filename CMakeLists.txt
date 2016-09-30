cmake_minimum_required(VERSION 2.8.3)
project(gray2colormap)

find_package(cmake_modules REQUIRED)
find_package(Eigen REQUIRED)
find_package(PCL REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  cv_bridge
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs pcl_conversions pcl_ros custom_msgs
)

set(SOURCE_FILES
  src/gray2colormap.cpp 
  src/gray_2_colormap.cpp
)

set(HEADER_FILES
  include/gray2colormap.h
)

include_directories( include
  ${catkin_INCLUDE_DIRS}
  ${Eigen_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

add_executable(gray2colormap ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(gray2colormap ${catkin_LIBRARIES} ${PCL_LIBRARIES})
