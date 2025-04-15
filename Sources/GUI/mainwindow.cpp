#include "../../Headers/GUI/mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), toolBar(new QToolBar(this)), windows(new QStackedWidget(this)) {
    resize(1200, 800);
    
    toolBar = addToolBar("Strumenti");
    QPushButton* searching = new QPushButton("Ricerca", toolBar);
    toolBar->addWidget(searching);
    
    QPushButton* creation = new QPushButton("Creazione", toolBar);
    toolBar->addWidget(creation);

    windows->addWidget(new Search);
    windows->addWidget(new Creation);
     
    setCentralWidget(windows);
    windows->setVisible(false);

    connect(searching, &QPushButton::clicked, this, &MainWindow::showSearching);
    connect(creation, &QPushButton::clicked, this, &MainWindow::showAdvanced);
}

//Risolvere fattore di reset al variare del widget mostrato
void MainWindow::showSearching() {
   if(!windows->isVisible()) windows->setVisible(true);
    
   windows->setCurrentWidget(windows->widget(0));
}

void MainWindow::showAdvanced() {
    if(!windows->isVisible()) windows->setVisible(true);
    windows->setCurrentWidget(windows->widget(1));
}
