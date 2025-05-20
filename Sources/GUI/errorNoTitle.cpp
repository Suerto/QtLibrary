#include "../../Headers/GUI/errorNoTitle.h"

ErrorNoTitle::ErrorNoTitle(const string& mode, QWidget* parent) : ErrorStructure(parent), confirm(new QPushButton("Capito", this)) {
    text->setText("Titolo Assente. " + QString::fromStdString(mode) + " non effettuata");
    errorLayout->addWidget(confirm);
    
    connect(confirm, &QPushButton::clicked, this, &ErrorNoTitle::chiudiErrore);
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

void ErrorNoTitle::chiudiErrore() { close(); }
