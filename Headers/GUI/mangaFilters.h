#ifndef MANGAFILTERS_H
#define MANGAFILTERS_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>

#include "genericFilters.h"

class MangaFilters : public Filters {
private:
    QComboBox* cover;
    QComboBox* cadence;
    QLineEdit* mangaka;
    QLineEdit* editor;
    QSpinBox* pages;
    QSpinBox* chapters;
    QComboBox* genre;
public: 
    MangaFilters(QWidget* parent = nullptr);
    virtual void reset() override;
    virtual unordered_map<string, string> raccogliDati() const override;

    void setCover(const QString& cvr);
    void setPages(const unsigned int& pgs);

    void setCadence(const QString& cdnc);
    
    void setMangaka(const QString& mngk);
    void setEditor(const QString& edtr);
    void setChapters(const unsigned int& chpt);
    void setGenre(const QString& gnr);

    virtual void setModifiable(const bool& mdf) override;
    virtual void setAttributes(const unordered_map<string, string>& attributes)
                                override;
    virtual void accept(GuiVisitor* visitor) const override;
};

#endif //MANGAFILTERS_H
