#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QToolBar>
#include <QPushButton>

#include "search.h"
#include "creation.h"

class MainWindow : public QMainWindow { 
    Q_OBJECT    
private:
    QToolBar* toolBar;
    QStackedWidget* windows;
public: 
    MainWindow(QWidget* parent = nullptr);
private slots :
    void showSearching();
    void showCreation();
};

#endif //MAINWINDOW_H
