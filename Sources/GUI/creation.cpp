#include "../../Headers/GUI/creation.h"
#include "qglobal.h"
#include "qnamespace.h"

Creation::Creation(QWidget* parent, ContentManager* mngr) : MainWidget(parent), manager(mngr), crea(new QPushButton(this)) {
    crea->setFixedSize(50, 50);
    crea->setIcon(QIcon("➕"));
    titleLayout->addWidget(crea);
    pulsantiera->setVisible(true);
    
    mainLayout->setAlignment(Qt::AlignCenter);
    connect(crea, &QPushButton::clicked, this, &Creation::startCreation);

    setLayout(mainLayout);
}

void Creation::mostraFiltro(int id) {
    if(filtri->currentIndex() != id && filtri->isVisible()) {
            ErrorChanging change(this);
            connect(&change, &ErrorChanging::azione, this, [this, id](const QString& choice) {
                if(choice == "Conferma") {
                    qobject_cast<Filters*>(filtri->currentWidget())->reset();
                    filtri->setCurrentIndex(id);
                    qobject_cast<Filters*>(filtri->currentWidget())->setImageButtonVisible();
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
        qobject_cast<Filters*>(filtri->currentWidget())->setImageButtonVisible();
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
       for(const auto&[T, V] : parameters) { qDebug() << QString::fromStdString(T) << " : " << QString::fromStdString(V); }
       if(!checkMap(parameters)) {
           ErrorMissing error(this, "Creazione", titolo->text().toStdString());
           error.exec();
       }

       else {
           CreationVisitor creator(parameters);
           //AGGIUNGERE NON POSSIBILITÀ DI CREARE DUPLICATI
           if(manager->cercaContenuto(filtri->currentIndex(), parameters).size() != 0) {
                    ErrorDuplicate error(this, "Creazione", titolo->text().toStdString());
                    error.exec();
           }
           else {
               manager->creaContenuto(filtri->currentIndex(), &creator);
               qobject_cast<Filters*>(filtri->currentWidget())->reset();
               titolo->clear();
               MessageSuccess success(this, "Creazione", titolo->text().toStdString());
               success.exec();
           }
       }
   }
   else {
       ErrorNoTitle error("Creazione", this);
       error.exec();        
   }
}

Creation::~Creation() {
    manager = nullptr;
}
