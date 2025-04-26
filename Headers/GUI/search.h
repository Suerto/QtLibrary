#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

#include "advancedSearch.h"

#include "../LogicModel/contentManager.h"
class Search : public QWidget {
    Q_OBJECT    
private:
    ContentManager* manager;

    QLineEdit* searchBar;
    QPushButton* searchButton;
    QCheckBox* advancedResearchButton;
    AdvancedResearch* advancedSearch;
    QVBoxLayout* searchLayout;
    QHBoxLayout* simpleSearchLayout;
    QLabel* titleError;
public:
    Search(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
private slots:
    void advancedResearch(bool checked);
    void startSearch();
    void advanced(const int& index, const std::unordered_map<string, string>& attributi) const;
};

#endif //SEARCH_H
