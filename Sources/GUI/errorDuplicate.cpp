#include "../../Headers/GUI/errorDuplicate.h"

ErrorDuplicate::ErrorDuplicate(QWidget* parent, const string& mode, const string& title) : ErrorStructure(parent), confirm(new QPushButton("Capito", this)) {
    text->setText("Un contenuto chiamato " + QString::fromStdString("'" + title + "'") + " è già esistente con i seguenti attributi. " + QString::fromStdString(mode + " di '" + title + "'") + " non avvenuta");
    errorLayout->addWidget(confirm, Qt::AlignBottom | Qt::AlignRight);

    connect(confirm, &QPushButton::clicked, this, &ErrorDuplicate::chiudiErrore); 
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

void ErrorDuplicate::chiudiErrore() { close(); }
