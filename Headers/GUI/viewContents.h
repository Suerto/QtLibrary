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
    DuplicateVerifier* verifier;
    vector<ContentViewer*> contentsWidgets;
    QGridLayout* contentsLayout;
public:
    ViewContents(DuplicateVerifier* vrfr, vector<Contenuto*> res, QWidget* parent = nullptr);
    ~ViewContents();
public slots :
    void bloccaContenuti(ContentViewer* contenuto);
    void ripristinaContenuto();
    void eliminaContenuto(ContentViewer* contenuto, const int& index, 
        const unordered_map<string, string>& attributi);
signals:
    void eliminaOggetto(const int& index, const unordered_map<string, string>& attributi);
    void modificaOggetto(const int& index, const unordered_map<string, string>& original, 
            const unordered_map<string, string>& modifiche);
};

#endif //VIEW_CONTENTS_H
