#include "../../Headers/GUI/mainwindow.h"

MainWindow::MainWindow(QWidget* parent, ContentManager* mngr) : QMainWindow(parent), manager(mngr), toolBar(new QToolBar(this)), windows(new QStackedWidget(this)) {
    resize(1200, 800);
    toolBar = addToolBar("Strumenti");
    toolBar->setMovable(false);
    
    QAction* searching = new QAction("Ricerca", toolBar);
    toolBar->addAction(searching);
    
    QAction* creation = new QAction("Creazione", toolBar);
    toolBar->addAction(creation);
    
    Search* ricerca = new Search(this, mngr);
    Creation* creazione = new Creation(this, mngr);
    windows->insertWidget(0, ricerca);
    windows->insertWidget(1, creazione);
     
    setCentralWidget(windows);
    windows->setVisible(false);
    
    connect(searching, &QAction::triggered, this, &MainWindow::showSearching);
    connect(creation, &QAction::triggered, this, &MainWindow::showCreation);

    //Design
    toolBar->setStyleSheet("background-color : #2E8B57; text->color : #FFFFFF;");
    setStyleSheet("background-color: #2E8B57"); 
}

void MainWindow::showSearching() {
    if(!windows->isVisible()) windows->setVisible(true);
    
    if(windows->currentIndex() == 1) {
        ErrorChanging* change = new ErrorChanging(this);
        connect(change, &ErrorChanging::azione, this, [this](const QString& choice) {
            if(choice == "Conferma") {
               qDebug() << "";
               qobject_cast<Creation*>(windows->currentWidget())->ripristinaFiltri();
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
