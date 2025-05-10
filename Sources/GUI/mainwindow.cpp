#include "../../Headers/GUI/mainwindow.h"

MainWindow::MainWindow(QWidget* parent, ContentManager* mngr) : QMainWindow(parent), manager(mngr), toolBar(new QToolBar(this)), windows(new QStackedWidget(this)), searching(new QAction("Sezione Ricerca", this)), creation(new QAction("Sezione Creazione", this)) {
    setMinimumSize(1200, 800);
    toolBar = addToolBar("Strumenti");
    toolBar->setMovable(false);
    
    toolBar->addAction(searching);
    searching->setCheckable(true);

    QWidget* spaziatoreSx = new QWidget();
    spaziatoreSx->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spaziatoreSx);
    
    QLabel* title = new QLabel("Benvenuto in QtLibrary!");
    toolBar->addWidget(title);

    QWidget* spaziatoreDx = new QWidget();
    spaziatoreDx->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spaziatoreDx);

    toolBar->addAction(creation);
    creation->setCheckable(true);
    
    QActionGroup* sezioni = new QActionGroup(this);
    sezioni->addAction(searching);
    sezioni->addAction(creation);

    connect(searching, &QAction::toggled, [this](bool checked) {
        if (checked) {
            if (creation->isChecked()) {
                creation->setChecked(false);
            }
        }
    });

    connect(creation, &QAction::toggled, [this](bool checked) {
        if (checked) {
            if (searching->isChecked()) {
                searching->setChecked(false);
            }
        }
    });

    Research* ricerca = new Research(this, mngr);
    Creation* creazione = new Creation(this, mngr);

    windows->insertWidget(0, ricerca);
    windows->insertWidget(1, creazione);
    windows->setVisible(false);
    windows->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
     
    setCentralWidget(windows);
    
    connect(searching, &QAction::triggered, this, &MainWindow::showSearching);
    connect(creation, &QAction::triggered, this, &MainWindow::showCreation);

    //Design
    toolBar->setStyleSheet(R"(
        QToolBar {
            background-color: #F1E1B0;
            spacing: 6px;             
            padding: 4px;
            border: none;
        }
        
        QToolButton {
            color: white;             
            background-color: #DFCBAA;
            border: none;
            padding: 6px 12px;
            border-radius: 6px;
            font-family : Century Gothic;
            font-size : 12px;
            font-weight: normal;
        }
        
        QToolButton:hover {
            background-color: #F8ECD0;
        }

        QToolButton:pressed {
            background-color: #E2C48A;
        }
       
        QToolButton:checked {
            background-color: #D0A55A;
            font-weight: bold; 
        }
        
        QLabel {
            color : #C99A52;
            font-family : Century Gothic;
            font-weight : bold italic;
            font-size : 15px;
        }
        )"
    );
}

void MainWindow::showSearching() {
    if(!windows->isVisible()) 
        windows->setVisible(true);
    
    if(windows->currentIndex() == 1) {
        ErrorChanging* change = new ErrorChanging(this);
        connect(change, &ErrorChanging::azione, this, [this](const QString& choice) {
            if(choice == "Conferma") {
               qobject_cast<Creation*>(windows->currentWidget())->ripristinaFiltri();
               windows->setCurrentIndex(0);
               searching->setChecked(true);
               creation->setChecked(false);
            }
            else {
                creation->setChecked(true);
                searching->setChecked(false);
            }
        });
        change->exec();

    }
}

void MainWindow::showCreation() {
    if(!windows->isVisible()) 
        windows->setVisible(true);
    
    if(windows->currentIndex() != 1) {
        windows->setCurrentIndex(1);
        creation->setChecked(true);
        searching->setChecked(false);
    }
}
