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
            res = manager->cercaPerTitolo(title);
        }
        else {
            qDebug() << "ingresso nell'else per la ricerca per parametri";
            unordered_map<string, string> parametri = qobject_cast<Filters*>(filtri->currentWidget())->raccogliDati();
            parametri.insert({"Titolo", title});

            qDebug() << "parametri raccolti :";
            for(const auto&[T, V] : parametri) qDebug() << QString::fromStdString(T) << " : " << QString::fromStdString(V);
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
