#ifndef BEBOPGUI_QNODE_H
#define BEBOPGUI_QNODE_H


/***************************************
** #include
***************************************/
#ifndef Q_MOC_RUN // if not, BOOST_JOIN error
#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#endif

#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>


/***************************************
** #define
***************************************/
#define TAKEOFF 0
#define LAND 1
#define EMERGENCY 2
#define MOVE 3


//namespace bebop_gui{


/***************************************
** QNode Class(파생클래스)
***************************************/
class QNode : public QThread{ // 파생클래스, 부모클래스: QThread
  Q_OBJECT  // macro
private:
  int init_argc;
  char** init_argv;

  // ros subscriber
  ros::Subscriber subscribeGPS;
  ros::Subscriber subscribeRotation;

  bebop_msgs::Ardrone3PilotingStatePositionChanged droneGPSData;
  bebop_msgs::Ardrone3PilotingStateAttitudeChanged droneRotationData;

public:
  QNode(int argc, char** argv);
  virtual ~QNode(); // 클래스는 가상 소멸자를 가질 수 있지만 가상 생성자는 가질 수 없다.

  // ros initialze
  bool init();
  bool init(const std::string &master_url, const std::string &host_url);

  // ros publisher
  ros::Publisher pub_[4];
  void readyToPublish(ros::NodeHandle&);

  // ros subscriber
  void subscribers(ros::NodeHandle&);

  //ros callback functions
  void subGPSData(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr&);
  void subRotationData(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr&);

  // ros work
  void run();

Q_SIGNALS:  // QNode macro
  void rosShutdown();
};

//} //namespace bebop_gui

#endif
