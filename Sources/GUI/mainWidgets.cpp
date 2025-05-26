#include "../../Headers/GUI/mainWidgets.h"
#include "qwidget.h"

MainWidget::MainWidget(QWidget* parent, ContentManager* mngr) : QWidget(parent), manager(mngr), mainLayout(new QVBoxLayout(this)), topLayout(new QVBoxLayout()), titleLayout(new QHBoxLayout()), titolo(new QLineEdit(this)), reset(new QPushButton("Ripristina Filtri", this)), filtersButtonsLayout(new QHBoxLayout()), pulsantiera(new QWidget(this)), tipologia(new QButtonGroup(this)), filtri(new QStackedWidget(this)) {
    titolo->setPlaceholderText("Inserire titolo del Contenuto : ");
    titolo->setFixedSize(300, 50);
    titolo->setStyleSheet("QLineEdit::placeholder { color : white; }");
    titleLayout->addWidget(titolo);
    
    reset->setFixedSize(50, 50);
    titleLayout->addWidget(reset);

    topLayout->addLayout(titleLayout);

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
        pulsante->setFixedSize(90, 25);
    }
    pulsantiera->setLayout(filtersButtonsLayout);

    mainLayout->addWidget(pulsantiera);
    pulsantiera->setVisible(false);

    BookFilters* filtroLibro = new BookFilters(this);
    MangaFilters* filtroManga = new MangaFilters(this);
    FilmFilters* filtroFilm = new FilmFilters(this);
    AnimeFilters* filtroAnime = new AnimeFilters(this);

    filtri->insertWidget(0, filtroLibro);
    filtri->insertWidget(1, filtroManga);
    filtri->insertWidget(2, filtroFilm);
    filtri->insertWidget(3, filtroAnime);

    filtri->setCurrentIndex(-1);

    filtri->setVisible(false);
    filtri->setFixedSize(410, maximumHeight());

    mainLayout->addWidget(filtri);
    titleLayout->setAlignment(mainLayout->alignment());
    mainLayout->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    
    setLayout(mainLayout);

    connect(tipologia, &QButtonGroup::idToggled, this, &MainWidget::mostraFiltro);

    connect(reset, &QPushButton::clicked, this, &MainWidget::ripristinaFiltri);

    //Design
    setStyleSheet(R"(
        QPushButton {
            background-color : #4D91C6;
            font-family : Cascadia Code;
            font-size : 13px;
        }   

        QPushButton::checked {
            background-color : #33B2FF;
            font-weight : bold;
        }

        QLabel {
            color : white;
            font-size : 13px;
            font-family : Fira Code;
        }

        QLineEdit {
            background-color: #66CCCC;
            color : white;
        }
    )");
}

void MainWidget::ripristinaFiltri() {
   qobject_cast<Filters*>(filtri->currentWidget())->reset();
}

MainWidget::~MainWidget() {
    delete topLayout;
    delete filtersButtonsLayout;
    manager = nullptr;
}
