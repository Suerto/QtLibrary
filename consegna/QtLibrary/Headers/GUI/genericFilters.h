#ifndef GENERIC_H
#define GENERIC_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>
//Per la gestione d'accesso alla cartella Data/Immagini
#include <QDir>
#include <QCoreApplication>
#include <QFileDialog>

#include <unordered_map>

#include "guiVisitor.h"

#include "../../Sources/JSON/JsonHandler.hpp"

using std::unordered_map;

class Filters : public QWidget {
    Q_OBJECT
protected:
    QString pathImmagine;
    QComboBox* language;
    QSpinBox* year;
    QPushButton* coverImage;
    QFormLayout* filtersLayout;
public:
    Filters(QWidget* parent = nullptr);
    void setLanguage(const QString& lng);
    void setYear(const unsigned int& yr);
    void setPathImage(const QString& path);
    void setImageButtonVisible(const bool& vsbl);
    QString getPathImage() const;

    virtual void reset();
    virtual void setModifiable(const bool& mdf);
    virtual void setAttributes(const unordered_map<string, string>& attributes);

    virtual unordered_map<string, string> raccogliDati() const = 0;
    virtual ~Filters();
    virtual void accept(GuiVisitor* visitor) const = 0;
signals:
    void AnteprimaInviata(const QString& path);
};

#endif //GENERIC_H
