#ifndef VIEW_CONTENTS_H
#define VIEW_CONTENTS_H

#include <QWidget>
#include <QScrollArea>
#include <QGridLayout>

#include "filterVisitor.h"

#include "../LogicModel/contenuto.h"
#include "genericFilters.h"
#include "contentViewer.h"

#include <vector>

using std::vector;

class ViewContents : public QWidget {
    Q_OBJECT
private:
    vector<ContentViewer*> contentsWidgets;
    QGridLayout* contentsLayout;
public:
    ViewContents(vector<Contenuto*> res, QWidget* parent = nullptr);
    //Dovrà sicuramente ricevere un vettore di contenuti per poter creare la
    //griglia, successivamente sarà necessario un visitor che prende i contenuti
    //e crea un Filters adatto ponendo gli attributi esattamente come sono nel contenuto
    //
    //Successivamente dovrò fare in modo che siano in modalità non edit e valutare
    //l'ipotesi di aggiungere
public slots :
    void bloccaContenuti(ContentViewer* contenuto);
    void ripristinaContenuto();
    void eliminaContenuto(ContentViewer* contenuto, const int& index, 
        const unordered_map<string, string>& attributi);
signals:
    void eliminaOggetto(const int& index, const unordered_map<string, string>& attributi);
    void modificaOggetto(const int& index, const unordered_map<string, string>& original, const unordered_map<string, string>& modifiche);
};

#endif //VIEW_CONTENTS_H
