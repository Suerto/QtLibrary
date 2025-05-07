#include "../../Headers/GUI/viewContents.h"
#include "qglobal.h"

ViewContents::ViewContents(vector<Contenuto*> result, QWidget* parent) : QWidget(parent), contentsWidgets(), contentsLayout(new QGridLayout(this)) {
    for(Contenuto* content : result) {
        FilterVisitor visitor;
        content->accept(&visitor);
        Filters* filtro = visitor.getFilters();
        qDebug() << "Filtro creato : " << static_cast<void*>(filtro);
        contentsWidgets.push_back(filtro);
        qDebug() << contentsWidgets.size();
        contentsLayout->addWidget(filtro);
    }
    setLayout(contentsLayout);
}
