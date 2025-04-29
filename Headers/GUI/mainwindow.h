#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>

#include "creation.h"
#include "search.h"
#include "errorDialog.h"

class MainWindow : public QMainWindow { 
    Q_OBJECT    
private:
    ContentManager* manager;

    QToolBar* toolBar;
    QStackedWidget* windows;
public: 
    MainWindow(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
private slots :
    void showSearching();
    void showCreation();
};

#endif //MAINWINDOW_H
