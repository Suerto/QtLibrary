#include "../../Headers/JSON/jsonSelector.h"
#include "../../Headers/GUI/error.h"

JsonSelector::JsonSelector(QWidget* parent) : QWidget(parent), mainLayout(new QVBoxLayout(this)), buttonLayout(new QHBoxLayout()) {

    QPushButton* libro = new QPushButton("Carica Libri", this);
    buttonLayout->addWidget(libro);

    QPushButton* manga = new QPushButton("Carica Manga", this);
    buttonLayout->addWidget(manga);

    QPushButton* film = new QPushButton("Carica Film", this);
    buttonLayout->addWidget(film);

    QPushButton* anime = new QPushButton("Carica Anime", this);
    buttonLayout->addWidget(anime);

    mainLayout->addLayout(buttonLayout);
    
    QPushButton* start = new QPushButton("Avvia Applicazione", this);
    mainLayout->addWidget(start);
    setLayout(mainLayout);

    connect(start, &QPushButton::clicked, this, [this](){
        for(std::size_t i = 0; i < json.size(); ++i) {
            if(json[i].empty()) {
                ErrorNoFile error(this);
                error.exec();
                return;
            }
        }

        emit caricaContenuti(); 
    });


    connect(libro, &QPushButton::clicked, this, [this]() {
        QString absolutePath = QFileDialog::getOpenFileName(this, 
                "Selezionare il file per il caricamento dei libri", 
                "Data", "(*.json)");
    
        if (!absolutePath.isEmpty()) {
            QDir baseDir(QCoreApplication::applicationDirPath()); 
            string relativePath = baseDir.relativeFilePath(absolutePath).toStdString();

            json[0] = relativePath;
        }
    });


    connect(manga, &QPushButton::clicked, this, [this]() {
        QString absolutePath = QFileDialog::getOpenFileName(this, 
                "Selezionare il file per il caricamento dei manga", 
                "Data", "(*.json)");
    
        if (!absolutePath.isEmpty()) {
            QDir baseDir(QCoreApplication::applicationDirPath()); 
            string relativePath = baseDir.relativeFilePath(absolutePath).toStdString();
            json[1] = relativePath;
        }

        for(std::size_t i = 0; i < json.size(); ++i) qDebug() << QString::fromStdString(json[i]) << "\n";
    });


    connect(film, &QPushButton::clicked, this, [this]() {
        QString absolutePath = QFileDialog::getOpenFileName(this, 
                "Selezionare il file per il caricamento dei film", 
                "Data", "(*.json)");
    
        if (!absolutePath.isEmpty()) {
            QDir baseDir(QCoreApplication::applicationDirPath()); 
            string relativePath = baseDir.relativeFilePath(absolutePath).toStdString(); 
            
            json[2] = relativePath;
        }
    });


    connect(anime, &QPushButton::clicked, this, [this]() {
        QString absolutePath = QFileDialog::getOpenFileName(this, 
                "Selezionare il file per il caricamento degli anime", 
                "Data", "(*.json)");
    
        if (!absolutePath.isEmpty()) {
            QDir baseDir(QCoreApplication::applicationDirPath()); 
            string relativePath = baseDir.relativeFilePath(absolutePath).toStdString();
        
            json[3] = relativePath;
        }
    });
}

array<string, 4> JsonSelector::getFiles() const { return json; }
