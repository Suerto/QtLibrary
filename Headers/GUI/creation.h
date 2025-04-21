#ifndef CREATION_H
#define CREATION_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>


#include "bookFilters.h"
#include "mangaFilters.h"
#include "filmFilters.h"
#include "animeFilters.h"
#include "errorDialog.h"

class Creation : public QWidget {
    Q_OBJECT 
private:
    QVBoxLayout* creationLayout;
    QPushButton* reset;
    QLineEdit* title;
    QHBoxLayout* buttonLayout;
    QButtonGroup* type;
    QStackedWidget* typeForm;
    QPushButton* choice; 
public:
    Creation(QWidget* parent = nullptr);
    void resetCreation();
    void startCreation();
private slots:
    void showTypeForm(int id);
};

#endif //CREATION_H
