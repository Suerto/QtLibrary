#include "../../Headers/GUI/errorClosing.h"

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
