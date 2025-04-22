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

QVariantMap FilmFilters::raccogliDati() const {
    QVariantMap parametri;

    parametri["lingua"] = language->currentText();
    parametri["anno"] = year->value();
    parametri["regista"] = director->text();
    parametri["compositore"] = composer->text();
    parametri["produttore"] = producer->text();
    parametri["durata"] = durata->value();
    parametri["genere"] = genre->currentText();
    parametri["risoluzione"] = resolution->currentText();
    
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
