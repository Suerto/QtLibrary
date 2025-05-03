#ifndef ERROR_NO_TITLE_H
#define ERROR_NO_TITLE_H

#include <QPushButton>

#include "errorStructure.h"

class ErrorNoTitle : public ErrorStructure {
private:
    QPushButton* confirm;
public:
    ErrorNoTitle(QWidget* parent = nullptr);
public slots:
    void chiudiErrore();
};

#endif //ERROR_NO_TITLE_H
