#include "../../Headers/GUI/errorChanging.h"

//Trovare il modo che impedisce di chiudere con Esc o altri tasti il widget di errore e fare in modo che non siano visibili i pulsanti di azione

ErrorChanging::ErrorChanging(QWidget* parent) : ErrorStructure(parent), action(new QButtonGroup(this)) { 
    //setWindowTitle("Conferma Scelta");
    //setModal(true);
    text->setText("Attenzione! Così facendo verranno persi tutti i filtri inseriti. Si è sicuri di voler procedere?");
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);
    errorLayout->addWidget(text, Qt::AlignCenter);

    QPushButton* confirm = new QPushButton("Conferma ✅", this);
    action->addButton(confirm, 0);

    QPushButton* cancel = new QPushButton("Annulla ❌", this);
    action->addButton(cancel, 1);
    
    QHBoxLayout* actionLayout = new QHBoxLayout();
    foreach(QAbstractButton* button, action->buttons()) actionLayout->addWidget(button, Qt::AlignBottom | Qt::AlignRight);

    errorLayout->addLayout(actionLayout);
    
    connect(action, &QButtonGroup::idClicked, this, &ErrorChanging::changeWidget);

    confirm->setStyleSheet(
            " QPushButton { background-color : green; }"
            " QPushButton::hover { background-color : #039322; }");

    cancel->setStyleSheet("background-color : red;");
}

void ErrorChanging::changeWidget(int id) {
    id == 0 ? emit azione("Conferma") : emit azione("Anulla");
    close();
}

//Trasformare questa in una classe Base per una gerarchia di 2 classi derivate, 
//una che è questa, cioè per il cambio di widget quando si è in Creation e si cambia 
//widget di Filtro o quando si vuole passare a Ricerca
//l'altra che invece viene usata o quando non viene inserito il titolo in Ricerca
//o quando mancano degli attributi nella creazione di un Contenuto
