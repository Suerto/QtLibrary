#ifndef APP_H
#define APP_H

#include <QApplication>

#include "mainWindow.h"
#include "../JSON/jsonSelector.h"

class App : public QApplication {
private:
    MainWindow* main;
    ContentManager* manager;
    JsonSelector* json;

    bool started;
public: 
    App(int& argc, char** argv, ContentManager* mngr);
    ~App();
};

#endif //APP_H
