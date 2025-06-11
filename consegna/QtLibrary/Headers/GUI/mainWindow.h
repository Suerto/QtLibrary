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
    QToolBar* toolBar;
    QStackedWidget* windows;
    QAction* searching;
    QAction* creation;
    Creation* creationSection;
    Research* researchSection;
public: 
    MainWindow(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
private slots :
    void showSearching();
    void showCreation();
    void closeApplication();
    
};

#endif //MAINWINDOW_H
