#include "../../Headers/GUI/creation.h"

Creation::Creation(QWidget* parent) : QWidget(parent), creationLayout(new QVBoxLayout(this)), title(new QLineEdit(this)) {
    title->setPlaceholderText("Inserire Titolo del Contenuto");
    creationLayout->addWidget(title);


    setLayout(creationLayout);
}
