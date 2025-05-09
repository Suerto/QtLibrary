#include "../../Headers/GUI/research.h"
#include "qnamespace.h"
#include "qwidget.h"

Research::Research(QWidget* parent, ContentManager* mngr) : QWidget(parent), manager(mngr), researchLayout(new QHBoxLayout(this)), searchSection(new Search(this, mngr)), results(nullptr) {
    searchSection->setFixedWidth(500);
    searchSection->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    researchLayout->addWidget(searchSection, Qt::AlignLeft);
    setStyleSheet("border: 1px solid red");
    //C'è un problemone qui!!!
    connect(searchSection, &Search::risultatiOttenuti, this, &Research::showResults);

   setLayout(researchLayout);
} 

void Research::showResults(vector<Contenuto*> res) {
    results = new ViewContents(res, this);
    results->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    researchLayout->addWidget(results);
}
