#include "../../Headers/GUI/mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    resize(1200, 800);
    setMinimumSize(600, 400);
    
    Search* search = new Search(this);
    setCentralWidget(search);
}
