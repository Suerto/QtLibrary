#include "../../Headers/GUI/mainwindow.h"

MainWindow::MainWindow(QWidget* parent, ContentManager* mngr) : QMainWindow(parent), manager(mngr), toolBar(new QToolBar(this)), windows(new QStackedWidget(this)) {
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
    toolBar->setStyleSheet("background-color : #808080; text->color : #FFFFFF;");
    
}

void MainWindow::showSearching() {
    if(!windows->isVisible()) windows->setVisible(true);
    
    if(windows->currentIndex() == 1) {
        ErrorDialog* change = new ErrorDialog(this);
        connect(change, &ErrorDialog::azione, this, [this](const QString& choice) {
            if(choice == "Conferma") {
               qobject_cast<Creation*>(windows->currentWidget())->resetCreation();
               windows->setCurrentIndex(0); 
            }
        });

        change->exec();
    }

    windows->setFixedSize(500, this->height());
}

void MainWindow::showCreation() {
    if(!windows->isVisible()) windows->setVisible(true);
    
    if(windows->currentIndex() != 1) windows->setCurrentIndex(1); 
}
