#ifndef CONTENT_VIEWER_H
#define CONTENT_VIEWER_H

#include <QLineEdit>
#include <QPushButton>

#include "genericFilters.h"
#include "qpushbutton.h"


class ContentViewer : public QWidget {
    Q_OBJECT
private:
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
    ContentViewer(const QString& ttl, const QString& tp, Filters* flts = nullptr, QWidget* parent = nullptr);
    void disabilitaPulsanti(const bool& setting);
public slots:
    void modifica();
signals:
    void rimuoviContent(ContentViewer* contenuto);
    void modificaAvviata(ContentViewer* modified);
    void modificaAnnullata();
};

#endif //CONTENT_VIEWER_H
