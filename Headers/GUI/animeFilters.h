#ifndef ANIMEFILTERS_H
#define ANIMEFILTERS_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>

#include "genericFilters.h"

class AnimeFilters : public Filters {
private:
    QComboBox* resolution;
    QSpinBox* durata;
 
    QLineEdit* producer;
    QSpinBox* episodes;
    QSpinBox* seasons;
    QCheckBox* subtitled;
    QComboBox* genre;
public:
    AnimeFilters(QWidget* parent = nullptr);
    void reset();
};

#endif //ANIMEFILTERS_H
