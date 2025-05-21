#ifndef MESSAGE_SUCCESS_H
#define MESSAGE_SUCCESS_H

#include <string>

#include "errorStructure.h"

using std::string;

class MessageSuccess : public ErrorStructure {
private:
    QPushButton* confirm;
public:
    MessageSuccess(QWidget* parent = nullptr, const string& mode = string(), const string& title = string());
public slots:
    void chiudiErrore();
};

#endif //MESSAGE_SUCCESS_H
