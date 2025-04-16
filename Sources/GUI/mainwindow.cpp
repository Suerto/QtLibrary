#include "../../Headers/GUI/mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), toolBar(new QToolBar(this)), windows(new QStackedWidget(this)) {
    resize(1200, 800);
    
    toolBar = addToolBar("Strumenti");
    toolBar->setMovable(false);
    
    QAction* searching = new QAction("Ricerca", toolBar);

    toolBar->addAction(searching);
    
    QAction* creation = new QAction("Creazione", toolBar);
    toolBar->addAction(creation);

    windows->addWidget(new Search);
    windows->addWidget(new Creation);
     
    setCentralWidget(windows);
    windows->setVisible(false);

    connect(searching, &QAction::triggered, this, &MainWindow::showSearching);
    connect(creation, &QAction::triggered, this, &MainWindow::showCreation);

    //Design
    //setStyleSheet("background-color : #003fd4");
}

//Risolvere fattore di reset al variare del widget mostrato
void MainWindow::showSearching() {
   if(!windows->isVisible()) windows->setVisible(true);    
   windows->setCurrentWidget(windows->widget(0));

   windows->setFixedSize(470, 800);
}

void MainWindow::showCreation() {
    if(!windows->isVisible()) windows->setVisible(true);
    
    windows->setCurrentWidget(windows->widget(1));
}
