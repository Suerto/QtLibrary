#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QActionGroup>

#include "creation.h"
#include "research.h"
#include "errorChanging.h"

class MainWindow : public QMainWindow { 
    Q_OBJECT    
private:
    ContentManager* manager;

    QToolBar* toolBar;
    QStackedWidget* windows;
    QAction* searching;
    QAction* creation;
public: 
    MainWindow(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
private slots :
    void showSearching();
    void showCreation();
};

#endif //MAINWINDOW_H
