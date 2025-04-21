#ifndef ERROR_DIALOG_H
#define ERROR_DIALOG_H

#include "qstringliteral.h"
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>

class ErrorDialog : public QDialog {
    Q_OBJECT
private:
    QLabel* text;
    QVBoxLayout* errorLayout;
    QButtonGroup* action;
public:
    ErrorDialog(QWidget* parent = nullptr);
public slots:
    void changeWidget(int id);
signals:
    void azione(const QString& choice);
};

#endif //ERROR_DIALOG_H
