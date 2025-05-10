#ifndef GENERIC_H
#define GENERIC_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QFormLayout>
#include <unordered_map>

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
    virtual void reset();
    virtual unordered_map<string, string> raccogliDati() const = 0;
    
    virtual void setAttributes(const unordered_map<string, string>& attributes);
    void setLanguage(const QString& lng);
    void setYear(const unsigned int& yr);
    virtual void setModifiable(const bool& mdf);
};

#endif //GENERIC_H
