#ifndef BOOKFILTERS_H
#define BOOKFILTERS_H

#include <QLineEdit>
#include <QWidget>
#include <QComboBox>

#include "genericFilters.h"

class BookFilters : public Filters {
private:
   QComboBox* cover;
   QSpinBox* pages;

   QLineEdit* author;
   QLineEdit* editor;
   QLineEdit* publisher;
   QComboBox* genre;
public:
   BookFilters(QWidget* parent = nullptr);
   virtual void reset() override;
   virtual unordered_map<string, string> raccogliDati() const override;
};

#endif //BOOKFILTERS_H 

