#ifndef APP_H
#define APP_H

#include <QApplication>

#include "mainWindow.h"

class App : public QApplication {
private:
    MainWindow* main;
public: 
    App(int& argc, char** argv, ContentManager* mngr);
    ~App();
};

#endif //APP_H
