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
#include "errorDialog.h"

#include "../LogicModel/contentManager.h"

class MainWidget : public QWidget {
    Q_OBJECT
private:
    ContentManager* manager; //riferimento al manager
protected:
    QVBoxLayout* mainLayout; //Layout principale
    QVBoxLayout* topLayout;
    QHBoxLayout* titleLayout;
    QLineEdit* titolo; //Barra di inserimento del titolo
    QPushButton* reset; //pulsante di reset dei filtri
    QHBoxLayout* filtersButtonsLayout;
    QWidget* pulsantiera;
    QButtonGroup* tipologia; //pulsantiera di selezione del tipo mostrabile
    QStackedWidget* filtri; //stack dei possibili tipi mostrabili all'utente
public:
    MainWidget(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
public slots:
    void mostraFiltro(int id);
    void ripristinaFiltri();
    //void raccogliDati();
};

#endif //MAIN_WIDGETS_H
