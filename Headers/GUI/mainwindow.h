#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QToolBar>
#include <QSplitter>

#include "search.h"

class MainWindow : public QMainWindow { 
    Q_OBJECT    
private:
    Search* searchWidget;
public: 
    MainWindow(QWidget* parent = nullptr);
};

#endif //MAINWINDOW_H
