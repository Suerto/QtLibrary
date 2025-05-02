#include "../../Headers/GUI/animeFilters.h"

AnimeFilters::AnimeFilters(QWidget* parent) :Filters(parent), resolution(new QComboBox(this)), durata(new QSpinBox(this)), producer(new QLineEdit(this)), episodes(new QSpinBox(this)), seasons(new QSpinBox(this)), subtitled(new QCheckBox(this)), genre(new QComboBox(this)), cadence(new QComboBox(this)) {
   filtersLayout->addRow("Producer : ", producer);

   filtersLayout->addRow("Sottotitolato : ", subtitled);

   filtersLayout->addRow("Episodi : ", episodes);
    
   filtersLayout->addRow("Durata episodio : ", durata);
    
   JsonHandler::loadEnumFromJson("Data/Dati.json", "Cadenze", cadence);
   filtersLayout->addRow("Selezionare Cadenza di Pubblicazione : ", cadence);

   filtersLayout->addRow("Stagioni : ", seasons);

   JsonHandler::loadEnumFromJson("Data/Dati.json", "Risoluzioni", resolution);
   filtersLayout->addRow("Selezionare Risoluzione : ", resolution);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Anime", genre);
    filtersLayout->addRow("Selezionare Genere : ", genre);
    
    reset();
} 

unordered_map<string, string> AnimeFilters::raccogliDati() const {
    unordered_map<string, string> parametri;
    //Contenuto
    parametri.insert({"Anno", std::to_string(year->value())});
    (language->currentText().toStdString()).empty() ? parametri.insert({"Lingua", "Indefinita"}) : parametri.insert({"Lingua", language->currentText().toStdString()});
    
    //Digitale
    (resolution->currentText().toStdString()).empty() ? parametri.insert({"Risoluzione", "Indefinita"}) : parametri.insert({"Risoluzione", resolution->currentText().toStdString()});
    parametri.insert({"Durata", std::to_string(durata->value())});
    
    //Periodico
    (cadence->currentText().toStdString()).empty() ? parametri.insert({"Cadenza", "Indefinita"}) : parametri.insert({"Cadenza", cadence->currentText().toStdString()});

    //Anime
    parametri.insert({"Episodi", std::to_string(episodes->value())});
    parametri.insert({"Stagioni", std::to_string(seasons->value())});
    (producer->text().toStdString()).empty() ? parametri.insert({"Producer", "Indefinito"}) : parametri.insert({"Producer", producer->text().toStdString()});
    (genre->currentText().toStdString()).empty() ? parametri.insert({"Genere", "Indefinito"}) : parametri.insert({"Genere", genre->currentText().toStdString()});
    return parametri;
}

void AnimeFilters::reset() {
    Filters::reset();

    resolution->setCurrentIndex(-1);
    durata->setValue(0);

    cadence->setCurrentIndex(-1);
    
    producer->clear();
    subtitled->setChecked(false);
    episodes->setValue(0);
    seasons->setValue(0);
    genre->setCurrentIndex(-1);
}
