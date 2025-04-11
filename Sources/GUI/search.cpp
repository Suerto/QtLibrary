#include "../../Headers/GUI/search.h"
#include "qboxlayout.h"

Search::Search(QWidget* parent) : QWidget(parent), searchBar(new QLineEdit(this)), searchButton(new QPushButton(this)), advancedResearchButton(new QCheckBox("Ricerca Avanzata", this)), advancedSearch(new AdvancedResearch(this)), searchLayout(new QVBoxLayout(this)), simpleSearchLayout(new QHBoxLayout(this)) {

    searchBar->setPlaceholderText("Inserire titolo del contenuto...");
    searchBar->setFixedSize(350, 40);

    searchButton->setFixedSize(40, 40);
    simpleSearchLayout->addWidget(searchBar);
    simpleSearchLayout->addWidget(searchButton);
    searchLayout->addLayout(simpleSearchLayout);
   
    advancedResearchButton->setFixedSize(175, 20);
    searchLayout->addWidget(advancedResearchButton);
    
    advancedSearch->setVisible(false);
    advancedSearch->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    searchLayout->addWidget(advancedSearch);

    searchLayout->setContentsMargins(5, 5, 5, 5);
    searchLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop); 
    connect(advancedResearchButton, &QCheckBox::toggled, this, &Search::advancedResearch);

}

void Search::advancedResearch(bool checked) {
    checked ? advancedSearch->show() : advancedSearch->hide();
}
