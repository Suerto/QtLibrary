#include "../../Headers/GUI/contentViewer.h"
#include "qglobal.h"
#include "qnamespace.h"

ContentViewer::ContentViewer(DuplicateVerifier* vrfr, const QString& ttl, const QString& tp, Filters* flts, QWidget* parent) : QWidget(parent), verifier(vrfr), picture(new QLabel(this)), title(new QLineEdit(this)), type(new QLineEdit(this)), dettagli(flts), modify(new QPushButton("Modifica", this)), remove(new QPushButton("Elimina", this)), save(new QPushButton("Salva", this)), cancel(new QPushButton("Annulla", this)), mainLayout(new QHBoxLayout()), contentLayout(new QVBoxLayout()), buttonsLayout(new QHBoxLayout()){
    picture->setFixedSize(240, 330);  // Larghezza fissa, altezza come tutto il widget
    picture->setScaledContents(true);
    picture->setPixmap(QPixmap(dettagli->getPathImage()));

    title->setText(ttl);
    title->setAlignment(Qt::AlignCenter);
    title->setReadOnly(true);
   
    type->setText(tp);
    type->setAlignment(Qt::AlignCenter);
    type->setReadOnly(true);

    contentLayout->addWidget(title);
    contentLayout->addWidget(type);
    dettagli->setModifiable(false);
    contentLayout->addWidget(dettagli);

    buttonsLayout->addWidget(remove);
    buttonsLayout->addWidget(modify);

    buttonsLayout->addWidget(cancel);
    buttonsLayout->addWidget(save);

    cancel->setVisible(false);
    save->setVisible(false);

    contentLayout->addLayout(buttonsLayout);
   
    mainLayout->addWidget(picture);
    mainLayout->addLayout(contentLayout);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    dettagli->setModifiable(false);

    dettagli->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setLayout(mainLayout);

    connect(modify, &QPushButton::clicked, this, &ContentViewer::modifica);
    connect(remove, &QPushButton::clicked, this, &ContentViewer::rimuovi);

}

void ContentViewer::rimuovi() {
    IndexVisitor visitor;
    dettagli->accept(&visitor);
    unordered_map<string, string> attributi = dettagli->raccogliDati();
    emit rimuoviContenuto(this, visitor.getIndex(), attributi);
}

void ContentViewer::restoreFilter(const unordered_map<string, string>& attributes) { 
    dettagli->setAttributes(attributes); 
}

void ContentViewer::abilitaPulsantiReadOnly(const bool& rom) {
    remove->setVisible(rom);
    modify->setVisible(rom);

    save->setVisible(!rom);
    cancel->setVisible(!rom);
}

void ContentViewer::modifica() {
    //Viene impedita la modifica a contenuti multipli. Solo quello cliccato viene 
    //possibilmente modificato
    emit modificaAvviata(this);
    
    //Si raccolgono gli attributi, compresa la immagine, ma non viene ancora inserita
    std::unordered_map<string, string> original = dettagli->raccogliDati();
    const string originalImage = dettagli->getPathImage().toStdString();
    qDebug() << "Immagine vecchia : " << QString::fromStdString(originalImage);
    original.insert({"Titolo", title->text().toStdString()});
    dettagli->setModifiable(true);

    abilitaPulsantiReadOnly(false);

    //Se la modifica viene annullata, vengono reimpostati i valori iniziali 
    //(questo serve perché si potrebbero modificare i valori e poi cliccare Annulla)
    connect(cancel, &QPushButton::clicked, this, [&]() {
        dettagli->setModifiable(false);

        emit modificaAnnullata();
        dettagli->setModifiable(false);
        abilitaPulsantiReadOnly(true);
        original.insert({"Anteprima", originalImage});
        restoreFilter(original);
    });
    
    //Viene cliccato il pulsante di salvataggio
    connect(save, &QPushButton::clicked, this, [original, originalImage, this]() {
        //Vengono raccolti gli attributi modificati, tra cui la immagine, ma non viene 
        //ancora inserita
        unordered_map<string, string> modifiche = dettagli->raccogliDati();
        string modifiedImage = dettagli->getPathImage().toStdString();
        modifiche.insert({"Titolo", title->text().toStdString()});
        
        qDebug() << "Seconda stampa di immagine vecchia: " << QString::fromStdString(originalImage);
        qDebug() << "Immagine nuova:" << QString::fromStdString(modifiedImage);
        //si controllano che tutti gli attributi siano stati definiti
        if(!checkMap(modifiche)) {
                ErrorMissing* error = new ErrorMissing(this, "Modifica" , title->text().toStdString());
                error->open();
                emit modificaAnnullata();
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                restoreFilter(original);
                dettagli->setPathImage(QString::fromStdString(originalImage));
        }
        
        //Si controlla se l'utente vuole cambiare SOLO l'immagine
        else if(original == modifiche) {
            qDebug() << QString::fromStdString(originalImage) << " | " << QString::fromStdString(modifiedImage);
            if(originalImage != modifiedImage) {
                qDebug() << "Si vuole modificare l'immagine";
                modifiche.insert({"Anteprima", modifiedImage});
                IndexVisitor visitor;
                dettagli->accept(&visitor);
                MessageSuccess* success = new MessageSuccess(this, "Modifica", title->text().toStdString());
                success->setAttribute(Qt::WA_DeleteOnClose);
                success->open();
                qDebug() << "Modifica confermata";
                emit modificaConfermata(visitor.getIndex(), original, modifiche);
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                restoreFilter(modifiche);
                picture->setPixmap(QPixmap(QString::fromStdString(modifiedImage)));

            }
            
            //Se sono tutti uguali, non viene modificato nulla
            else {
                emit modificaAnnullata();
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                qDebug() << "Nessuna modifica effettuata per mancanza di differenti attributi";
                restoreFilter(original);
                dettagli->setPathImage(QString::fromStdString(originalImage));
            }
        }
        
        //Gli attributi sono differenti. Bisogna controllare che non vi siano duplicati
        else {
            IndexVisitor visitor;
            dettagli->accept(&visitor);
            qDebug() << visitor.getIndex();
            if(verifier->isThereADuplicate(visitor.getIndex(), modifiche)) {
                ErrorDuplicate* error = new ErrorDuplicate(this, "Modifica", title->text().toStdString());
                error->setAttribute(Qt::WA_DeleteOnClose);
                error->open();

                emit modificaAnnullata();
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                restoreFilter(original);
                qDebug() << "Duplicato";
            }    
            
            else {
                MessageSuccess* success = new MessageSuccess(this, "Modifica", title->text().toStdString());
                success->setAttribute(Qt::WA_DeleteOnClose);
                success->open();
                qDebug() << "Modifica confermata";
                emit modificaConfermata(visitor.getIndex(), original, modifiche);
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                restoreFilter(modifiche);
                picture->setPixmap(QPixmap(QString::fromStdString(modifiedImage)));
            }
                
        }
    });
}

void ContentViewer::pulsantiModificaAttivi(const bool& rom) {
    remove->setVisible(rom);
    modify->setVisible(rom);
}

ContentViewer::~ContentViewer() {
    delete dettagli;
    dettagli = nullptr;
    delete buttonsLayout;
    delete contentLayout;
}

bool ContentViewer::checkMap(const unordered_map<string, string>& map) const {
    for(const auto&[T, V] : map) {
        if(V == "Indefinito" || V == "Indefinita" || (V == "0" && T != "Sottotitolato")) {
            return false;
        }
    }
    return true;
}

