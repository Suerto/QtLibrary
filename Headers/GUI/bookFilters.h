#ifndef BOOKFILTERS_H
#define BOOKFILTERS_H

#include <QLineEdit>
#include <QWidget>
#include <QComboBox>

#include "genericFilters.h"

class BookFilters : public Filters {
private:
   QLineEdit* author;
   QComboBox* genre;
   QLineEdit* editor;
   QLineEdit* publisher;
public:
   BookFilters(QWidget* parent = nullptr);
   void reset();
};

#endif //BOOKFILTERS_H 

