#include "../../Headers/GUI/bookFilters.h"

BookFilters::BookFilters(QWidget* parent) : Filters(parent) {
    //author->setPlaceholderText("Inserire nome dell'autore ");
    author = new QLineEdit(this);
    filtersLayout->addRow("Inserire Autore : ", author);
    //editor->setPlaceholderText("Inserire editore del libro ");
    editor = new QLineEdit(this);
    filtersLayout->addRow("Inserire Editore : ", editor);

    publisher = new QLineEdit(this);
    filtersLayout->addRow("Inserire nome del Publisher : ", publisher);
    
    genre = new QComboBox(this);
    JsonHandler::loadEnumFromJson(genre, "copertine.json", "Copertine");
    filtersLayout->addRow("Selezionare un genere : ", genre);
}

//gestita l'aggiunta delle possibili copertine che un libro può avere, occuparsi della rimozione del filtro selezionato per il refresh della pagina
void BookFilters::reset() {
    Filters::reset(); //pensare ad una alternativa più performante
    author->clear();
    editor->clear();
    publisher->clear();
    genre->setCurrentIndex(0);
}


