#ifndef FILMFILTERS_H
#define FILMFILTERS_H

#include <QWidget>
#include <QLineEdit>

#include "genericFilters.h"

class FilmFilters : public Filters {
private:
    QLineEdit* director;
public:
    FilmFilters(QWidget* parent = nullptr);
    void reset();
};

#endif //FILMFILTERS_H
