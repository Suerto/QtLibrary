#include "../../Headers/GUI/filmFilters.h"

FilmFilters::FilmFilters(QWidget* parent) : Filters(parent), director(new QLineEdit(this)) {
    filtersLayout->addRow("Inserire nome regista : ", director);
    
}

void FilmFilters::reset() {
    Filters::reset();
    director->setText("");
}
