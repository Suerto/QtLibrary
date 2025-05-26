#include "../../Headers/GUI/error.h"

ErrorStructure::ErrorStructure(QWidget* parent) : QDialog(parent), text(new QLabel(this)), errorLayout(new QVBoxLayout(this)) {
    errorLayout->addWidget(text, Qt::AlignCenter);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setModal(true);  // se vuoi bloccare l'interazione con altre finestre
    
    adjustSize();
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

ErrorChanging::ErrorChanging(QWidget* parent) : ErrorStructure(parent), action(new QButtonGroup(this)) { 
    text->setText("Attenzione! Così facendo verranno persi tutti i filtri inseriti. Si è sicuri di voler procedere?");
    //errorLayout->addWidget(text, Qt::AlignCenter);

    QPushButton* confirm = new QPushButton("Conferma ✅", this);
    action->addButton(confirm, 0);

    QPushButton* cancel = new QPushButton("Annulla ❌", this);
    action->addButton(cancel, 1);
    
    QHBoxLayout* actionLayout = new QHBoxLayout();
    foreach(QAbstractButton* button, action->buttons()) actionLayout->addWidget(button, Qt::AlignBottom | Qt::AlignRight);

    errorLayout->addLayout(actionLayout);
    
    connect(action, &QButtonGroup::idClicked, this, &ErrorChanging::changeWidget);

    confirm->setStyleSheet(
            " QPushButton { background-color : #14452F; }"
            " QPushButton::hover { background-color : #039322; }");

    cancel->setStyleSheet("background-color : red;");
}

void ErrorChanging::changeWidget(int id) {
    id == 0 ? emit azione("Conferma") : emit azione("Anulla");
    close();
}

ErrorClosing::ErrorClosing(QWidget* parent) : ErrorStructure(parent), action(new QButtonGroup(this)) { 
    text->setText("Si desidera uscire da QtLibrary?");
    //errorLayout->addWidget(text, Qt::AlignCenter);

    QPushButton* confirm = new QPushButton("Conferma ✅", this);
    action->addButton(confirm, 0);

    QPushButton* cancel = new QPushButton("Annulla ❌", this);
    action->addButton(cancel, 1);
    
    QHBoxLayout* actionLayout = new QHBoxLayout();
    foreach(QAbstractButton* button, action->buttons()) actionLayout->addWidget(button, Qt::AlignBottom | Qt::AlignRight);

    errorLayout->addLayout(actionLayout);
    
    connect(action, &QButtonGroup::idClicked, this, &ErrorClosing::changeWidget);

    confirm->setStyleSheet(
            " QPushButton { background-color : #14452F; }"
            " QPushButton::hover { background-color : #039322; }");

    cancel->setStyleSheet("background-color : red;");
}

void ErrorClosing::changeWidget(int id) {
    id == 0 ? emit azione("Conferma") : emit azione("Anulla");
    close();
}

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
