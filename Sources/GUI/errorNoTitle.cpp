#include "../../Headers/GUI/errorNoTitle.h"

ErrorNoTitle::ErrorNoTitle(QWidget* parent) : ErrorStructure(parent), confirm(new QPushButton("Capito", this)) {
    text->setText("Titolo Assente. Ricerca non effettuata");
    errorLayout->addWidget(confirm);
    
    connect(confirm, &QPushButton::clicked, this, &ErrorNoTitle::chiudiErrore);
}

void ErrorNoTitle::chiudiErrore() { close(); }
