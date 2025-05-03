#include "../../Headers/GUI/errorNoResult.h"

ErrorNoResult::ErrorNoResult(QWidget* parent) : ErrorStructure(parent), confirm(new QPushButton("Capito", this)) {
    text->setText("Nessun risultato trovato sulla base dei filtri inseriti");
    errorLayout->addWidget(confirm);
    
    connect(confirm, &QPushButton::clicked, this, &ErrorNoResult::chiudiErrore);
}

void ErrorNoResult::chiudiErrore() { close(); }
