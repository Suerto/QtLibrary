#ifndef GENERIC_H
#define GENERIC_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QFormLayout>
#include <QVariantMap>

#include "../../Sources/JSON/JsonHandler.hpp"


class Filters : public QWidget {
    Q_OBJECT
protected:
    QComboBox* language;
    QSpinBox* year;
    QFormLayout* filtersLayout;
public:
    Filters(QWidget* parent = nullptr);
    virtual void reset();
    virtual QVariantMap raccogliDati() const = 0;
};

#endif //GENERIC_H
