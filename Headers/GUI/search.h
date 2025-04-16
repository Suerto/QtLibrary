#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>

#include "advancedSearch.h"

class Search : public QWidget {
    Q_OBJECT    
private:
    QLineEdit* searchBar;
    QPushButton* searchButton;
    QCheckBox* advancedResearchButton;
    AdvancedResearch* advancedSearch;
    QVBoxLayout* searchLayout;
    QHBoxLayout* simpleSearchLayout;
public:
    Search(QWidget* parent = nullptr);
private slots:
    void advancedResearch(bool checked);
    void startSearch();
    
    //Possibile idea, resettare i widget se si cambia la schermata visualizzata:
    //Se il widget è quello di ricerca, resettare tutti i filtri
    //Se il widget è quello di creazione, mostrare un prompt che indica che le 
    //modifiche verranno perse
    //void refreshOnChanged();
};

#endif //SEARCH_H
