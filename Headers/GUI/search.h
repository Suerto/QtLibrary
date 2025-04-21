#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

#include "advancedSearch.h"

class Search : public QWidget {
    Q_OBJECT    
private:
    QLineEdit* searchBar;
    QPushButton* searchButton;
    QCheckBox* advancedResearchButton;
    AdvancedResearch* advancedSearch;
    QVBoxLayout* searchLayout;
    QHBoxLayout* simpleSearchLayout;
    QLabel* titleError;
public:
    Search(QWidget* parent = nullptr);
private slots:
    void advancedResearch(bool checked);
    void startSearch();
};

#endif //SEARCH_H
