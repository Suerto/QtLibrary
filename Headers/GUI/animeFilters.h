#ifndef ANIMEFILTERS_H
#define ANIMEFILTERS_H

#include <QWidget>
#include <QLineEdit>

#include "genericFilters.h"

class AnimeFilters : public Filters {
private:
    QLineEdit* composer;
public:
    AnimeFilters(QWidget* parent = nullptr);
    void reset();
};

#endif //ANIMEFILTERS_H
