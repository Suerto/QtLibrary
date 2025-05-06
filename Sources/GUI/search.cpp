#include "../../Headers/GUI/search.h"

Search::Search(QWidget* parent, ContentManager* mngr) : MainWidget(parent), manager(mngr), advancedResearchButton(new QCheckBox("Ricerca Avanzata", this)), ricerca(new QPushButton("Avvia Ricerca", this)) {    
    ricerca->setFixedSize(50, 50);
    titleLayout->addWidget(ricerca);
    topLayout->addWidget(advancedResearchButton);

    connect(advancedResearchButton, &QCheckBox::toggled, this, &Search::advancedResearch);

    connect(ricerca, &QPushButton::clicked, this, &Search::startSearch);

    connect(tipologia, &QButtonGroup::idToggled, this, &Search::mostraFiltro);

    setFixedSize(450, parent->height() / 2);
    setStyleSheet("border: 2px solid black;");
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
        vector<Contenuto*> risultati;
        if(!advancedResearchButton->isChecked()) {
            qDebug() << "Ricerca Per Titolo Avviata";
            risultati = manager->cercaPerTitolo(title);
        }
        else {
            unordered_map<string, string> parametri = qobject_cast<Filters*>(filtri->currentWidget())->raccogliDati();
            parametri.insert({"Titolo", title});
            risultati =  manager->cercaContenuto(filtri->currentIndex(), parametri);
        }
            //else verrà passato il vettore risultante al widget che si occuperà della costruzione dei widget dei 
        if(risultati.size() == 0) {
            ErrorNoResult* error = new ErrorNoResult(this);
            error->exec();
        }
       //risultati. Sicuramente servirà un visitor che visita tutti gli elementi del vettore e a seconda del
       //tipo del contenuto con il metodo visit() costruirà il widget specifico a seconda del contenuto visionato
       //Tali widget verranno poi inseriti in un layout a griglia e cliccandoli dovrà essere possibile visionare 
       //il widget per intero
    } 
}
