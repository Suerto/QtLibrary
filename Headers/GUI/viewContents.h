#ifndef VIEW_CONTENTS_H
#define VIEW_CONTENTS_H

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>

#include "filterVisitor.h"
#include "contentViewer.h"

#include "../LogicModel/contenuto.h"

#include <vector>

using std::vector;

class ViewContents : public QWidget {
    Q_OBJECT
private:
    vector<ContentViewer*> risultati;
    QGridLayout* contentsLayout;
public:
    ViewContents(vector<Contenuto*> res, QWidget* parent = nullptr);
    //Dovrà sicuramente ricevere un vettore di contenuti per poter creare la
    //griglia, successivamente sarà necessario un visitor che prende i contenuti
    //e crea un Filters adatto ponendo gli attributi esattamente come sono nel contenuto
    //
    //Successivamente dovrò fare in modo che siano in modalità non edit e valutare
    //l'ipotesi di aggiungere
public slots:
    void setUnmodifiable(ContentViewer* modified);
    void setModifiable();
};

#endif //VIEW_CONTENTS_H
