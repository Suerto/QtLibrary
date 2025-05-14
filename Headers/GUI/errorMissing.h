#ifndef ERROR_MISSING_H
#define ERROR_MISSING_H

#include "errorStructure.h"
#include <string>

using std::string;

class ErrorMissing : public ErrorStructure {
private:
    QPushButton* confirm;
public:
    ErrorMissing(QWidget* parent = nullptr, const string& mode = string(), const string& title = string());
public slots:
    void chiudiErrore();
};

#endif //ERROR_MISSING_H
