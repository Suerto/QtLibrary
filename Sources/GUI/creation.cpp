#include "../../Headers/GUI/creation.h"

Creation::Creation(QWidget* parent, ContentManager* mngr) : MainWidget(parent), manager(mngr), crea(new QPushButton("Avvia Creazione", this)) {
    crea->setFixedSize(50, 50);
    titleLayout->addWidget(crea);
    
    pulsantiera->setVisible(true);

    connect(crea, &QPushButton::clicked, this, &Creation::startCreation);
}

void Creation::startCreation() {
   unordered_map<string, string> parameters = qobject_cast<Filters*>(filtri->currentWidget())->raccogliDati();
   parameters.insert({"Titolo", titolo->text().toStdString()}); 
    
   CreationVisitor* visitor = new CreationVisitor(parameters);
}
