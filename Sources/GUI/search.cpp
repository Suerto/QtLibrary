#include "../../Headers/GUI/search.h"

Search::Search(QWidget* parent) : QWidget(parent), searchBar(new QLineEdit()), searchButton(new QPushButton()), advancedResearchButton(new QCheckBox("Ricerca Avanzata")), advancedSearch(new AdvancedResearch(this)), searchLayout(new QVBoxLayout()), simpleSearchLayout(new QHBoxLayout()) {   
    searchBar->setPlaceholderText("Inserire titolo del contenuto...");
    searchBar->setFixedSize(400, 40);

    searchButton->setFixedSize(40, 40);
    titleError = new QLabel(this);
    titleError->setText("Inserire un titolo");
    titleError->setVisible(false);

    simpleSearchLayout->addWidget(searchBar);
    simpleSearchLayout->addWidget(searchButton);
    simpleSearchLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    searchLayout->addLayout(simpleSearchLayout);
   
    advancedResearchButton->setFixedSize(175, 15);
    searchLayout->addWidget(titleError);
    searchLayout->addWidget(advancedResearchButton);
    
    advancedSearch->setVisible(false);

    searchLayout->addWidget(advancedSearch);

    searchLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft); 
    connect(advancedResearchButton, &QCheckBox::toggled, this, &Search::advancedResearch);
    
    connect(searchButton, &QPushButton::clicked, this, &Search::startSearch);

    setLayout(searchLayout);
}

void Search::advancedResearch(bool checked) { checked ? advancedSearch->show() : advancedSearch->hide(); }

void Search::startSearch() {
    searchBar->text().isEmpty() ? titleError->show() : (titleError->isHidden() ? advancedSearch->show() : (titleError->hide()));
}
