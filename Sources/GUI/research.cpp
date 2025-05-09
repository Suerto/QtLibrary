#include "../../Headers/GUI/research.h"
#include "qnamespace.h"
#include "qwidget.h"

Research::Research(QWidget* parent, ContentManager* mngr) : QWidget(parent), manager(mngr), researchLayout(new QHBoxLayout(this)), searchSection(new Search(this, mngr)), results(nullptr) {
    searchSection->setFixedWidth(500);
    researchLayout->addWidget(searchSection, Qt::AnchorLeft);
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
}
