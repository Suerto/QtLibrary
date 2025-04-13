#ifndef GENERIC_H
#define GENERIC_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QFormLayout>

#include "../../Sources/JSON/JsonHandler.hpp"

class Filters : public QWidget {
    Q_OBJECT
private:
    QComboBox* language;
    QSpinBox* year;
protected:
    Filters(QWidget* parent = nullptr);
    QFormLayout* filtersLayout;
public:
    virtual void reset();
};

#endif //GENERIC_H
