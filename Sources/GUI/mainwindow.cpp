#include "../../Headers/GUI/mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), searchWidget(new Search()){
    resize(1200, 800);

    searchWidget->setFixedSize(width() / 2, height());
    setCentralWidget(searchWidget);
}
