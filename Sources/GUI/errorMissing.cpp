#include "../../Headers/GUI/errorMissing.h"
#include "qnamespace.h"

ErrorMissing::ErrorMissing(QWidget* parent, const string& mode, const string& title) : ErrorStructure(parent), confirm(new QPushButton("Capito", this)) {
    text->setText("Uno o più filtri non sono stati dichiarati. " + QString::fromStdString(mode)  + " di " + QString::fromStdString("'" + title + "'") + " non avvenuta");
    errorLayout->addWidget(confirm, Qt::AlignBottom | Qt::AlignRight);

    connect(confirm, &QPushButton::clicked, this, &ErrorMissing::chiudiErrore); 
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

void ErrorMissing::chiudiErrore() { close(); }
