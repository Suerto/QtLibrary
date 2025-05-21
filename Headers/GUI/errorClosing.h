#ifndef ERROR_CLOSING_H
#define ERROR_CLOSING_H

#include <QButtonGroup>

#include "errorStructure.h"

class ErrorClosing : public ErrorStructure {
    Q_OBJECT
private:
    QButtonGroup* action;
public:
    ErrorClosing(QWidget* parent = nullptr);
public slots:
    void changeWidget(int id);
signals:
    void azione(const QString& choice);
};

#endif //ERROR_CLOSING_H
