#ifndef ANIMEFILTERS_H
#define ANIMEFILTERS_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>

#include "genericFilters.h"
#include "qpixelformat.h"

class AnimeFilters : public Filters {
private:
    QComboBox* resolution;
    QSpinBox* duration;
 
    QLineEdit* producer;
    QSpinBox* episodes;
    QSpinBox* seasons;
    QCheckBox* subtitled;
    QComboBox* genre;
    QComboBox* cadence;
public:
    AnimeFilters(QWidget* parent = nullptr);
    virtual void reset() override;
    virtual unordered_map<string, string> raccogliDati() const override;

    void setResolution(const QString& rslt);
    void setDuration(const unsigned int& drtn);

    void setProducer(const QString& prdc);
    void setEpisodes(const unsigned int& epsd);
    void setSeasons(const unsigned int& ssns);
    void setSubtitle(const bool& sbtd);
    void setGenre(const QString& gnr);
    void setCadence(const QString& cdnc);

    virtual void setModifiable(const bool& mdf) override;
};

#endif //ANIMEFILTERS_H
