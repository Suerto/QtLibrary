#include "../../Headers/GUI/creation.h"

Creation::Creation(QWidget* parent, ContentManager* mngr) :
                   MainWidget(parent), manager(mngr), crea(new QPushButton(this)) {
    crea->setFixedSize(50, 50);
    crea->setIcon(QIcon("Data/Icone/creazione.png"));
    crea->setIconSize(QSize(25, 25));
    titolo->text().isEmpty() ? crea->setToolTip("Inserire un titolo valido per la creazione") : crea->setToolTip("Clicca qui per avviare la creazione");
    titleLayout->addWidget(crea);
    pulsantiera->setVisible(true);
    
    mainLayout->setAlignment(Qt::AlignCenter);
    connect(crea, &QPushButton::clicked, this, &Creation::startCreation);

    setLayout(mainLayout);
    
    crea->setStyleSheet(R"(
    QPushButton {
        border: 1px solid gray;
        padding: 5px;
        background-color: white;
        border-radius: 6px;
    }

    QPushButton:hover {
        background-color: #e6f0ff;
    }
)");
}

void Creation::mostraFiltro(int id) {
    if(filtri->currentIndex() != id && filtri->isVisible()) {
            ErrorChanging change(this);
            connect(&change, &ErrorChanging::azione, this, [this, id](const QString& choice) {
                if(choice == "Conferma") {
                    qobject_cast<Filters*>(filtri->currentWidget())->reset();
                    filtri->setCurrentIndex(id);
                    qobject_cast<Filters*>(filtri->currentWidget())->setImageButtonVisible(true);
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
        qobject_cast<Filters*>(filtri->currentWidget())->setImageButtonVisible(true);
    }
}

bool Creation::checkMap(const unordered_map<string, string>& map) const {
    for(const auto&[T, V] : map) {
        if(V == "Indefinito" || V == "Indefinita" || (V == "0" && T != "Sottotitolato")) return false;
    }
    return true;
}

void Creation::startCreation() {
   if(!titolo->text().toStdString().empty()) { 
       unordered_map<string, string> parameters = 
           qobject_cast<Filters*>(filtri->currentWidget())->raccogliDati();
       
       parameters.insert({"Titolo", titolo->text().toStdString()});
       if(!checkMap(parameters)) {
           ErrorMissing error(this, "Creazione", titolo->text().toStdString());
           error.exec();
       }

       else {
           parameters.insert({"Anteprima",
            qobject_cast<Filters*>(filtri->currentWidget())->getPathImage().toStdString()});
           CreationVisitor creator(parameters);
           //AGGIUNGERE NON POSSIBILITÀ DI CREARE DUPLICATI
           
           if(manager->controllaDuplicato(filtri->currentIndex(), parameters)) {
                    ErrorDuplicate error(this, "Creazione", titolo->text().toStdString());
                    error.exec();
           }
           else {
               qDebug() << static_cast<void*>(manager); 
               manager->creaContenuto(filtri->currentIndex(), &creator);
               MessageSuccess success(this, "Creazione", titolo->text().toStdString());
               success.exec();
               qobject_cast<Filters*>(filtri->currentWidget())->reset();
               titolo->clear();
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
