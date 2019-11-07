/***************************************
** #include
***************************************/
#include <QtGui>
#include <QApplication>
#include "../include/bebop_gui/main_window.hpp"

int main(int argc, char** argv){
  /***************************************
  ** QT
  ***************************************/
  QApplication app(argc, argv); // QWidget(QMainWindow) Must construct a QApplication

  MainWindow w(argc, argv);
  w.show(); // ui open

  app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
  int result = app.exec();

  return result;
}
