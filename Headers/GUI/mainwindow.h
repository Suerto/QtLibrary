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

#include "search.h"

class MainWindow : public QMainWindow { 
    Q_OBJECT    
private:
    QStackedWidget* windows;
    QToolBar* tools;
public: 
    MainWindow(QWidget* parent = nullptr);
//private:
    //QStackedWidget* windows;
};

#endif //MAINWINDOW_H


/*
 * Idea per la gestione delle finestre :
 *      In cima vi è una toolbar con i pulsanti di creazione e di ricerca e il 
 *      widget di ricerca è il primo widget che viene visualizzato. Se viene cliccato
 *      e si è già su quella schermata non succede nulla, altrimento cambia la
 *      schermata e farà così per tutti i pulsanti definiti nella toolBar
 * */
