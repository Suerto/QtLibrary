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
} 

void AnimeFilters::reset() {
    Filters::reset();

    producer->clear();

    subtitled->setChecked(false);

    episodes->clear();

    seasons->clear();

    durata->clear();

    genre->setCurrentIndex(-1);

    resolution->setCurrentIndex(-1);
}
