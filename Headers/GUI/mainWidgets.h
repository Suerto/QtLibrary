#ifndef MAIN_WIDGETS_H
#define MAIN_WIDGETS_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QButtonGroup>

#include "bookFilters.h"
#include "animeFilters.h"
#include "mangaFilters.h"
#include "filmFilters.h"
#include "errorMissing.h"
#include "errorChanging.h"

#include "../LogicModel/contentManager.h"

class MainWidget : public QWidget {
    Q_OBJECT
private:
    ContentManager* manager;
protected:
    QVBoxLayout* mainLayout;
    QVBoxLayout* topLayout;
    QHBoxLayout* titleLayout;
    QLineEdit* titolo;
    QPushButton* reset; 
    QHBoxLayout* filtersButtonsLayout;
    QWidget* pulsantiera;
    QButtonGroup* tipologia;
    QStackedWidget* filtri; 
public:
    MainWidget(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
public slots:
    virtual void mostraFiltro(int id) = 0;
    void ripristinaFiltri();
};

#endif //MAIN_WIDGETS_H
