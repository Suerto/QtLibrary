#ifndef FILMFILTERS_H
#define FILMFILTERS_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

#include "genericFilters.h"

class FilmFilters : public Filters {
private:
    QComboBox* resolution;
    QSpinBox* durata;
    
    QLineEdit* director;
    QLineEdit* composer;
    QLineEdit* producer;
    QComboBox* genre;
public:
    FilmFilters(QWidget* parent = nullptr);
    virtual void reset() override;
    virtual unordered_map<string, string> raccogliDati() const override;
};

#endif //FILMFILTERS_H
