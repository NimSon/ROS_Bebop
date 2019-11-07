/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QTabWidget *tabWidget;
    QWidget *ManualMode;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_takeoff;
    QPushButton *pushButton_land;
    QPushButton *pushButton_emergency;
    QPushButton *pushButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_latitude;
    QListView *listView;
    QLabel *label_longitude;
    QListView *listView_3;
    QLabel *label_altitude;
    QListView *listView_2;
    QLabel *label_velocity;
    QListView *listView_4;
    QWidget *AutoMode;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(944, 704);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        ManualMode = new QWidget();
        ManualMode->setObjectName(QString::fromUtf8("ManualMode"));
        verticalLayoutWidget = new QWidget(ManualMode);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 10, 191, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_takeoff = new QPushButton(verticalLayoutWidget);
        pushButton_takeoff->setObjectName(QString::fromUtf8("pushButton_takeoff"));

        verticalLayout_2->addWidget(pushButton_takeoff);

        pushButton_land = new QPushButton(verticalLayoutWidget);
        pushButton_land->setObjectName(QString::fromUtf8("pushButton_land"));

        verticalLayout_2->addWidget(pushButton_land);

        pushButton_emergency = new QPushButton(verticalLayoutWidget);
        pushButton_emergency->setObjectName(QString::fromUtf8("pushButton_emergency"));

        verticalLayout_2->addWidget(pushButton_emergency);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        formLayoutWidget = new QWidget(ManualMode);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(250, 10, 391, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_latitude = new QLabel(formLayoutWidget);
        label_latitude->setObjectName(QString::fromUtf8("label_latitude"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_latitude);

        listView = new QListView(formLayoutWidget);
        listView->setObjectName(QString::fromUtf8("listView"));

        formLayout->setWidget(0, QFormLayout::FieldRole, listView);

        label_longitude = new QLabel(formLayoutWidget);
        label_longitude->setObjectName(QString::fromUtf8("label_longitude"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_longitude);

        listView_3 = new QListView(formLayoutWidget);
        listView_3->setObjectName(QString::fromUtf8("listView_3"));

        formLayout->setWidget(1, QFormLayout::FieldRole, listView_3);

        label_altitude = new QLabel(formLayoutWidget);
        label_altitude->setObjectName(QString::fromUtf8("label_altitude"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_altitude);

        listView_2 = new QListView(formLayoutWidget);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, listView_2);

        label_velocity = new QLabel(formLayoutWidget);
        label_velocity->setObjectName(QString::fromUtf8("label_velocity"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_velocity);

        listView_4 = new QListView(formLayoutWidget);
        listView_4->setObjectName(QString::fromUtf8("listView_4"));

        formLayout->setWidget(3, QFormLayout::FieldRole, listView_4);

        tabWidget->addTab(ManualMode, QString());
        AutoMode = new QWidget();
        AutoMode->setObjectName(QString::fromUtf8("AutoMode"));
        tabWidget->addTab(AutoMode, QString());

        hboxLayout->addWidget(tabWidget);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 944, 22));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        pushButton_takeoff->setText(QApplication::translate("MainWindowDesign", "TAKE OFF", 0, QApplication::UnicodeUTF8));
        pushButton_land->setText(QApplication::translate("MainWindowDesign", "LAND", 0, QApplication::UnicodeUTF8));
        pushButton_emergency->setText(QApplication::translate("MainWindowDesign", "EMERGENCY", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindowDesign", "QUIT", 0, QApplication::UnicodeUTF8));
        label_latitude->setText(QApplication::translate("MainWindowDesign", "LATITUDE", 0, QApplication::UnicodeUTF8));
        label_longitude->setText(QApplication::translate("MainWindowDesign", "LONGITUDE", 0, QApplication::UnicodeUTF8));
        label_altitude->setText(QApplication::translate("MainWindowDesign", "ALTITUDE", 0, QApplication::UnicodeUTF8));
        label_velocity->setText(QApplication::translate("MainWindowDesign", "VELOCITY", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(ManualMode), QApplication::translate("MainWindowDesign", "Manual", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(AutoMode), QApplication::translate("MainWindowDesign", "Tab 2", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
