/***************************************
** #include
***************************************/
#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <std_msgs/Empty.h>
#include "../include/bebop_gui/main_window.hpp"


/***************************************
** MainWindow Constructor and Destructor
***************************************/
// MainWindow Constructor
MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
:QMainWindow(parent), qnode(argc, argv){  // QMainWindow는 자체적으로 layout을 가지고 있다. central widget을 반드시 필요로 한다.

  ui.setupUi(this); // setupUi() : UI를 위젯이나 다이얼로그 등에 적용시켜주는 함수
  QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));
  // connect(signal 발생 위치, signal, slot 발생 위치, slot);
  // signal : click etc, slot : function
  // qApp is a global variable for the application,

  //ReadSetting();
  //setWindowIcon(QIcon(":/images/icon.png"));
  //ui.tab_manager->setCurrentIndex(0);

  QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
  // &qnode에서 rosShutdown() signal을 받으면，&MainWindow에서 SLOT(close) 함수 실행
}

// MainWindow Destructor
MainWindow::~MainWindow(){

}

void MainWindow::on_pushButton_takeoff_clicked(){
  if(qnode.init() ){
    std_msgs::Empty takeoff;
    qnode.pub_[TAKEOFF].publish(takeoff);
    ROS_INFO("take off");
  }
}

void MainWindow::on_pushButton_land_clicked(){
  if(qnode.init() ){
    std_msgs::Empty land;
    qnode.pub_[LAND].publish(land);
    ROS_INFO("land");
  }
}

void MainWindow::on_pushButton_emergency_clicked(){
  if(qnode.init() ){
    std_msgs::Empty emergency;
    qnode.pub_[EMERGENCY].publish(emergency);
    ROS_INFO("emergency");
  }
}
