#include "../../Headers/GUI/viewContents.h"
#include "qglobal.h"

ViewContents::ViewContents(std::vector<Contenuto*> result, QWidget* parent)
    : QWidget(parent), contentsLayout(new QGridLayout()) // non this
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Crea il contenitore centrale e il layout
    QWidget* containerWidget = new QWidget(this);
    containerWidget->setLayout(contentsLayout);

    contentsLayout->setSpacing(10);   // spazio tra i widget
    contentsLayout->setContentsMargins(10, 10, 10, 10);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(containerWidget); // container scrollabile

    // Layout principale per ViewContents
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);

    // Calcolo colonne
    int widgetWidth = 600;
    int containerWidth = parent->width() - 200;
    int colonne = std::max(1, containerWidth / widgetWidth);

    int row = 0, col = 0;

    for (Contenuto* content : result) {
        FilterVisitor visitor;
        content->accept(&visitor);
        ContentViewer* filtro = new ContentViewer(
            QString::fromStdString(content->getNome()),
            QString::fromStdString(visitor.getType()),
            visitor.getFilters());

        filtro->setFixedSize(widgetWidth, 350);

        contentsLayout->addWidget(filtro, row, col);

        ++col;
        if (col >= colonne) {
            col = 0;
            ++row;
        }

        contentsWidgets.push_back(filtro);

        connect(filtro, &ContentViewer::modificaAvviata, this, &ViewContents::bloccaContenuti);
        connect(filtro, &ContentViewer::modificaAnnullata, this, &ViewContents::ripristinaContenuto);
        connect(filtro, &ContentViewer::rimuoviContenuto, this, &ViewContents::eliminaContenuto);
        connect(filtro, &ContentViewer::modificaConfermata, this,
            [this](const int& index, const unordered_map<string, string> original, const unordered_map<string, string>& modifiche) {
                emit modificaOggetto(index, original, modifiche);
                ripristinaContenuto();
            });
    }

    setStyleSheet(R"(
        background-color : #426585;
    )"); 
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

void ViewContents::eliminaContenuto(ContentViewer* contenuto, const int& index,
        const unordered_map<string, string>& attributi) {
   for(std::size_t i = 0; i < contentsWidgets.size(); ++i) {
        if (contenuto == contentsWidgets[i]) {
            contentsLayout->removeWidget(contenuto); 
            emit eliminaOggetto(index, attributi);
            delete contenuto;
            contentsWidgets.erase(contentsWidgets.begin() + i);
            break; 
        }
   }     // Ricostruisci la griglia in modo compatto
    // Prima: rimuovi tutti i widget dal layout
   QLayoutItem* item;
   while ((item = contentsLayout->takeAt(0)) != nullptr) {
       // Non cancelliamo qui i widget: sono ancora in contentsWidgets
       item->widget()->setParent(nullptr); // necessario per evitare che rimangano agganciati
       delete item;
   }
    // Poi: reinserisci i widget nel layout in ordine compatto
   const int columns = 3; // ad esempio, 3 colonne nella griglia
   int row = 0, col = 0;
   for (ContentViewer* w : contentsWidgets) {
       contentsLayout->addWidget(w, row, col);
       if (++col == columns) {
           col = 0;
           ++row;
       }
   }

}

ViewContents::~ViewContents() {
    for(ContentViewer* content : contentsWidgets) delete content;
    contentsWidgets.clear();
}
