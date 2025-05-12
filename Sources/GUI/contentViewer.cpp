#include "../../Headers/GUI/contentViewer.h"
#include "qglobal.h"

ContentViewer::ContentViewer(const QString& ttl, const QString& tp, Filters* flts, Contenuto* obj, QWidget* parent) : QWidget(parent),  object(obj), title(new QLineEdit(this)), type(new QLineEdit(this)), dettagli(flts), modify(new QPushButton("Modifica", this)), remove(new QPushButton("Elimina", this)), save(new QPushButton("Salva", this)), cancel(new QPushButton("Annulla", this)), contentLayout(new QVBoxLayout()), buttonsLayout(new QHBoxLayout()) {
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
    emit rimuoviContenuto(this);
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
    std::unordered_map<string, string> tmp = dettagli->raccogliDati();

    dettagli->setModifiable(true);
    
    abilitaPulsantiReadOnly(false);
    connect(cancel, &QPushButton::clicked, this, [tmp, this]() {
        dettagli->setModifiable(false);

        emit modificaAnnullata();
        dettagli->setModifiable(false);
        abilitaPulsantiReadOnly(true);
        restoreFilter(tmp);
        });
    
    connect(save, &QPushButton::clicked, this, [this]() {
            qDebug() << "Siamo nella connect del save";
            unordered_map<string, string> modifiche = dettagli->raccogliDati();
            modifiche.insert({"Titolo", title->text().toStdString()});
            CreationVisitor visitor(modifiche);
            qDebug() << "Abbiamo raccolto i dati"; 

            for(const auto&[T, V] : dettagli->raccogliDati()) {
                qDebug() << QString::fromStdString(T) << " " << QString::fromStdString(V); 
            }
            qDebug() << "Indirizzo oggetto : " << static_cast<void*>(object);
            object->accept(&visitor);
            dettagli->setModifiable(false);
            abilitaPulsantiReadOnly(true);
            restoreFilter(modifiche);
        });
    }
void ContentViewer::pulsantiModificaAttivi(const bool& rom) {
    remove->setVisible(rom);
    modify->setVisible(rom);
}

ContentViewer::~ContentViewer() {
    delete dettagli;
}

Contenuto* ContentViewer::getObject() const { return object; }
