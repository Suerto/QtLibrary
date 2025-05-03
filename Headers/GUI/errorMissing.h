#ifndef ERROR_MISSING_H
#define ERROR_MISSING_H

#include "errorStructure.h"

class ErrorMissing : public ErrorStructure {
private:
    QPushButton* confirm;
public:
    ErrorMissing(QWidget* parent = nullptr);
public slots:
    void chiudiErrore();
};

#endif //ERROR_MISSING_H
