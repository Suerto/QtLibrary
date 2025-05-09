#include "../../Headers/GUI/bookFilters.h"
#include <string>

BookFilters::BookFilters(QWidget* parent) : Filters(parent), cover(new QComboBox(this)), pages(new QSpinBox(this)), author(new QLineEdit(this)), editor(new QLineEdit(this)), publisher(new QLineEdit(this)), genre(new QComboBox(this)) { 
    filtersLayout->addRow("Autore : ", author);
    
    filtersLayout->addRow("Editore : ", editor);
 
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Libri", genre);
    filtersLayout->addRow("Selezionare Genere : ", genre);

    pages->setMinimum(0);
    pages->setMaximum(10000);
    filtersLayout->addRow("Numero di Pagine : ", pages);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Copertine", cover);
    filtersLayout->addRow("Selezionare Copertina : ", cover);

    filtersLayout->addRow("Publisher : ", publisher);

    reset();

    //setStyleSheet("border: 2px solid black; ");

    cover->currentText();
}

unordered_map<string, string> BookFilters::raccogliDati() const {
    unordered_map<string, string> parametri;
    
    //Contenuto
    parametri.insert({"Anno", std::to_string(year->value())});
    (language->currentText().toStdString()).empty() ? parametri.insert({"Lingua", "Indefinita"}) : parametri.insert({"Lingua", language->currentText().toStdString()});
    
    //Fisico
    (cover->currentText().toStdString()).empty() ? parametri.insert({"Copertina", "Indefinita"}) : parametri.insert({"Copertina", cover->currentText().toStdString()});
    parametri.insert({"Pagine", std::to_string(pages->value())});
    
    //Libro
    (author->text().toStdString()).empty() ? parametri.insert({"Autore", "Indefinito"}) : parametri.insert({"Autore", author->text().toStdString()});
    (editor->text().toStdString()).empty() ? parametri.insert({"Editore", "Indefinito"}) :parametri.insert({"Editore", editor->text().toStdString()});
    (publisher->text().toStdString()).empty() ? parametri.insert({"Publisher", "Indefinito"}) : parametri.insert({"Publisher", publisher->text().toStdString()});
    (genre->currentText().toStdString()).empty() ? parametri.insert({"Genere", "Indefinito"}) : parametri.insert({"Genere", genre->currentText().toStdString()});

    return parametri;
}

void BookFilters::reset() {
   Filters::reset();
    
   author->clear();
   editor->clear();
   genre->setCurrentIndex(-1);
   pages->clear();
   cover->setCurrentIndex(-1);
   publisher->clear();
}

void BookFilters::setCover(const QString& cvr) {
    cover->setCurrentText(cvr);
}

void BookFilters::setPages(const unsigned int& pgs) {
    pages->setValue(pgs);
}

void BookFilters::setAuthor(const QString& athr) {
    author->setText(athr);
}

void BookFilters::setEditor(const QString& edtr) {
    editor->setText(edtr);
}

void BookFilters::setPublisher(const QString& pshr) {
    publisher->setText(pshr);
}

void BookFilters::setGenre(const QString& gnr) {
    genre->setCurrentText(gnr);
}
