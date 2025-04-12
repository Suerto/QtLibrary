#include "../../Headers/GUI/mangaFilters.h"

MangaFilters::MangaFilters(QWidget* parent) : Filters(parent), cover(new QComboBox(this)), cadence(new QComboBox(this)), mangaka(new QLineEdit(this)), editor(new QLineEdit(this)), pages(new QSpinBox(this)), chapters(new QSpinBox(this)), genre(new QComboBox(this)) {
   
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Copertine", cover);

    filtersLayout->addRow("Indicare tipologia di copertina : ", cover);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Cadenze", cadence);

    filtersLayout->addRow("Indicare cadenza di pubblicazione : ", cadence);
    
    filtersLayout->addRow("Scrivere nome del Mangaka : ", mangaka);

    filtersLayout->addRow("Indicare nome dell'Editore :", editor);

    filtersLayout->addRow("Indicare numero di pagine : ", pages);

    filtersLayout->addRow("Indicare numero di capitoli ", chapters);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Manga", genre);

    filtersLayout->addRow("Indicare genere : ", genre);

}

void MangaFilters::reset() {
    Filters::reset();
    mangaka->setText("");
}
