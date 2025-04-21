#include "../../Headers/GUI/errorDialog.h"
#include "qnamespace.h"

ErrorDialog::ErrorDialog(QWidget* parent) : QDialog(parent), text(new QLabel("Attenzione! Così facendo verranno persi tutti i criteri inseriti finora. Vuoi davvero continuare?", this)), errorLayout(new QVBoxLayout(this)), action(new QButtonGroup(this)) { 
    setWindowTitle("Conferma Scelta");
    errorLayout->addWidget(text, Qt::AlignCenter);

    QPushButton* confirm = new QPushButton("Conferma", this);
    action->addButton(confirm, 0);

    QPushButton* cancel = new QPushButton("Annulla", this);
    action->addButton(cancel, 1);
    
    QHBoxLayout* actionLayout = new QHBoxLayout();
    foreach(QAbstractButton* button, action->buttons()) actionLayout->addWidget(button, Qt::AlignBottom | Qt::AlignRight);

    errorLayout->addLayout(actionLayout);
    
    connect(action, &QButtonGroup::idClicked, this, &ErrorDialog::changeWidget);

    //setLayout(errorLayout);
}

void ErrorDialog::changeWidget(int id) {
    id == 0 ? emit azione("Conferma") : emit azione("Anulla");
    close();
}
