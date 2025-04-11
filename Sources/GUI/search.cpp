#include "../../Headers/GUI/search.h"
#include "qboxlayout.h"

Search::Search(QWidget* parent) : QWidget(parent), searchBar(new QLineEdit()), searchButton(new QPushButton()), advancedResearchButton(new QCheckBox("Ricerca Avanzata")), advancedSearch(new AdvancedResearch(this)), searchLayout(new QVBoxLayout()), simpleSearchLayout(new QHBoxLayout()) {   
    //setStyleSheet("border : 2px solid blue; border-radius: 4px; ");
    searchBar->setPlaceholderText("Inserire titolo del contenuto...");
    searchBar->setFixedSize(400, 40);

    searchButton->setFixedSize(40, 40);
    simpleSearchLayout->addWidget(searchBar);
    simpleSearchLayout->addWidget(searchButton);
    searchLayout->addLayout(simpleSearchLayout);
   
    advancedResearchButton->setFixedSize(175, 15);
    searchLayout->addWidget(advancedResearchButton);
    
    advancedSearch->setVisible(false);
    advancedSearch->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //advancedSearch->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    searchLayout->addWidget(advancedSearch);

    searchLayout->setContentsMargins(15, 15, 15, 15);
    searchLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop); 
    connect(advancedResearchButton, &QCheckBox::toggled, this, &Search::advancedResearch);

    setLayout(searchLayout);
}

void Search::advancedResearch(bool checked) { checked ? advancedSearch->show() : advancedSearch->hide(); }
