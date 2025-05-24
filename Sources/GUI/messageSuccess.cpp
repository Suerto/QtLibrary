#include "../../Headers/GUI/messageSuccess.h"

MessageSuccess::MessageSuccess(QWidget* parent, const string& mode, const string& title) : ErrorStructure(parent), confirm(new QPushButton("Capito", this)) {
    text->setText(QString::fromStdString(mode) + " di '" + QString::fromStdString("'" + title + "'") + "' avvenuta con successo!");
    errorLayout->addWidget(confirm, Qt::AlignBottom | Qt::AlignRight);

    connect(confirm, &QPushButton::clicked, this, &MessageSuccess::chiudiErrore); 
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

void MessageSuccess::chiudiErrore() { close(); }
