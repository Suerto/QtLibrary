#include "../../Headers/GUI/mainWindow.h"

MainWindow::MainWindow(QWidget* parent, ContentManager* mngr) : QMainWindow(parent), toolBar(new QToolBar(this)), windows(new QStackedWidget(this)), searching(new QAction("Sezione Ricerca", this)), creation(new QAction("Sezione Creazione", this)), creationSection(new Creation(this, mngr)), researchSection(new Research(this, mngr)) {
    setMinimumSize(1200, 800);
    addToolBar(toolBar);
    toolBar->setMovable(false);
    
    toolBar->addAction(searching);
    searching->setCheckable(true);

    QWidget* spaziatoreSx = new QWidget(this);
    spaziatoreSx->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    toolBar->addWidget(spaziatoreSx);
    
    QLabel* title = new QLabel("Benvenuto in QtLibrary!", this);
    toolBar->addWidget(title);

    QWidget* spaziatoreDx = new QWidget(this);
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

    windows->insertWidget(0, researchSection);
    windows->insertWidget(1, creationSection);
    windows->setVisible(false);
    windows->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
     
    setCentralWidget(windows);
    
    connect(searching, &QAction::triggered, this, &MainWindow::showSearching);
    connect(creation, &QAction::triggered, this, &MainWindow::showCreation);

    //Design
    setStyleSheet(R"(
        QMainWindow {
            background-color : #426585;
        }

        QToolBar {
            background-color: #4D91C6;
            spacing: 6px;             
            padding: 4px;
            border: none;
        }
        
        QToolButton {
            color: #002FA7;             
            background-color: #E6E6FA;
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
            color : #002FA7;
            font-family : Century Gothic;
            font-weight : bold italic;
            font-size : 15px;
        }
        )"
    );

        QShortcut* escShortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this);
        connect(escShortcut, &QShortcut::activated, this, &MainWindow::closeApplication);
}

void MainWindow::showSearching() {
    if(!windows->isVisible()) 
        windows->setVisible(true);
    
    if(windows->currentIndex() == 1) {
        ErrorChanging change;
        connect(&change, &ErrorChanging::azione, this, [this](const QString& choice) {
            if(choice == "Conferma") {
               creationSection->ripristinaFiltri();
               windows->setCurrentIndex(0);
               searching->setChecked(true);
               creation->setChecked(false);
            }
            else {
                creation->setChecked(true);
                searching->setChecked(false);
            }
        });
        change.exec();
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

void MainWindow::closeApplication() {
    ErrorClosing error;
    connect(&error, &ErrorClosing::azione, this, [this](const QString& choice) {
            if(choice == "Conferma") {
                close();
            }
        });
    error.exec();
}
