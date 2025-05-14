#ifndef GENERIC_H
#define GENERIC_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QFormLayout>
#include <unordered_map>

#include "guiVisitor.h"

#include "../../Sources/JSON/JsonHandler.hpp"

using std::unordered_map;

class Filters : public QWidget {
    Q_OBJECT
protected:
    QComboBox* language;
    QSpinBox* year;
    QFormLayout* filtersLayout;
public:
    Filters(QWidget* parent = nullptr);
    void setLanguage(const QString& lng);
    void setYear(const unsigned int& yr);
    
    virtual void reset();
    virtual void setModifiable(const bool& mdf);
    virtual void setAttributes(const unordered_map<string, string>& attributes);

    virtual unordered_map<string, string> raccogliDati() const = 0;
    virtual void accept(GuiVisitor* visitor) const = 0;
};

#endif //GENERIC_H
