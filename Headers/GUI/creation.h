#ifndef CREATION_H
#define CREATION_H

#include <QWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QButtonGroup>
#include <QPushButton>

class Creation : public QWidget {
    Q_OBJECT 
private:
    QFormLayout* creationLayout;
    QLineEdit* title;
    QButtonGroup* type;
public:
    Creation(QWidget* parent = nullptr);
};

#endif //CREATION_H
