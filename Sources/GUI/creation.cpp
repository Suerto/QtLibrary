#include "../../Headers/GUI/creation.h"

Creation::Creation(QWidget* parent, ContentManager* mngr) : MainWidget(parent), manager(mngr), crea(new QPushButton("Avvia Creazione", this)) {
    crea->setFixedSize(50, 50);
    titleLayout->addWidget(crea);
    
    pulsantiera->setVisible(true);

    connect(crea, &QPushButton::clicked, this, &Creation::startCreation);
}

void Creation::mostraFiltro(int id) {
    //gestione del tentativo di cambio del widget durante la creazione dell'oggetto
    if(filtri->currentIndex() != id && filtri->isVisible()) {
            ErrorDialog* change = new ErrorDialog(this);
            connect(change, &ErrorDialog::azione, this, [this, id](const QString& choice) {
                if(choice == "Conferma") {
                    qobject_cast<Filters*>(filtri->currentWidget())->reset();
                    filtri->setCurrentIndex(id);
                }
                else {
                    tipologia->button(filtri->currentIndex())->click();
                }
            });
            change->exec();
        }
    else {
        filtri->setCurrentIndex(id);
        filtri->setVisible(true);
  }
}

void Creation::startCreation() {
   unordered_map<string, string> parameters = qobject_cast<Filters*>(filtri->currentWidget())->raccogliDati();
   parameters.insert({"Titolo", titolo->text().toStdString()}); 
   
   CreationVisitor* visitor = new CreationVisitor(parameters);
    
   manager->creaContenuto(filtri->currentIndex(), visitor);
}
