#ifndef ERROR_CHANGING_H
#define ERROR_CHANGING_H

#include <QButtonGroup>

#include "errorStructure.h"

class ErrorChanging : public ErrorStructure {
    Q_OBJECT
private:
    QButtonGroup* action;
public:
    ErrorChanging(QWidget* parent = nullptr);
public slots:
    void changeWidget(int id);
signals:
    void azione(const QString& choice);
};

#endif //ERROR_CHANGING_H
