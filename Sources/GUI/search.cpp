#include "../../Headers/GUI/search.h"

Search::Search(QWidget* parent, ContentManager* mngr) : MainWidget(parent, mngr), advancedResearchButton(new QCheckBox("Ricerca Avanzata", this)), ricerca(new QPushButton("Avvia Ricerca", this)) {   
    ricerca->setFixedSize(50, 50);
    titleLayout->addWidget(ricerca);
    topLayout->addWidget(advancedResearchButton);
    
    connect(advancedResearchButton, &QCheckBox::toggled, this, &Search::advancedResearch);

    connect(ricerca, &QPushButton::clicked, this, &Search::startSearch);
}

void Search::advancedResearch(bool checked) {
    if(checked) {
        pulsantiera->setVisible(true);
        
        if(tipologia->checkedId() != -1) filtri->setVisible(true);
        connect(tipologia, &QButtonGroup::idToggled, this, &Search::mostraFiltro);
    }

    else {
        pulsantiera->setVisible(false);
        qobject_cast<Filters*>(filtri->currentWidget())->reset();
        filtri->setVisible(false);
    }
}

void Search::mostraFiltro(int id) {
    if(id != 4) {
        filtri->setCurrentIndex(id);
        filtri->setVisible(true);
    }
}

void Search::startSearch() {
    if(titolo->text().toStdString().empty()) {
        ErrorNoTitle error("Ricerca", this);
        error.exec();
    }
    else {
        const string& title = titolo->text().toStdString();
        vector<Contenuto*> res;
        if(!advancedResearchButton->isChecked()) {
            qDebug() << "Avvio ricerca solo con titolo";
            res = manager->cercaPerTitolo(title);
        }
        else {
            unordered_map<string, string> parametri = qobject_cast<Filters*>(filtri->currentWidget())->raccogliDati();
            parametri.insert({"Titolo", title});
            qDebug() << "Avvio ricerca con filtri";
            res =  manager->cercaContenuto(filtri->currentIndex(), parametri);
        }
        
        if(res.size() == 0) {
            ErrorNoResult error(this);
            error.exec();
        }
        else emit risultatiOttenuti(res);
    } 
}

Search::~Search() = default;
