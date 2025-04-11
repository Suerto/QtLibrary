#ifndef APP_H
#define APP_H

#include <QApplication>

class App : public QApplication {
public: 
    App(int& argc, char* argv[]);
};

#endif //APP_H
