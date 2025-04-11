#include "../../Headers/GUI/mangaFilters.h"

MangaFilters::MangaFilters(QWidget* parent) : Filters(parent), mangaka(new QLineEdit(this)) {
    filtersLayout->addRow("Scrivere nome del Mangaka : ", mangaka);
}

void MangaFilters::reset() {
    Filters::reset();
    mangaka->setText("");
}
