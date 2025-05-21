#ifndef ERROR_DUPLICATE_H
#define ERROR_DUPLICATE_H

#include <string>

#include "errorStructure.h"

using std::string;

class ErrorDuplicate : public ErrorStructure {
private:
    QPushButton* confirm;
public:
    ErrorDuplicate(QWidget* parent = nullptr, const string& mode = string(),
            const string& title = string());
public slots:
    void chiudiErrore();
};

#endif //ERROR_DUPLICATE_H
