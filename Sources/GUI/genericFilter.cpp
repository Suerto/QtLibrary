#include "../../Headers/GUI/genericFilters.h"
#include "qglobal.h"
#include <string>

Filters::Filters(QWidget* parent) : QWidget(parent), pathImmagine(), language(new QComboBox(this)), year(new QSpinBox(this)), coverImage(new QPushButton("Cartella Immagini", this)), filtersLayout(new QFormLayout(this)) {
    pathImmagine = "Data/Immagini/default.jpg";
    filtersLayout->addRow("", coverImage);
    coverImage->setVisible(false);
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Lingue", language);
    filtersLayout->addRow("Lingua : ", language);
    
    year->setMinimum(0);
    year->setMaximum(2025);
    filtersLayout->addRow("Anno di Pubblicazione : ", year);
    
    setLayout(filtersLayout);

    reset();

    setStyleSheet(R"(    
        QComboBox { 
            background-color : #ABADAB;  
        }
        QSpinBox { 
            background-color : #ABADAB;  
        }
        QLineEdit { 
            background-color : #ABADAB;  
        }
    )");

    connect(coverImage, &QPushButton::clicked, this, [this]() {
        QString absolutePath = QFileDialog::getOpenFileName(this, "Seleziona immagine", "Data/Immagini", "Immagini (*.png *.jpg *.jpeg *.bmp)");
    
        if (!absolutePath.isEmpty()) {
            QDir baseDir(QCoreApplication::applicationDirPath()); // QtLibrary/
            QString relativePath = baseDir.relativeFilePath(absolutePath);
        
            qDebug() << "Percorso assoluto: " << absolutePath;
            qDebug() << "Percorso relativo: " << relativePath;
        
            pathImmagine = relativePath;
        }
    });
    
}

void Filters::reset() { 
    language->setCurrentIndex(-1);  
    year->setValue(0);
    pathImmagine = "Data/Immagini/default.jpg";
}

void Filters::setLanguage(const QString& lng) {
    language->setCurrentText(lng);
}

void Filters::setYear(const unsigned int& yr) {
    year->setValue(yr);
}

void Filters::setPathImage(const QString& path) {
    pathImmagine = path;
}

void Filters::setModifiable(const bool& mdf) {
        language->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        language->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        language->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");
        
        year->setReadOnly(!mdf);
        year->setButtonSymbols(mdf ? QAbstractSpinBox::UpDownArrows : 
                QAbstractSpinBox::NoButtons);
        year->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        year->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        year->setStyleSheet(!mdf ?
            "QSpinBox { border: none; background: transparent; }" : "");
        coverImage->setVisible(mdf);
}

QString Filters::getPathImage() const { return pathImmagine; }

void Filters::setAttributes(const std::unordered_map<string, string>& attributes) {
    setLanguage(QString::fromStdString(attributes.find("Lingua")->second));
    setYear(std::stoi(attributes.find("Anno")->second));
}

Filters::~Filters() = default;

void Filters::setImageButtonVisible(const bool& vsbl) { coverImage->setVisible(vsbl); }
