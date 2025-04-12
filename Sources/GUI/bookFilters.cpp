#include "../../Headers/GUI/bookFilters.h"

BookFilters::BookFilters(QWidget* parent) : Filters(parent), cover(new QComboBox(this)), pages(new QSpinBox(this)), author(new QLineEdit(this)), editor(new QLineEdit(this)), publisher(new QLineEdit(this)), genre(new QComboBox(this)) {
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Copertine", cover);
    
    filtersLayout->addRow("Selezionare tipo di copertina : ", cover);

    filtersLayout->addRow("Indicare numero di pagine : ", pages);
    
    filtersLayout->addRow("Inserire Autore : ", author);
    
    filtersLayout->addRow("Inserire Editore : ", editor);
    
    filtersLayout->addRow("Inserire nome del Publisher : ", publisher);
      
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Libri", genre);
    
    filtersLayout->addRow("Selezionare un genere : ", genre);
}

//gestita l'aggiunta delle possibili copertine che un libro può avere, occuparsi della rimozione del filtro selezionato per il refresh della pagina
void BookFilters::reset() {
    Filters::reset(); //pensare ad una alternativa più performante
    
    cover->setCurrentIndex(-1);

    author->clear();
    
    editor->clear();
    
    publisher->clear();
    
    genre->setCurrentIndex(-1);
}


