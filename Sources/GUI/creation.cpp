#include "../../Headers/GUI/creation.h"
#include "qboxlayout.h"
#include "qnamespace.h"

Creation::Creation(QWidget* parent) : QWidget(parent), creationLayout(new QFormLayout(this)), title(new QLineEdit(this)) {

    title->setPlaceholderText("Inserire Titolo del Contenuto");
    title->setFixedSize(300, 30);
    creationLayout->addWidget(title);
    
    QWidget* typeWidget = new QWidget(this);
    type = new QButtonGroup(typeWidget);
    QHBoxLayout* buttonLayout = new QHBoxLayout(typeWidget);

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
    
    buttonLayout->setAlignment(Qt::AlignRight);
    typeWidget->setLayout(buttonLayout);

    creationLayout->addRow("Selezionare la tipologia di contenuto : ", typeWidget); 

    creationLayout->setAlignment(Qt::AlignRight);
    setLayout(creationLayout);
}
