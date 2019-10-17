#include <math.h>

#include "test.h"
#include "kbhit.h"
#include "GPStoXYDistance.h"

#define TAKEOFF 0
#define LAND 1
#define EMERGENCY 2
#define MOVE 3

#define dt 0.001
#define TOLERANCE 0.5

#define maxSpeedX 1
#define maxSpeedY 1
#define maxSpeedZ 0.5
#define maxSpeedYaw 0.5

CONTROL *bebop_control;

// ready to publish commands of takeoff, land, move control
void CONTROL::readyToPublish(ros::NodeHandle& nh){
	ROS_INFO("ready to publish");
	pub_[TAKEOFF] = nh.advertise<std_msgs::Empty>("/bebop/takeoff", 1);
	pub_[LAND] = nh.advertise<std_msgs::Empty>("/bebop/land", 1);
	pub_[EMERGENCY] = nh.advertise<std_msgs::Empty>("/bebop/reset", 1);
	pub_[MOVE] = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);
}

// execute commands of takeoff, land, move control
void CONTROL::executeCommand(ros::Publisher pub){
	ROS_INFO("execute a command");
	std_msgs::Empty command;
	pub.publish(command);
}

/*
<REFERENCE>
Alternatively, you could define a generic queue object with a callback, and pass the object to the subscriber:
MagicQueue magicQueue1, magicQueue2;
ros::Subscriber sub = n.subscribe("topic1",100,&MagicQueue::callback,magicQueue1);
ros::Subscriber sub = n.subscribe("topic2",100,&MagicQueue::callback,magicQueue2);
*/
void CONTROL::subscribers(ros::NodeHandle& nh){
	ROS_INFO("subscribers");
	subscribeHome = nh.subscribe("/bebop/fix", 100, &CONTROL::saveHomeGPS, this);
	subscribeGPS = nh.subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 100, &CONTROL::subGPSData, this);
	subscribeRotation = nh.subscribe("/bebop/states/ardrone3/PilotingState/AttitudeChanged", 100, &CONTROL::subRotationData, this);
}

void CONTROL::saveHomeGPS(const sensor_msgs::NavSatFix::ConstPtr& homeGPS){
	ROS_INFO("subscribers callback function 'saveHomeGPS'");
	homeGPSData.longitude = homeGPS->longitude;			// x
	homeGPSData.latitude = homeGPS->latitude;				// y
	homeGPSData.altitude = homeGPS->altitude + 1;		// '0' is saved to altitude during takeoff

	ROS_INFO("[HOME] LONGITUDE : %lf", homeGPSData.longitude);
	ROS_INFO("[HOME] LATITUDE : %lf", homeGPSData.latitude);
	ROS_INFO("[HOME] ALTITUDE : %lf", homeGPSData.altitude);

	subscribeHome.shutdown();		// close 'subscribeHome' of subscribe
}

void CONTROL::subGPSData(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& droneGPS){
	ROS_INFO("subscribers callback function 'subGPSData'");
	droneGPSData.longitude = droneGPS->longitude;			// x
	droneGPSData.latitude = droneGPS->latitude;				// y
	droneGPSData.altitude = droneGPS->altitude;

	ROS_INFO("[DRONE] LONGITUDE : %lf", droneGPSData.longitude);
	ROS_INFO("[DRONE] LATITUDE : %lf", droneGPSData.latitude);
	ROS_INFO("[DRONE] ALTITUDE : %lf", droneGPSData.altitude);
}

void CONTROL::subRotationData(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& droneRotation){
	ROS_INFO("subscribers callback function 'subRotationData'");
	droneRotationData.roll = droneRotation->roll;
	droneRotationData.pitch = droneRotation->pitch;
	droneRotationData.yaw = droneRotation->yaw;

	ROS_INFO("[DRONE] ROLL : %lf", droneRotationData.roll);
	ROS_INFO("[DRONE] PITCH : %lf", droneRotationData.pitch);
	ROS_INFO("[DRONE] YAW : %lf", droneRotationData.yaw);
}

void CONTROL::returnHome(ros::Publisher& pub){
	ROS_INFO("return home");
	double latitude_gap, longitude_gap, altitude_gap;

	ros::Rate loopRate(100);

	while(calDistance(droneGPSData.latitude, droneGPSData.longitude, homeGPSData.latitude, homeGPSData.longitude) >= TOLERANCE){
		latitude_gap = homeGPSData.longitude - droneGPSData.longitude;	// distance from current position to home position
		longitude_gap = homeGPSData.latitude - droneGPSData.latitude;
		altitude_gap = homeGPSData.altitude - droneGPSData.altitude;

		ROS_INFO("[GAP] XGAP : %lf", latitude_gap);
		ROS_INFO("[GAP] YGAP : %lf", longitude_gap);
		ROS_INFO("[GAP] ZGAP : %lf", altitude_gap);

		ros::spinOnce();
		droneSpeed.linear.x = latitude_gap / dt;
		droneSpeed.linear.y = longitude_gap / dt;
		droneSpeed.linear.z = altitude_gap * dt;

		droneSpeed.angular.x = droneSpeed.angular.y = droneSpeed.angular.z = 0;

		ROS_INFO("[SPEED] X : %lf", droneSpeed.linear.x);
		ROS_INFO("[SPEED] Y : %lf", droneSpeed.linear.y);
		ROS_INFO("[SPEED] Z : %lf", droneSpeed.linear.z);
		ROS_INFO("[HOME] LONGITUDE : %lf", homeGPSData.longitude);
		ROS_INFO("[HOME] LATITUDE : %lf", homeGPSData.latitude);
		ROS_INFO("[HOME] ALTITUDE : %lf", homeGPSData.altitude);
		ROS_INFO("[DRONE] LONGITUDE : %lf", droneGPSData.longitude);
		ROS_INFO("[DRONE] LATITUDE : %lf", droneGPSData.latitude);
		ROS_INFO("[DRONE] ALTITUDE : %lf", droneGPSData.altitude);

		pub.publish(droneSpeed);
		loopRate.sleep();
	}
}

double degreeToRadian(double degree){
	return degree * (M_PI / 180);
}

double radianToDegree(double radian){
	return radian * (180 / M_PI);
}

double latitudeToX(double distance, double latitude, double longitude){
	return distance * cos(latitude) * cos(longitude);
}

double longtitudeToY(double distance, double latitude, double longitude){
	return distance * sin(latitude) * cos(longitude);
}

/*
<SPHERICAL COORDINATES TO RECTANGULAR COORDINATES>
x = r * cos(a) * cos(b)
y = r * sin(a) * cos(b)
z = r * sin(b)

r = sqrt(x* x + y * y + z * z)
a = arctan(y / x)
b = arcsin(z / r)
*/

void CONTROL::controlGPS(ros::Publisher& pub){
	// distance fronm drone' position to destination
	double distance = calDistance(droneGPSData.latitude, droneGPSData.longitude, homeGPSData.latitude, homeGPSData.longitude);		// distance from current positon to goal position

	double droneX, droneY;
	double destinationX, destinationY;
	double x_gap, y_gap, yaw_gap = 1;
	double longitude_gap, latitude_gap, altitude_gap;
	double theta;

	ros::Rate loopRate(100);

	while(distance >= TOLERANCE && abs(yaw_gap) >= 1){
		distance = calDistance(droneGPSData.latitude, droneGPSData.longitude, homeGPSData.latitude, homeGPSData.longitude);
		/* GPS data of drone to X, Y, Z
		droneX = latitudeToX(distance, droneGPSData.latitude, droneGPSData.longitude);
		droneY = longtitudeToY(distance, droneGPSData.latitude, droneGPSData.longitude);
		ROS_INFO("[DRONEXY] X : %lf, Y : %lf", droneX, droneY);
		*/
		/* GPS data of destination to X, Y, Z
		destinationX = latitudeToX(distance, homeGPSData.latitude, homeGPSData.longitude);
		destinationY = longtitudeToY(distance, homeGPSData.latitude, homeGPSData.longitude);
		ROS_INFO("[DESTINATIONXY] X : %lf, Y : %lf", destinationX, destinationY);
		*/
		/* distance from drone' position to destination
		x_gap = destinationX - droneX;
		y_gap = destinationY - droneY;
		*/
		//yaw of droneGPSData : -3 ~ 3 (+y ; 0)
		//theta = degreeToRadian(atan2(y_gap, x_gap));

		// GPS difference
		longitude_gap = homeGPSData.longitude - droneGPSData.longitude;
		latitude_gap = homeGPSData.latitude - droneGPSData.latitude;
		altitude_gap = homeGPSData.altitude - droneGPSData.altitude;
		// theta : current to destination
		theta = radianToDegree(atan2(longitude_gap, latitude_gap));
		// theta(degree) : -180~180
		if(theta >= 180.)
			theta -= 360.;
		else if(theta < -180.)
			theta += 360.;

		yaw_gap = theta - radianToDegree(droneRotationData.yaw);
		// yaw_gap(degree) : -180~180
		if(abs(yaw_gap) > 180.)
			if(theta >= radianToDegree(droneRotationData.yaw))
				yaw_gap -= 360;
			else
				yaw_gap += 360;


		ros::spinOnce();
		// move to destination
		droneSpeed.linear.x = longitude_gap / dt;
		if (droneSpeed.linear.x > maxSpeedX) droneSpeed.linear.x = maxSpeedX;				// define the max speed of x
		else if (droneSpeed.linear.x < -maxSpeedX) droneSpeed.linear.x = -maxSpeedX;
		droneSpeed.linear.y = latitude_gap / dt;
		if (droneSpeed.linear.y > maxSpeedY) droneSpeed.linear.y = maxSpeedY;				// define the max speed of y
		else if (droneSpeed.linear.y < -maxSpeedY) droneSpeed.linear.y = -maxSpeedY;
		droneSpeed.linear.z = altitude_gap * dt;
		if (droneSpeed.linear.z > maxSpeedZ) droneSpeed.linear.z = maxSpeedZ;				// define the max speed of z
		else if (droneSpeed.linear.z < -maxSpeedZ) droneSpeed.linear.z = -maxSpeedZ;
		droneSpeed.angular.z = yaw_gap * dt;
		if (droneSpeed.angular.z > maxSpeedYaw) droneSpeed.angular.z = maxSpeedYaw;	// define the max speed of yaw
		else if (droneSpeed.angular.z < -maxSpeedYaw) droneSpeed.angular.z = -maxSpeedYaw;

		droneSpeed.angular.x = droneSpeed.angular.y = 0;

		ROS_INFO("[HOME] LONGITUDE : %lf", homeGPSData.longitude);
		ROS_INFO("[HOME] LATITUDE : %lf", homeGPSData.latitude);
		ROS_INFO("[HOME] ALTITUDE : %lf", homeGPSData.altitude);
		ROS_INFO("[DRONE] LONGITUDE : %lf", droneGPSData.longitude);
		ROS_INFO("[DRONE] LATITUDE : %lf", droneGPSData.latitude);
		ROS_INFO("[DRONE] ALTITUDE : %lf", droneGPSData.altitude);
		ROS_INFO("[DRONE] YAW : %lf", radianToDegree(droneRotationData.yaw));
		ROS_INFO("[GAP] DISTANCE : %lf", distance);
		ROS_INFO("[GAP] XGAP : %lf", longitude_gap);
		ROS_INFO("[GAP] YGAP : %lf", latitude_gap);
		ROS_INFO("[GAP] ZGAP : %lf", altitude_gap);
		ROS_INFO("[GAP] YAWGAP : %lf, THETA : %lf", yaw_gap, theta);
		ROS_INFO("[SPEED] X : %lf", droneSpeed.linear.x);
		ROS_INFO("[SPEED] Y : %lf", droneSpeed.linear.y);
		ROS_INFO("[SPEED] Z : %lf", droneSpeed.linear.z);
		ROS_INFO("[SPEED] YAW : %lf", droneSpeed.angular.z);

		pub.publish(droneSpeed);
		loopRate.sleep();
	}
}

// control the drone with keyboard
void controlKeyboard(const ros::TimerEvent& timerEventKey){
	init_keyboard();
	if(_kbhit()){
		int ch = _getch();
		_putch(ch);
		switch (ch) {
			case '1': {
				ROS_INFO("take off");
				bebop_control->executeCommand(bebop_control->pub_[TAKEOFF]);
			} break;
			case '2': {
				ROS_INFO("land");
				bebop_control->executeCommand(bebop_control->pub_[LAND]);
			} break;
			case '3': {
				ROS_INFO("emergency landing");
				bebop_control->executeCommand(bebop_control->pub_[EMERGENCY]);
			} break;
			case '4': {
				ROS_INFO("return home");
				bebop_control->returnHome(bebop_control->pub_[MOVE]);
			} break;
			case '5': {
				ROS_INFO("go to destination");
				bebop_control->controlGPS(bebop_control->pub_[MOVE]);
			} break;

			case 'i':			// drone is moving during pushing a key
			case 'I': {
				ROS_INFO("forward");
				bebop_control->droneSpeed.linear.x = 1;
				bebop_control->droneSpeed.linear.y = bebop_control->droneSpeed.linear.z = 0;
				bebop_control->droneSpeed.angular.x = bebop_control->droneSpeed.angular.y = bebop_control->droneSpeed.angular.z = 0;

				bebop_control->pub_[MOVE].publish(bebop_control->droneSpeed);
			} break;
			case 'k':			// drone is moving during pushing a key
			case 'K': {
				ROS_INFO("backward");
				bebop_control->droneSpeed.linear.x = -1;
				bebop_control->droneSpeed.linear.y = bebop_control->droneSpeed.linear.z = 0;
				bebop_control->droneSpeed.angular.x = bebop_control->droneSpeed.angular.y = bebop_control->droneSpeed.angular.z = 0;

				bebop_control->pub_[MOVE].publish(bebop_control->droneSpeed);
			} break;
			case 'j':			// drone is moving during pushing a key
			case 'J': {
				ROS_INFO("left");
				bebop_control->droneSpeed.linear.y = 1;
				bebop_control->droneSpeed.linear.x = bebop_control->droneSpeed.linear.z = 0;
				bebop_control->droneSpeed.angular.x = bebop_control->droneSpeed.angular.y = bebop_control->droneSpeed.angular.z = 0;

				bebop_control->pub_[MOVE].publish(bebop_control->droneSpeed);
			} break;
			case 'l':			// drone is moving during pushing a key
			case 'L': {
				ROS_INFO("right");
				bebop_control->droneSpeed.linear.y = -1;
				bebop_control->droneSpeed.linear.x = bebop_control->droneSpeed.linear.z = 0;
				bebop_control->droneSpeed.angular.x = bebop_control->droneSpeed.angular.y = bebop_control->droneSpeed.angular.z = 0;

				bebop_control->pub_[MOVE].publish(bebop_control->droneSpeed);
			} break;
			case 'w':			// drone is moving during pushing a key
			case 'W': {
				ROS_INFO("up");
				bebop_control->droneSpeed.linear.x = bebop_control->droneSpeed.linear.y = 0;
				bebop_control->droneSpeed.linear.z = 1;
				bebop_control->droneSpeed.angular.x = bebop_control->droneSpeed.angular.y = bebop_control->droneSpeed.angular.z = 0;

				bebop_control->pub_[MOVE].publish(bebop_control->droneSpeed);
			} break;
			case 's':			// drone is moving during pushing a key
			case 'S': {
				ROS_INFO("down");
				bebop_control->droneSpeed.linear.x = bebop_control->droneSpeed.linear.y = 0;
				bebop_control->droneSpeed.linear.z = -1;
				bebop_control->droneSpeed.angular.x = bebop_control->droneSpeed.angular.y = bebop_control->droneSpeed.angular.z = 0;

				bebop_control->pub_[MOVE].publish(bebop_control->droneSpeed);
			} break;
			case 'a':			// drone is moving during pushing a key
			case 'A': {
				ROS_INFO("yaw_left");
				bebop_control->droneSpeed.linear.x = bebop_control->droneSpeed.linear.y = bebop_control->droneSpeed.linear.z = 0;
				bebop_control->droneSpeed.angular.x = bebop_control->droneSpeed.angular.y = 0;
				bebop_control->droneSpeed.angular.z = 1;

				bebop_control->pub_[MOVE].publish(bebop_control->droneSpeed);
			} break;
			case 'd':			// drone is moving during pushing a key
			case 'D': {
				ROS_INFO("yaw_right");
				bebop_control->droneSpeed.linear.x = bebop_control->droneSpeed.linear.y = bebop_control->droneSpeed.linear.z = 0;
				bebop_control->droneSpeed.angular.x = bebop_control->droneSpeed.angular.y = 0;
				bebop_control->droneSpeed.angular.z = -1;

				bebop_control->pub_[MOVE].publish(bebop_control->droneSpeed);
			} break;
		}
	}
}
