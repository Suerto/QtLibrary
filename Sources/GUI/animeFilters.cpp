#include "../../Headers/GUI/animeFilters.h"

AnimeFilters::AnimeFilters(QWidget* parent) :Filters(parent), resolution(new QComboBox(this)), durata(new QSpinBox(this)), producer(new QLineEdit(this)), episodes(new QSpinBox(this)), seasons(new QSpinBox(this)), subtitled(new QCheckBox(this)) {} 

    //Da ultimare
