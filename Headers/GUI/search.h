#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>

#include "advancedSearch.h"
#include "qboxlayout.h"

class Search : public QWidget {
    Q_OBJECT
private:
    QLineEdit* searchBar;
    QPushButton* searchButton;
    QCheckBox* advancedResearchButton;
    AdvancedResearch* advancedSearch;
protected:
    QVBoxLayout* searchLayout;
private:
    QHBoxLayout* simpleSearchLayout;
public:
    Search(QWidget* parent = nullptr);
private slots:
    void advancedResearch(bool checked);
};

#endif //SEARCH_H
