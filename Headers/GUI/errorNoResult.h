#ifndef ERROR_NO_RESULT_H
#define ERROR_NO_RESULT_H

#include <QPushButton>

#include "errorStructure.h"

class ErrorNoResult : public ErrorStructure {
private:
    QPushButton* confirm;
public:
    ErrorNoResult(QWidget* parent = nullptr);
public slots:
    void chiudiErrore();
};

#endif //ERROR_NO_RESULT_H
