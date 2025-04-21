#include "../../Headers/GUI/mangaFilters.h"

MangaFilters::MangaFilters(QWidget* parent) : Filters(parent), cover(new QComboBox(this)), cadence(new QComboBox(this)), mangaka(new QLineEdit(this)), editor(new QLineEdit(this)), pages(new QSpinBox(this)), chapters(new QSpinBox(this)), genre(new QComboBox(this)) {
    filtersLayout->addRow("Mangaka : ", mangaka);

    filtersLayout->addRow("Editore : ", editor);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Manga", genre);
    filtersLayout->addRow("Selezionare Genere : ", genre);

    filtersLayout->addRow("Numero di Pagine : ", pages);

    filtersLayout->addRow("Numero di Capitoli : ", chapters);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Cadenze", cadence);
    filtersLayout->addRow("Selezionare Cadenza di Pubblicazione : ", cadence);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Copertine", cover);
    filtersLayout->addRow("Selezionare Copertina : ", cover);

    reset();
}

void MangaFilters::reset() {
    Filters::reset();
    
    mangaka->clear();

    editor->clear();

    genre->setCurrentIndex(-1);

    pages->clear();

    chapters->clear();

    cadence->setCurrentIndex(-1);

    cover->setCurrentIndex(-1);
}
