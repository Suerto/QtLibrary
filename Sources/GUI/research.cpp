#include "../../Headers/GUI/research.h"
#include "qnamespace.h"
#include "qwidget.h"

Research::Research(QWidget* parent, ContentManager* mngr) : QWidget(parent), manager(mngr), researchLayout(new QHBoxLayout(this)), searchSection(new Search(this, mngr)), results(nullptr) {
    searchSection->setFixedWidth(500);
    searchSection->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    researchLayout->addWidget(searchSection, Qt::AlignLeft);
    connect(searchSection, &Search::risultatiOttenuti, this, &Research::showResults);

   setLayout(researchLayout);
} 

void Research::showResults(vector<Contenuto*> res) {
    if(results) {
        delete results;
        results = nullptr;
    }

    results = new ViewContents(res, this);
    results->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    researchLayout->addWidget(results);

    connect(results, &ViewContents::eliminaOggetto, this, [this](int index, Contenuto* oggetto) {
            qDebug() << "Inizio eliminazione : " << index << " " << static_cast<void*>(oggetto);
            manager->eliminaContenuto(index, oggetto);
            });
}
