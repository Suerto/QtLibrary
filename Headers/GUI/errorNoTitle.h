#ifndef ERROR_NO_TITLE_H
#define ERROR_NO_TITLE_H

#include <QPushButton>

#include "errorStructure.h"
#include <string>

using std::string;

class ErrorNoTitle : public ErrorStructure {
private:
    QPushButton* confirm;
public:
    ErrorNoTitle(const string& title = string(), QWidget* parent = nullptr);
public slots:
    void chiudiErrore();
};

#endif //ERROR_NO_TITLE_H
