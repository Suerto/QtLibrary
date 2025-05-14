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

   void setCover(const QString& cvr);
   void setPages(const unsigned int& pgs);

   void setAuthor(const QString& athr);
   void setEditor(const QString& edtr);
   void setPublisher(const QString& pshr);
   void setGenre(const QString& gnr);

   virtual void setModifiable(const bool& mdf) override;
   virtual void setAttributes(const unordered_map<string, string>& map) override;
   virtual void accept(GuiVisitor* visitor) const override;
};

#endif //BOOKFILTERS_H 

