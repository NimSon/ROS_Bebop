#ifndef BEBOPGUI_MAINWINDOW_H
#define BEBOPGUI_MAINWINDOW_H


/***************************************
** #include
***************************************/
#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"


/***************************************
** MainWindow Class(파생클래스)
***************************************/
class MainWindow : public QMainWindow{  // 파생클래스, 부모클래스: QMainWindow
  Q_OBJECT  // macro. for use signals and slots
private:
  Ui::MainWindowDesign ui;
  QNode qnode;

public:
  MainWindow(int argc, char** argv, QWidget *parent = 0);
  ~MainWindow();

public Q_SLOTS:
  void on_pushButton_takeoff_clicked();
  void on_pushButton_land_clicked();
  void on_pushButton_emergency_clicked();
};

#endif
