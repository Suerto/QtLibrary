#include "../../Headers/GUI/contentViewer.h"

ContentViewer::ContentViewer(const QString& ttl, const QString& tp, Filters* flts, QWidget* parent) : QWidget(parent), title(new QLineEdit(this)), type(new QLineEdit(this)), dettagli(flts), modify(new QPushButton("Modifica", this)), remove(new QPushButton("Elimina", this)), save(new QPushButton("Salva", this)), cancel(new QPushButton("Annulla", this)), contentLayout(new QVBoxLayout(this)), buttonsLayout(new QHBoxLayout()) {
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
    setLayout(contentLayout);

    connect(modify, &QPushButton::clicked, this, &ContentViewer::modifica);

    //connect(remove, &QPushButton::clicked, this, &)
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
    }

void ContentViewer::pulsantiModificaAttivi(const bool& rom) {
    remove->setVisible(rom);
    modify->setVisible(rom);
}
