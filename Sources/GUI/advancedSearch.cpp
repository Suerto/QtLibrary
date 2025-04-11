#include "../../Headers/GUI/advancedSearch.h"
#include "qboxlayout.h"
#include "qobject.h"
#include "qsizepolicy.h"
#include "qstackedwidget.h"

AdvancedResearch::AdvancedResearch(QWidget* parent) : QWidget(parent), advancedLayout(new QVBoxLayout(this)), buttonsLayout(new QHBoxLayout(this)), types(new QButtonGroup(this)), filter(new QStackedWidget(this)) { 
    
    QPushButton* libro = new QPushButton("Libro", this);
    libro->setCheckable(true);
    types->addButton(libro, 0);
    
    QPushButton* manga = new QPushButton("Manga", this);
    manga->setCheckable(true);
    types->addButton(manga, 1);

    QPushButton* film = new QPushButton("Film", this);
    film->setCheckable(true);
    types->addButton(film, 2);

    QPushButton* anime = new QPushButton("Anime", this);
    anime->setCheckable(true);
    types->addButton(anime, 3);
 
    foreach(QAbstractButton* button, types->buttons()) buttonsLayout->addWidget(button);
    
    advancedLayout->addLayout(buttonsLayout);

    filter->insertWidget(0, new BookFilters);
    filter->insertWidget(1, new MangaFilters);
    filter->insertWidget(2, new FilmFilters);
    filter->insertWidget(3, new AnimeFilters);
    
    advancedLayout->setContentsMargins(5, 5, 5, 5);
    connect(types, &QButtonGroup::idClicked, this, &AdvancedResearch::showFilters);
}     

void AdvancedResearch::showFilters(int id) {
    //effettua il refresh della schermata dei filtri se viene cambiato il 
    //contenuto selezionato
    (qobject_cast<Filters*>(filter->currentWidget()))->reset();
    filter->setCurrentWidget(filter->widget(id));
    filter->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
    advancedLayout->addWidget(filter);
}

