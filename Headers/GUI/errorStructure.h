#ifndef ERROR_STRUCTURE_H
#define ERROR_STRUCTURE_H

#include <QDialog>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>

class ErrorStructure : public QDialog {
protected:
    QLabel* text;
    QVBoxLayout* errorLayout;
public:
    ErrorStructure(QWidget* parent = nullptr);
};

#endif //ERRORE_STRUCTURE_H
