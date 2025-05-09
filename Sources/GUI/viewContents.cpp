#include "../../Headers/GUI/viewContents.h"
#include "qglobal.h"

ViewContents::ViewContents(std::vector<Contenuto*> result, QWidget* parent) : QWidget(parent), risultati(), contentsLayout(new QGridLayout(this)) {
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed); // Larghezza espandibile, altezza fissa

    int widgetWidth = 300;
    int containerWidth = parent->width() - 400;  // Ottieni larghezza disponibile
    int colonne = std::max(1, containerWidth / widgetWidth);  // Calcola quante colonne
    contentsLayout->setSpacing(5);
    int col = 0, row = 0;
    for (Contenuto* content : result) {
        FilterVisitor visitor;
        content->accept(&visitor);
        ContentViewer* filtro = new ContentViewer(QString::fromStdString(content->getNome()), QString::fromStdString(visitor.getType()), visitor.getFilters());
        filtro->setFixedSize(widgetWidth, 300);  // Imposta la dimensione fissa del filtro
        contentsLayout->addWidget(filtro, row, col);
        ++col;
        if (col >= colonne) {
            col = 0;
            ++row;
        }
        risultati.push_back(filtro);

        connect(filtro, &ContentViewer::modificaAvviata, this, &ViewContents::setUnmodifiable);
        connect(filtro, &ContentViewer::modificaAnnullata, this, &ViewContents::setModifiable);
    }
    setLayout(contentsLayout);

}

void ViewContents::setUnmodifiable(ContentViewer* modified) { 
    for(ContentViewer* content : risultati) {
        if(content != modified) {
            content->disabilitaPulsanti(true);
        }
    }
}

void ViewContents::setModifiable() {
    for(ContentViewer* content : risultati) {
        content->disabilitaPulsanti(false);
    }
}
