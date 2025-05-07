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
    ContentManager* manager;

    QCheckBox* advancedResearchButton;
    QPushButton* ricerca;
    //Quasi sicuramente un puntatore che viene ogni volta resettato per la 
    //visualizzazione dei contenuti ottenuti da startResearch() che invocherà
    //cercaContenuto() e verrà usato un vettore per inizializzare la costruzione
    //ViewContents* risultati;
    //
    //molto probabilmente conviene tenere Search all'interno di un'altra classe
    //mediante un puntatore e MainWindow creerà una istanza di quella nuova classe
    ViewContents* result;
    QHBoxLayout* searchLayout;
public:
    Search(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
private slots:
    void advancedResearch(bool checked);
    void startSearch();
    void mostraFiltro(int id) override;
signals:
    void risultatiOttenuti(vector<Contenuto*> res);
};

#endif //SEARCH_H
