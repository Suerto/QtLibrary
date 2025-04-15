#include "../../Headers/GUI/creation.h"

Creation::Creation(QWidget* parent) : QWidget(parent), creationLayout(new QVBoxLayout(this)), title(new QLineEdit(this)) {
    title->setPlaceholderText("Inserire Titolo del Contenuto");
    title->setFixedSize(300, 30);
    creationLayout->addWidget(title);
    



    creationLayout->setAlignment(Qt::AlignTop);
    setLayout(creationLayout);
}
