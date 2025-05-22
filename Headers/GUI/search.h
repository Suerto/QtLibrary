#ifndef SEARCH_H
#define SEARCH_H

#include <QCheckBox>

#include "mainWidgets.h"
#include "errorNoResult.h"
#include "errorNoTitle.h"
#include "viewContents.h" 

#include "../LogicModel/contentManager.h"

class Search : public MainWidget {
    Q_OBJECT    
private:
    QCheckBox* advancedResearchButton;
    QPushButton* ricerca;
    QHBoxLayout* searchLayout;
public:
    Search(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
    virtual ~Search() override;
    private slots:
        void advancedResearch(bool checked);
    void startSearch();
    void mostraFiltro(int id) override;
signals:
    void risultatiOttenuti(vector<Contenuto*> res);
};

#endif //SEARCH_H
