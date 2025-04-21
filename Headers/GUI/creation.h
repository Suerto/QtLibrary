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
    QLineEdit* title;
    QHBoxLayout* buttonLayout;
    QButtonGroup* type;
    QStackedWidget* typeForm;
public:
    Creation(QWidget* parent = nullptr);
private slots:
    void showTypeForm(int id);
};

#endif //CREATION_H
