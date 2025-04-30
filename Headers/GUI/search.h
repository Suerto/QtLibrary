#ifndef SEARCH_H
#define SEARCH_H

#include <QCheckBox>

#include "mainWidgets.h"

#include "../LogicModel/contentManager.h"

class Search : public MainWidget {
    Q_OBJECT    
private:
    ContentManager* manager;

    QCheckBox* advancedResearchButton;
    QPushButton* ricerca;
public:
    Search(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
private slots:
    void advancedResearch(bool checked);
    void startSearch();
    void mostraFiltro(int id) override;
};

#endif //SEARCH_H
