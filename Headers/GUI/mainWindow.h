#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QActionGroup>
#include <QShortcut>

#include "error.h"
#include "creation.h"
#include "research.h"

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

    ~MainWindow();
private slots :
    void showSearching();
    void showCreation();
    void closeApplication();
    
};

#endif //MAINWINDOW_H
