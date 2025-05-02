#include "../../Headers/GUI/mangaFilters.h"
#include <string>

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

unordered_map<string, string> MangaFilters::raccogliDati() const {   
    unordered_map<string, string> parametri;

    parametri.insert({"Anno", std::to_string(year->value())});
    (language->currentText().toStdString()).empty() ? parametri.insert({"Lingua", "Indefinita"}) : parametri.insert({"Lingua", language->currentText().toStdString()});
    
    //Fisico
    (cover->currentText().toStdString()).empty() ? parametri.insert({"Copertina", "Indefinita"}) : parametri.insert({"Copertina", cover->currentText().toStdString()});
    parametri.insert({"Pagine", std::to_string(pages->value())});
    
    //Periodico
    (cadence->currentText().toStdString()).empty() ? parametri.insert({"Cadenza", "Indefinita"}) : parametri.insert({"Cadenza", language->currentText().toStdString()});

    //Manga
    (editor->text().toStdString()).empty() ? parametri.insert({"Editore", "Indefinito"}) :parametri.insert({"Editore", editor->text().toStdString()});
    (mangaka->text().toStdString()).empty() ? parametri.insert({"Mangaka", "Indefinito"}) : parametri.insert({"Mangaka", mangaka->text().toStdString()});
    (genre->currentText().toStdString()).empty() ? parametri.insert({"Genere", "Indefinito"}) : parametri.insert({"Genere", genre->currentText().toStdString()});

    return parametri;
}

void MangaFilters::reset() {
    Filters::reset();
    
    cover->setCurrentIndex(-1);
    pages->setValue(0);

    cadence->setCurrentIndex(-1);

    mangaka->clear();
    editor->clear();
    genre->setCurrentIndex(-1);
    chapters->clear();
}
