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
    emit modificaAvviata(this);
    
    unordered_map<string, string> original = dettagli->raccogliDati();
    const string originalImage = dettagli->getPathImage().toStdString();
    qDebug() << "Immagine vecchia : " << QString::fromStdString(originalImage);
    original.insert({"Titolo", title->text().toStdString()});
    dettagli->setModifiable(true);
    abilitaPulsantiReadOnly(false);

    connect(cancel, &QPushButton::clicked, this, [original, originalImage, this]() {
        dettagli->setModifiable(false);
        emit modificaAnnullata();
        dettagli->setModifiable(false);
        abilitaPulsantiReadOnly(true);
        restoreFilter(original);
        dettagli->setPathImage(QString::fromStdString(originalImage));
    });
    
    connect(save, &QPushButton::clicked, this, [original, originalImage, this]() {
        unordered_map<string, string> modifiche = dettagli->raccogliDati();
        string modifiedImage = dettagli->getPathImage().toStdString();
        modifiche.insert({"Titolo", title->text().toStdString()});

        if(!checkMap(modifiche)) {
                ErrorMissing error(this, "Modifica" , title->text().toStdString());
                error.open();
                emit modificaAnnullata();
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                restoreFilter(original);
                dettagli->setPathImage(QString::fromStdString(originalImage));
        }
        
        else if(original == modifiche) {
            if(originalImage != modifiedImage) {
                IndexVisitor visitor;
                dettagli->accept(&visitor);
                MessageSuccess* success = new MessageSuccess(this, "Modifica", title->text().toStdString());
                success->setAttribute(Qt::WA_DeleteOnClose);
                success->open();
                modifiche.insert({"Anteprima", modifiedImage});
                emit modificaConfermata(visitor.getIndex(), original, modifiche);
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                restoreFilter(modifiche);
                dettagli->setPathImage(QString::fromStdString(modifiedImage));
                picture->setPixmap(QPixmap(QString::fromStdString(modifiedImage)));
            }
            
            else {
                emit modificaAnnullata();
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                restoreFilter(original);
                dettagli->setPathImage(QString::fromStdString(originalImage));
            }
        }
        
        else {
            IndexVisitor visitor;
            dettagli->accept(&visitor);
            qDebug() << visitor.getIndex();
            if(verifier->isThereADuplicate(visitor.getIndex(), modifiche)) {
                ErrorDuplicate error(this, "Modifica", title->text().toStdString());
                error.setAttribute(Qt::WA_DeleteOnClose);
                error.open();

                emit modificaAnnullata();
                dettagli->setModifiable(false);
                abilitaPulsantiReadOnly(true);
                restoreFilter(original);
            }    
            
            else {
                MessageSuccess success(this, "Modifica", title->text().toStdString());
                success.setAttribute(Qt::WA_DeleteOnClose);
                success.open();
                modifiche.insert({"Anteprima", modifiedImage});
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


bool ContentViewer::checkMap(const unordered_map<string, string>& map) const {
    for(const auto&[T, V] : map) {
        if(V == "Indefinito" || V == "Indefinita" || (V == "0" && T != "Sottotitolato")) {
            return false;
        }
    }
    return true;
}

ContentViewer::~ContentViewer() {
    delete dettagli;
    dettagli = nullptr;
    delete buttonsLayout;
    delete contentLayout;
}
