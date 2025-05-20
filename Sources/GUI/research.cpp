#include "../../Headers/GUI/research.h"

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
    

    connect(results, &ViewContents::eliminaOggetto, this, [this](const int& index, const unordered_map<string, string>& attributi) {
            manager->eliminaContenuto(index, attributi);
            });
    connect(results, &ViewContents::modificaOggetto, this, [this](const int& index, const unordered_map<string, string>& original, const unordered_map<string, string>& modifiche) {
            manager->modificaContenuto(index, original, modifiche);
            });
}

Research::~Research() {
    manager = nullptr;
}
