#include "../../Headers/GUI/search.h"
#include "qboxlayout.h"

Search::Search(QWidget* parent) : QWidget(parent), searchBar(new QLineEdit()), searchButton(new QPushButton()), advancedResearchButton(new QCheckBox("Ricerca Avanzata")), advancedSearch(new AdvancedResearch(this)), searchLayout(new QVBoxLayout()), simpleSearchLayout(new QHBoxLayout()) {   
    searchBar->setPlaceholderText("Inserire titolo del contenuto...");
    searchBar->setFixedSize(400, 40);

    searchButton->setFixedSize(40, 40);
    simpleSearchLayout->addWidget(searchBar);
    simpleSearchLayout->addWidget(searchButton);
    simpleSearchLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    searchLayout->addLayout(simpleSearchLayout);
   
    advancedResearchButton->setFixedSize(175, 15);
    searchLayout->addWidget(advancedResearchButton);
    
    advancedSearch->setVisible(false);

    searchLayout->addWidget(advancedSearch);

    //searchLayout->setContentsMargins(15, 15, 15, 15);
    searchLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft); 
    connect(advancedResearchButton, &QCheckBox::toggled, this, &Search::advancedResearch);

    setLayout(searchLayout);
}

void Search::advancedResearch(bool checked) { checked ? advancedSearch->setVisible(true) : advancedSearch->setVisible(false); }
