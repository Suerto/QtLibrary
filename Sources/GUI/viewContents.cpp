#include "../../Headers/GUI/viewContents.h"

ViewContents::ViewContents(std::vector<Contenuto*> result, QWidget* parent) : QWidget(parent), contentsLayout(new QGridLayout(this)) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Larghezza espandibile, altezza fissa

    int widgetWidth = 350;
    int containerWidth = parent->width() - 400;  // Ottieni larghezza disponibile
    int colonne = std::max(1, containerWidth / widgetWidth);  // Calcola quante colonne
    contentsLayout->setSpacing(5);
    int col = 0, row = 0;
    for (Contenuto* content : result) {
        FilterVisitor visitor;
        content->accept(&visitor);
        ContentViewer* filtro = new ContentViewer(QString::fromStdString(content->getNome()), QString::fromStdString(visitor.getType()), visitor.getFilters());
        
        filtro->setFixedSize(widgetWidth, 350);  // Imposta la dimensione fissa del filtro
        contentsLayout->addWidget(filtro, row, col);
        ++col;
        if (col >= colonne) {
            col = 0;
            ++row;
        }
        
        contentsWidgets.push_back(filtro);
        connect(filtro, &ContentViewer::modificaAvviata, this, &ViewContents::bloccaContenuti);
        connect(filtro, &ContentViewer::modificaAnnullata, this, &ViewContents::ripristinaContenuto);
    }
    setLayout(contentsLayout);
}

void ViewContents::bloccaContenuti(ContentViewer* contenuto) {
    for(ContentViewer* content : contentsWidgets) {
        if(contenuto != content) {
            content->pulsantiModificaAttivi(false);
        }
    }
}

void ViewContents::ripristinaContenuto() {
    for(ContentViewer* content : contentsWidgets) {
        content->pulsantiModificaAttivi(true);
    }
}
