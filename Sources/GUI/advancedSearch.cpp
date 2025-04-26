#include "../../Headers/GUI/advancedSearch.h"
#include "qnamespace.h"

AdvancedResearch::AdvancedResearch(QWidget* parent) : QWidget(parent), advancedLayout(new QVBoxLayout(this)), buttonsLayout(new QHBoxLayout()), types(new QButtonGroup()), filter(new QStackedWidget()) { 
    //setFixedSize(parent->width(), parent->height());
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
    types->addButton(film, 2) ;

    QPushButton* anime = new QPushButton("Anime", this);
    anime->setFixedSize(100, 25);
    anime->setCheckable(true);
    types->addButton(anime, 3);
 
    foreach(QAbstractButton* button, types->buttons()) buttonsLayout->addWidget(button);
    
    advancedLayout->addLayout(buttonsLayout);

    BookFilters* filtroLibro = new BookFilters;
    MangaFilters* filtroManga = new MangaFilters;
    FilmFilters* filtroFilm = new FilmFilters;
    AnimeFilters* filtroAnime = new AnimeFilters;

    filter->insertWidget(0, filtroLibro);
    filter->insertWidget(1, filtroManga);
    filter->insertWidget(2, filtroFilm);
    filter->insertWidget(3, filtroAnime);
    
    advancedLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    //advancedLayout->setContentsMargins(5, 5, 5, 5);
    connect(types, &QButtonGroup::idToggled, this, &AdvancedResearch::showFilters);

    connect(filtroLibro, &Filters::datiRaccolti, this, &AdvancedResearch::ottieniMappaAttributi);
    connect(filtroManga, &Filters::datiRaccolti, this, &AdvancedResearch::ottieniMappaAttributi);
    connect(filtroFilm, &Filters::datiRaccolti, this, &AdvancedResearch::ottieniMappaAttributi);
    connect(filtroAnime, &Filters::datiRaccolti, this, &AdvancedResearch::ottieniMappaAttributi);
}     

void AdvancedResearch::showFilters(int id) {
    filter->setCurrentWidget(filter->widget(id));
    (qobject_cast<Filters*>(filter->currentWidget()))->reset();
    advancedLayout->addWidget(filter);
}

void AdvancedResearch::ottieniMappaAttributi(const int& index, const std::unordered_map<string, string>& attributi) {
    emit datiRaccolti(filter->currentIndex(), attributi);
}
