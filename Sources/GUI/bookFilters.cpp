#include "../../Headers/GUI/bookFilters.h"
#include <string>

BookFilters::BookFilters(QWidget* parent) : Filters(parent), cover(new QComboBox(this)), pages(new QSpinBox(this)), author(new QLineEdit(this)), editor(new QLineEdit(this)), publisher(new QLineEdit(this)), genre(new QComboBox(this)) {
    filtersLayout->addRow("Autore : ", author);
    
    filtersLayout->addRow("Editore : ", editor);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Libri", genre);
    filtersLayout->addRow("Selezionare Genere : ", genre);

    filtersLayout->addRow("Numero di Pagine : ", pages);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Copertine", cover);
    filtersLayout->addRow("Selezionare Copertina : ", cover);

    filtersLayout->addRow("Publisher : ", publisher);

    reset();
}

unordered_map<string, string> BookFilters::raccogliDati() const {
    unordered_map<string, string> parametri = {
        {"Anno", std::to_string(year->value())},
        {"Lingua", language->currentText().toStdString()},

        {"Copertina", cover->currentText().toStdString()},
        {"Pagine", std::to_string(pages->value())},

        {"Autore", author->text().toStdString()},
        {"Editore", editor->text().toStdString()},
        {"Publisher", publisher->text().toStdString()},
        {"Genere", genre->currentText().toStdString()}
    };
    return parametri;
}

void BookFilters::reset() {
    Filters::reset();
    
    cover->setCurrentIndex(-1);
    author->clear();
    editor->clear();
    publisher->clear();
    genre->setCurrentIndex(-1);
}
