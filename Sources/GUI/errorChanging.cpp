#include "../../Headers/GUI/errorChanging.h"

ErrorChanging::ErrorChanging(QWidget* parent) : ErrorStructure(parent), action(new QButtonGroup(this)) { 
    text->setText("Attenzione! Così facendo verranno persi tutti i filtri inseriti. Si è sicuri di voler procedere?");
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
            " QPushButton { background-color : #14452F; }"
            " QPushButton::hover { background-color : #039322; }");

    cancel->setStyleSheet("background-color : red;");
}

void ErrorChanging::changeWidget(int id) {
    id == 0 ? emit azione("Conferma") : emit azione("Anulla");
    close();
}
