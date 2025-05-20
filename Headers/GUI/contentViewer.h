#ifndef CONTENT_VIEWER_H
#define CONTENT_VIEWER_H

#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "duplicateVerifier.h"
#include "genericFilters.h"
#include "errorMissing.h"
#include "indexVisitor.h"

class ContentViewer : public QWidget {
    Q_OBJECT 
private:
    DuplicateVerifier* verifier;
    QLabel* picture;
    QLineEdit* title;
    QLineEdit* type;
    Filters* dettagli;
    
    QPushButton* modify;
    QPushButton* remove;
    QPushButton* save;
    QPushButton* cancel;
    
    QHBoxLayout* mainLayout;
    QVBoxLayout* contentLayout;
    QHBoxLayout* buttonsLayout;
public:
    ContentViewer(const QString& ttl, const QString& tp, Filters* flts, 
                  QWidget* parent = nullptr);
    void abilitaPulsantiReadOnly(const bool& rom);

    void pulsantiModificaAttivi(const bool& rom);

    void restoreFilter(const std::unordered_map<string, string>& attributes);
    Filters* getFilter() const;

    bool checkMap(const unordered_map<string, string>& map) const;
    ~ContentViewer();
public slots:
    void rimuovi();
    void modifica();
signals:
    void modificaAvviata(ContentViewer* contenuto);
    void modificaAnnullata();
    void rimuoviContenuto(ContentViewer* contenuto, const int& index, 
            const unordered_map<string, string>& attributi);
    void modificaConfermata(const int& index, 
            const unordered_map<string, string>& original, const unordered_map<string, 
            string>& modifiche);
};
#endif //CONTENT_VIEWER_H
