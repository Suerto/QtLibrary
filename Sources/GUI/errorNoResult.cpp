#include "../../Headers/GUI/errorNoResult.h"

ErrorNoResult::ErrorNoResult(QWidget* parent) : ErrorStructure(parent), confirm(new QPushButton("Capito", this)) {
    text->setText("Nessun risultato trovato sulla base dei filtri inseriti");
    errorLayout->addWidget(confirm);
    
    connect(confirm, &QPushButton::clicked, this, &ErrorNoResult::chiudiErrore);
    setStyleSheet(R"(
        QLabel {
            color : white;
            font-family : Fira Code;
            font-size : 15px;
        }

        QDialog {
            background-color: #848687;
            border: 2px solid #0078D7;
        }
        )");
}

void ErrorNoResult::chiudiErrore() { close(); }
