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

    setLayout(contentLayout);

    connect(modify, &QPushButton::clicked, this, &ContentViewer::modifica);

    //connect(remove, &QPushButton::clicked, this, &)
}

void ContentViewer::modifica() {
    emit modificaAvviata(this);
    
    dettagli->setModifiable(true);
    
    disabilitaPulsanti(true);

    cancel->setVisible(true);
    save->setVisible(true);

    connect(cancel, &QPushButton::clicked, this, [this]() {
                dettagli->setModifiable(false);
                
                cancel->setVisible(false);
                save->setVisible(false);
                
                remove->setVisible(true);
                modify->setVisible(true);
                
                emit modificaAnnullata();
               });
}

void ContentViewer::disabilitaPulsanti(const bool& setting) {  
    remove->setVisible(!setting);
    modify->setVisible(!setting);
}
