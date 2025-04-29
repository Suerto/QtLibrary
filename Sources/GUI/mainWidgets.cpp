#include "../../Headers/GUI/mainWidgets.h"

MainWidget::MainWidget(QWidget* parent, ContentManager* mngr) : QWidget(parent), manager(mngr), mainLayout(new QVBoxLayout(this)), topLayout(new QVBoxLayout()), titleLayout(new QHBoxLayout()), titolo(new QLineEdit(this)), reset(new QPushButton("Ripristina Filtri", this)), filtersButtonsLayout(new QHBoxLayout()), pulsantiera(new QWidget(this)), tipologia(new QButtonGroup(pulsantiera)), filtri(new QStackedWidget(this)) {
    titolo->setPlaceholderText("Inserire titolo del Contenuto : ");
    titolo->setFixedSize(300, 50);
    titleLayout->addWidget(titolo);
    
    reset->setFixedSize(50, 50);
    titleLayout->addWidget(reset);

    topLayout->addLayout(titleLayout);
    //topLayout->setAlignment(mainLayout->alignment());
    mainLayout->addLayout(topLayout);

    QPushButton* book = new QPushButton("Libro", this);
    tipologia->addButton(book, 0);

    QPushButton* manga = new QPushButton("Manga", this);
    tipologia->addButton(manga, 1);

    QPushButton* film = new QPushButton("Film", this);
    tipologia->addButton(film, 2);

    QPushButton* anime = new QPushButton("Anime", this);
    tipologia->addButton(anime, 3);

    foreach(QAbstractButton* pulsante, tipologia->buttons()) {
        filtersButtonsLayout->addWidget(pulsante);
        pulsante->setCheckable(true);
        pulsante->setFixedSize(95, 25);
    }
    pulsantiera->setLayout(filtersButtonsLayout);

    mainLayout->addWidget(pulsantiera);
    pulsantiera->setVisible(false);

    BookFilters* filtroLibro = new BookFilters;
    MangaFilters* filtroManga = new MangaFilters;
    FilmFilters* filtroFilm = new FilmFilters;
    AnimeFilters* filtroAnime = new AnimeFilters;
    
    filtri->insertWidget(0, filtroLibro);
    filtri->insertWidget(1, filtroManga);
    filtri->insertWidget(2, filtroFilm);
    filtri->insertWidget(3, filtroAnime);
    
    filtri->setVisible(false);
    filtri->setFixedSize(400, maximumHeight());

    mainLayout->addWidget(filtri);
    titleLayout->setAlignment(mainLayout->alignment());
    mainLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    connect(tipologia, &QButtonGroup::idToggled, this, &MainWidget::mostraFiltro);

    connect(reset, &QPushButton::clicked, this, &MainWidget::ripristinaFiltri);
}

void MainWidget::ripristinaFiltri() {
   qobject_cast<Filters*>(filtri->currentWidget())->reset();
}

void MainWidget::mostraFiltro(int id) {
    //gestione del tentativo di cambio del widget durante la creazione dell'oggetto
    if(filtri->currentIndex() != id && filtri->isVisible()) {
            ErrorDialog* change = new ErrorDialog(this);
            connect(change, &ErrorDialog::azione, this, [this, id](const QString& choice) {
                if(choice == "Conferma") {
                    qobject_cast<Filters*>(filtri->currentWidget())->reset();
                    filtri->setCurrentIndex(id);
                }
                else {
                    tipologia->button(filtri->currentIndex())->click();
                }
            });
            change->exec();
        }
    else {
        filtri->setCurrentIndex(id);
        filtri->setVisible(true);
  }
}
