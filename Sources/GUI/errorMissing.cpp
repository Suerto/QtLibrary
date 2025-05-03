#include "../../Headers/GUI/errorMissing.h"
#include "qnamespace.h"

ErrorMissing::ErrorMissing(QWidget* parent) : ErrorStructure(parent), confirm(new QPushButton("Capito", this)) {
    text->setText("Uno o più filtri non sono stati dichiarati. Creazione del Contenuto non avvenuta");
    errorLayout->addWidget(confirm, Qt::AlignBottom | Qt::AlignRight);

    connect(confirm, &QPushButton::clicked, this, &ErrorMissing::chiudiErrore);
}

void ErrorMissing::chiudiErrore() { close(); }
