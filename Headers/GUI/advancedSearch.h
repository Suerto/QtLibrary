#ifndef ADVANCED_H
#define ADVANCED_H

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QHBoxLayout>
#include <QStackedWidget>

#include "mangaFilters.h"
#include "bookFilters.h"
#include "filmFilters.h"
#include "animeFilters.h"

class AdvancedResearch : public QWidget {
    friend class Search;
private:
    QVBoxLayout* advancedLayout;
    QHBoxLayout* buttonsLayout;
    QButtonGroup* types;
    QStackedWidget* filter;
public:
    AdvancedResearch(QWidget* parent = nullptr);
public slots :
    void showFilters(int id);
    void ottieniMappaAttributi(const int& index, const std::unordered_map<string, string>& attributi);
signals:
    void datiRaccolti(const int& index, const std::unordered_map<string, string>& attributi) const; 
};

#endif //ADVANCED_H
