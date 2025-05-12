#ifndef CONTENT_VIEWER_H
#define CONTENT_VIEWER_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "genericFilters.h"
#include "../LogicModel/creationVisitor.h"
#include "../LogicModel/contenuto.h"


class ContentViewer : public QWidget {
    Q_OBJECT 
private:
    Contenuto* object;

    QLineEdit* title;
    QLineEdit* type;
    Filters* dettagli;
    
    QPushButton* modify;
    QPushButton* remove;
    QPushButton* save;
    QPushButton* cancel;

    QVBoxLayout* contentLayout;
    QHBoxLayout* buttonsLayout;
public:
    ContentViewer(const QString& ttl, const QString& tp, Filters* flts, Contenuto* obj, QWidget* parent = nullptr);
    void abilitaPulsantiReadOnly(const bool& rom);

    void pulsantiModificaAttivi(const bool& rom);

    void restoreFilter(const std::unordered_map<string, string>& attributes);

    Contenuto* getObject() const;
    ~ContentViewer();
public slots:
    void rimuovi();
    void modifica();
signals:
    void modificaAvviata(ContentViewer* contenuto);
    void modificaAnnullata();
    void rimuoviContenuto(ContentViewer* contenuto);
    void modificaContenuto(const unordered_map<string, string>& modifiche);
};
#endif //CONTENT_VIEWER_H
