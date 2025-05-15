#include "../../Headers/GUI/contentViewer.h"
#include "qglobal.h"

ContentViewer::ContentViewer(const QString& ttl, const QString& tp, Filters* flts, QWidget* parent) : QWidget(parent), title(new QLineEdit(this)), type(new QLineEdit(this)), dettagli(flts), modify(new QPushButton("Modifica", this)), remove(new QPushButton("Elimina", this)), save(new QPushButton("Salva", this)), cancel(new QPushButton("Annulla", this)), contentLayout(new QVBoxLayout()), buttonsLayout(new QHBoxLayout()){
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
    
    dettagli->setModifiable(false);
    dettagli->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    setLayout(contentLayout);

    connect(modify, &QPushButton::clicked, this, &ContentViewer::modifica);
    connect(remove, &QPushButton::clicked, this, &ContentViewer::rimuovi);
}

void ContentViewer::rimuovi() {
    qDebug() << "Ingresso in ContentViewer::rimuovi() avvenuta";
    IndexVisitor visitor;
    qDebug() << "\nCreazione del visitor IndexVisitor avvenuta : " << static_cast<void*>(&visitor); 
    dettagli->accept(&visitor);
    qDebug() << "\nAccept del visitor avvenuta. Indice trovato : " << visitor.getIndex();
    unordered_map<string, string> attributi = dettagli->raccogliDati();
    qDebug() << "\nEmit di rimuoviContenuto avvenuta";
    emit rimuoviContenuto(this, visitor.getIndex(), attributi);
    qDebug() << "Ritorno da rimuoviContenuto() avvenuto. Problema risolto";
}

void ContentViewer::restoreFilter(const unordered_map<string, string>& attributes) { dettagli->setAttributes(attributes); }

void ContentViewer::abilitaPulsantiReadOnly(const bool& rom) {
    remove->setVisible(rom);
    modify->setVisible(rom);

    save->setVisible(!rom);
    cancel->setVisible(!rom);
}

void ContentViewer::modifica() {
    emit modificaAvviata(this);

    qDebug() << QString::fromStdString("Siamo nella modifica");
    std::unordered_map<string, string> original = dettagli->raccogliDati();

    dettagli->setModifiable(true);

    abilitaPulsantiReadOnly(false);
    connect(cancel, &QPushButton::clicked, this, [original, this]() {
            dettagli->setModifiable(false);

            emit modificaAnnullata();
            dettagli->setModifiable(false);
            abilitaPulsantiReadOnly(true);
            restoreFilter(original);
            });

    connect(save, &QPushButton::clicked, this, [original, this]() {
            qDebug() << "Siamo nella connect del save";
            unordered_map<string, string> modifiche = dettagli->raccogliDati();
            modifiche.insert({"Titolo", title->text().toStdString()});
            if(!checkMap(modifiche)) {
            ErrorMissing error(this, "Modifica " , title->text().toStdString());
            error.exec();
            }

            else {
            IndexVisitor visitor;

            dettagli->accept(&visitor);
            emit modificaConfermata(visitor.getIndex(), original, modifiche);
            dettagli->setModifiable(false);
            abilitaPulsantiReadOnly(true);
            }
            restoreFilter(modifiche); 
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
        if(V == "Indefinito" || V == "Indefinita" || V == "0") {
            return false;
            break;
        }
    }
    return true;
}
