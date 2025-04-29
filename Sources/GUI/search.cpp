#include "../../Headers/GUI/search.h"

Search::Search(QWidget* parent, ContentManager* mngr) : MainWidget(parent), manager(mngr), advancedResearchButton(new QCheckBox("Ricerca Avanzata", this)), ricerca(new QPushButton("Avvia Ricerca", this)) {    
    ricerca->setFixedSize(50, 50);
    titleLayout->addWidget(ricerca);
    topLayout->addWidget(advancedResearchButton);

    connect(advancedResearchButton, &QCheckBox::toggled, this, &Search::advancedResearch);
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
