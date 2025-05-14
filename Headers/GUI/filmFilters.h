#ifndef FILMFILTERS_H
#define FILMFILTERS_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>

#include "genericFilters.h"

class FilmFilters : public Filters {
private:
    QComboBox* resolution;
    QSpinBox* duration;
    
    QLineEdit* director;
    QLineEdit* composer;
    QLineEdit* producer;
    QComboBox* genre;
public:
    FilmFilters(QWidget* parent = nullptr);
    virtual void reset() override;
    virtual unordered_map<string, string> raccogliDati() const override;

    void setResolution(const QString& rslt);
    void setDuration(const unsigned int& drtn);

    void setDirector(const QString& drct);
    void setComposer(const QString& cmps);
    void setProducer(const QString& prdc);
    void setGenre(const QString& gnr);

    virtual void setModifiable(const bool& mdf) override;
    virtual void setAttributes(const unordered_map<string, string>& attributes) override;
    virtual void accept(GuiVisitor* visitor) const override;
};

#endif //FILMFILTERS_H
