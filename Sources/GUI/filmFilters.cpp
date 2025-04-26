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
    unordered_map<string, string> parametri = {
        {"Anno", std::to_string(year->value())},
        {"Lingua", language->currentText().toStdString()},

        {"Risoluzione", resolution->currentText().toStdString()},
        {"Durata", std::to_string(durata->value())},

        {"Regista", director->text().toStdString()},
        {"Composer", composer->text().toStdString()},
        {"Producer", producer->text().toStdString()},
        {"Genere", genre->currentText().toStdString()}
    };
    return parametri;
}

void FilmFilters::reset() {
    Filters::reset();

    director->clear();
    composer->clear();
    producer->clear();
    durata->clear();
    genre->setCurrentIndex(-1);
    resolution->setCurrentIndex(-1);
}
