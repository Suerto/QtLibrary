#include "../../Headers/GUI/animeFilters.h"

AnimeFilters::AnimeFilters(QWidget* parent) : Filters(parent), composer(new QLineEdit(this)) {
    filtersLayout->addRow("Indicare Composer : ", composer);
}

void AnimeFilters::reset() {
    Filters::reset();
    composer->setText("");
}
