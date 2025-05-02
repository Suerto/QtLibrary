#include "../../Headers/GUI/filmFilters.h"

FilmFilters::FilmFilters(QWidget* parent) : Filters(parent), resolution(new QComboBox(this)), durata(new QSpinBox(this)), director(new QLineEdit(this)), composer(new QLineEdit(this)), producer(new QLineEdit(this)), genre(new QComboBox(this)) {
    filtersLayout->addRow("Regista : ", director);

    filtersLayout->addRow("Compositore Musicale : ", composer);

    filtersLayout->addRow("Produttore : ", producer);

    filtersLayout->addRow("Durata : ", durata);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Film", genre);
    filtersLayout->addRow("Selezionare Genere : ", genre);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Risoluzioni", resolution);
    filtersLayout->addRow("Selezionare Risoluzione : ", resolution);

    reset();
}

unordered_map<string, string> FilmFilters::raccogliDati() const {
    unordered_map<string, string> parametri;

    //Contenuto
    parametri.insert({"Anno", std::to_string(year->value())});
    (language->currentText().toStdString()).empty() ? parametri.insert({"Lingua", "Indefinita"}) : parametri.insert({"Lingua", language->currentText().toStdString()});
    
    //Digitale
    (resolution->currentText().toStdString()).empty() ? parametri.insert({"Risoluzione", "Indefinita"}) : parametri.insert({"Risoluzione", resolution->currentText().toStdString()});
    parametri.insert({"Durata", std::to_string(durata->value())});
    
    //Film
    (director->text().toStdString()).empty() ? parametri.insert({"Regista", "Indefinito"}) : parametri.insert({"Regista", director->text().toStdString()});
    (composer->text().toStdString()).empty() ? parametri.insert({"Compositore", "Indefinito"}) :parametri.insert({"Compositore", composer->text().toStdString()});
    (producer->text().toStdString()).empty() ? parametri.insert({"Producer", "Indefinito"}) : parametri.insert({"Producer", producer->text().toStdString()});
    (genre->currentText().toStdString()).empty() ? parametri.insert({"Genere", "Indefinito"}) : parametri.insert({"Genere", genre->currentText().toStdString()});
    return parametri;
}

void FilmFilters::reset() {
    Filters::reset();
    
    resolution->setCurrentIndex(-1);
    durata->setValue(0);

    director->clear();
    composer->clear();
    producer->clear();
    genre->setCurrentIndex(-1);
}
