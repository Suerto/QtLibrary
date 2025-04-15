#ifndef CREATION_H
#define CREATION_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>


class Creation : public QWidget {
    Q_OBJECT 
private:
    QVBoxLayout* creationLayout;
    QLineEdit* title;
public:
    Creation(QWidget* parent = nullptr);
};

#endif //CREATION_H
