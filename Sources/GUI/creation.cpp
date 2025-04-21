#include "../../Headers/GUI/creation.h"
#include "qbuttongroup.h"
#include "qnamespace.h"

Creation::Creation(QWidget* parent) : QWidget(parent), creationLayout(new QVBoxLayout(this)), reset(new QPushButton("Riprista filtri", this)), title(new QLineEdit(this)), buttonLayout(new QHBoxLayout), type(new QButtonGroup(this)), typeForm(new QStackedWidget(this)), choice(new QPushButton("Crea Contenuto", this)) {
    
    
    creationLayout->addWidget(reset, Qt::AlignLeft);

    title->setPlaceholderText("Inserire Titolo del Contenuto");
    title->setFixedSize(300, 30);
    creationLayout->addWidget(title, Qt::AlignLeft | Qt::AlignTop);
    
    QPushButton* book = new QPushButton("Libro", this);
    book->setFixedSize(100, 25);
    book->setCheckable(true);
    type->addButton(book, 0);

    QPushButton* manga = new QPushButton("Manga", this);
    manga->setFixedSize(100, 25);
    manga->setCheckable(true);
    type->addButton(manga, 1);

    QPushButton* film = new QPushButton("Film", this);
    film->setFixedSize(100, 25);
    film->setCheckable(true);
    type->addButton(film, 2);

    QPushButton* anime = new QPushButton("Anime", this);
    anime->setFixedSize(100, 25);
    anime->setCheckable(true);
    type->addButton(anime, 3);

    foreach(QAbstractButton* button, type->buttons()) buttonLayout->addWidget(button);

    buttonLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    creationLayout->addLayout(buttonLayout);

    typeForm->insertWidget(1, new BookFilters);
    typeForm->insertWidget(2, new MangaFilters);
    typeForm->insertWidget(3, new FilmFilters);
    typeForm->insertWidget(4, new AnimeFilters);

    typeForm->setVisible(false);
    creationLayout->addWidget(typeForm);
    creationLayout->setAlignment(Qt::AlignCenter);

    creationLayout->addWidget(choice); 

    connect(type, &QButtonGroup::idClicked, this, &Creation::showTypeForm);

    connect(reset, &QPushButton::clicked, this, &Creation::resetCreation);

    connect(choice, &QPushButton::clicked, this, &Creation::startCreation);

}

void Creation::showTypeForm(int id) {
    //gestione del tentativo di cambio del widget durante la creazione dell'oggetto
    if(typeForm->currentIndex() != id && typeForm->currentIndex() != -1) {
        ErrorDialog* change = new ErrorDialog(this);
        connect(change, &ErrorDialog::azione, this, [this, id](const QString& choice) {
                if(choice == "Conferma") {
                    qobject_cast<Filters*>(typeForm->currentWidget())->reset();
                    //typeForm->setCurrentIndex(id);
                }
        });

        change->exec();
    }

    typeForm->setCurrentIndex(id);
    typeForm->setVisible(true);

}

void Creation::resetCreation() {
   title->clear();
   qobject_cast<Filters*>(typeForm->currentWidget())->reset();
}

void Creation::startCreation() {}
