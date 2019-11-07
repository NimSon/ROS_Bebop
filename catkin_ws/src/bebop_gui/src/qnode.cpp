/***************************************
** #include
***************************************/
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <sstream>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>
#include "../include/bebop_gui/qnode.hpp"


//namespace bebop_gui{


/***************************************
** QNode Constructor and Destructor
***************************************/
// QNode Constructor
QNode::QNode(int argc, char** argv)
:init_argc(argc), init_argv(argv){

}

// QNode Destructor
QNode::~QNode(){
  if(ros::isStarted()){
    ros::shutdown();
    //ros::waitForShutdown();
  }
  //wait();
}


/***************************************
** ROS initailize
***************************************/
bool QNode::init(){
  ros::init(init_argc, init_argv, "bebop_gui"); // ros initailize

  if( !ros::master::check()){
    return false;
  }

  //ros::start();
  ros::NodeHandle nh;

  readyToPublish(nh);
  //start();

  return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url){
  std::map<std::string, std::string> remapping; // std::map(key, value)
  remapping["__master"] = master_url;
  remapping["__hostname"] = host_url;

  ros::init(remapping, "bebop_gui");

  if( !ros::master::check()){
    return false;
  }

  //ros::start();
  ros::NodeHandle nh;

  readyToPublish(nh);
  //start();

  return true;
}

// ros publisher
void QNode::readyToPublish(ros::NodeHandle &nh){
  pub_[TAKEOFF] = nh.advertise<std_msgs::Empty>("/bebop/takeoff", 1);
  pub_[LAND] = nh.advertise<std_msgs::Empty>("/bebop/land", 1);
  pub_[EMERGENCY] = nh.advertise<std_msgs::Empty>("/bebop/reset", 1);
  pub_[MOVE] = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);
}

// ros subscriber
void QNode::subscribers(ros::NodeHandle &nh){
  subscribeGPS = nh.subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 100, &QNode::subGPSData, this);
  subscribeRotation = nh.subscribe("/bebop/states/ardrone3/PilotingState/AttitudeChanged", 100, &QNode::subRotationData, this);
}

//ros subscriber callback functions
void QNode::subGPSData(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& droneGPS){
  droneGPSData.longitude = droneGPS->longitude;			// x
  droneGPSData.latitude = droneGPS->latitude;				// y
  droneGPSData.altitude = droneGPS->altitude;
}

void QNode::subRotationData(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& droneRotation){
  droneRotationData.roll = droneRotation->roll;
  droneRotationData.pitch = droneRotation->pitch;
  droneRotationData.yaw = droneRotation->yaw;
}


/***************************************
** ROS run
***************************************/
void QNode::run(){
  while(ros::ok()){

  }

  Q_EMIT rosShutdown(); // used to signal the gui for a shutdown(useful to roslaunch). 'rosShutdown() signal' 발생
}

//} // namespace bebop_gui
