#ifndef MANGAFILTERS_H
#define MANGAFILTERS_H

#include <QWidget>
#include <QLineEdit>

#include "genericFilters.h"

class MangaFilters : public Filters {
private:
    QLineEdit* mangaka;
public: 
    MangaFilters(QWidget* parent = nullptr);
    void reset();
};

#endif //MANGAFILTERS_H
