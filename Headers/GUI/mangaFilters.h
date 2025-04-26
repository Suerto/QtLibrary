#ifndef MANGAFILTERS_H
#define MANGAFILTERS_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>

#include "genericFilters.h"

class MangaFilters : public Filters {
private:
    QComboBox* cover;
    QComboBox* cadence;
    QLineEdit* mangaka;
    QLineEdit* editor;
    QSpinBox* pages;
    QSpinBox* chapters;
    QComboBox* genre;
public: 
    MangaFilters(QWidget* parent = nullptr);
    virtual void reset() override;
    virtual unordered_map<string, string> raccogliDati() const override;
};

#endif //MANGAFILTERS_H
