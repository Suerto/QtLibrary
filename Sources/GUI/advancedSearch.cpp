#include "../../Headers/GUI/advancedSearch.h"

AdvancedResearch::AdvancedResearch(QWidget* parent) : QWidget(parent), advancedLayout(new QVBoxLayout(this)), buttonsLayout(new QHBoxLayout()), types(new QButtonGroup()), filter(new QStackedWidget()) { 

    QPushButton* libro = new QPushButton("Libro", this);
    libro->setFixedSize(100, 25);
    libro->setCheckable(true);
    types->addButton(libro, 0);
    
    QPushButton* manga = new QPushButton("Manga", this);
    manga->setFixedSize(100, 25);
    manga->setCheckable(true);
    types->addButton(manga, 1);

    QPushButton* film = new QPushButton("Film", this);
    film->setFixedSize(100, 25);
    film->setCheckable(true);
    types->addButton(film, 2);

    QPushButton* anime = new QPushButton("Anime", this);
    anime->setFixedSize(100, 25);
    anime->setCheckable(true);
    types->addButton(anime, 3);
 
    foreach(QAbstractButton* button, types->buttons()) buttonsLayout->addWidget(button);
    
    advancedLayout->addLayout(buttonsLayout);

    filter->insertWidget(0, new BookFilters);
    filter->insertWidget(1, new MangaFilters);
    filter->insertWidget(2, new FilmFilters);
    filter->insertWidget(3, new AnimeFilters);
    
    advancedLayout->setContentsMargins(5, 5, 5, 5);
    connect(types, &QButtonGroup::idToggled, this, &AdvancedResearch::showFilters);
}     

void AdvancedResearch::showFilters(int id) {
    filter->setCurrentWidget(filter->widget(id));
    (qobject_cast<Filters*>(filter->currentWidget()))->reset();
    advancedLayout->addWidget(filter);
}

