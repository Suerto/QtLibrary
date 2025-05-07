#include "../../Headers/GUI/search.h"

Search::Search(QWidget* parent, ContentManager* mngr) : MainWidget(parent), manager(mngr), advancedResearchButton(new QCheckBox("Ricerca Avanzata", this)), ricerca(new QPushButton("Avvia Ricerca", this)) {   
    setStyleSheet("border: 1px solid white;");
    ricerca->setFixedSize(50, 50);
    titleLayout->addWidget(ricerca);
    topLayout->addWidget(advancedResearchButton);
    
    connect(advancedResearchButton, &QCheckBox::toggled, this, &Search::advancedResearch);

    connect(ricerca, &QPushButton::clicked, this, &Search::startSearch);

    connect(tipologia, &QButtonGroup::idToggled, this, &Search::mostraFiltro); 
}

void Search::advancedResearch(bool checked) {
    if(checked) {
        pulsantiera->setVisible(true);
    }

    else {
        pulsantiera->setVisible(false);
        qobject_cast<Filters*>(filtri->currentWidget())->reset();
        filtri->setVisible(false);
    }
}

void Search::mostraFiltro(int id) {
        filtri->setCurrentIndex(id);
        filtri->setVisible(true);
}

void Search::startSearch() {
    //Identificare a chi dover passare il vettore dei contenuti :
    //  O alla MainWindow, però converrebbe fosse un widget legato alla sezione di Ricerca
    if(titolo->text().toStdString().empty()) {
        ErrorNoTitle* error = new ErrorNoTitle(this);
        error->exec();
    }
    else {
        const string& title = titolo->text().toStdString();
        vector<Contenuto*> res;
        if(!advancedResearchButton->isChecked()) {
            qDebug() << "Ricerca Per Titolo Avviata";
            res = manager->cercaPerTitolo(title);
            qDebug() << res.size();
        }
        else {
            unordered_map<string, string> parametri = qobject_cast<Filters*>(filtri->currentWidget())->raccogliDati();
            parametri.insert({"Titolo", title});
            res =  manager->cercaContenuto(filtri->currentIndex(), parametri);
        }
        
        if(res.size() == 0) {
            ErrorNoResult* error = new ErrorNoResult(this);
            error->exec();
        }
        else emit risultatiOttenuti(res); 
    } 
}
