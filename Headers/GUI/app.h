#ifndef APP_H
#define APP_H

#include <QApplication>

#include "mainwindow.h"

class App : public QApplication {
private:
    ContentManager* manager;
    MainWindow* main;
public: 
    App(int& argc, char** argv, ContentManager* mngr);
};

#endif //APP_H
