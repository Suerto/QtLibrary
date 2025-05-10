#include "../../Headers/GUI/creation.h"
#include "qglobal.h"
#include "qnamespace.h"

Creation::Creation(QWidget* parent, ContentManager* mngr) : MainWidget(parent), manager(mngr), crea(new QPushButton("Avvia Creazione", this)) {
    crea->setFixedSize(50, 50);
    titleLayout->addWidget(crea);
    
    pulsantiera->setVisible(true);
    
    mainLayout->setAlignment(Qt::AlignCenter);
    connect(crea, &QPushButton::clicked, this, &Creation::startCreation);

    setLayout(mainLayout);
}

void Creation::mostraFiltro(int id) {
    //gestione del tentativo di cambio del widget durante la creazione dell'oggetto
    if(filtri->currentIndex() != id && filtri->isVisible()) {
            ErrorChanging change(this);
            connect(&change, &ErrorChanging::azione, this, [this, id](const QString& choice) {
                if(choice == "Conferma") {
                    qobject_cast<Filters*>(filtri->currentWidget())->reset();
                    filtri->setCurrentIndex(id);
                }
                else {
                    tipologia->button(filtri->currentIndex())->click();
                }
            });
            change.exec();
        }
    else {
        filtri->setCurrentIndex(id);
        filtri->setVisible(true);
  }
}

bool Creation::checkMap(const unordered_map<string, string>& map) const {
    for(const auto&[T, V] : map) {
        if(V == "Indefinito" || V == "Indefinita" || V == "0") return false;
    }
    return true;
}

void Creation::startCreation() {
   if(!titolo->text().toStdString().empty()) { 
       unordered_map<string, string> parameters = qobject_cast<Filters*>(filtri->currentWidget())->raccogliDati();
       parameters.insert({"Titolo", titolo->text().toStdString()});
       if(!checkMap(parameters)) {
           ErrorMissing error(this, titolo->text().toStdString());
           error.exec();
       }
       else {
           CreationVisitor creator(parameters);
           manager->creaContenuto(filtri->currentIndex(), &creator);
       }
   }
   else {
       ErrorNoTitle error(this);
       error.exec();        
   }
}
