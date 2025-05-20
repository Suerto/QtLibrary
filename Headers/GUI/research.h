#ifndef RESEARCH_H
#define RESEARCH_H

#include <QHBoxLayout>

#include "search.h"
#include "viewContents.h"

class Research : public QWidget {
private:
    ContentManager* manager;
    QHBoxLayout* researchLayout;
    Search* searchSection;
    ViewContents* results;
public:
    Research(QWidget* parent = nullptr, ContentManager* mgnr = nullptr);
    ~Research();
public slots:
    void showResults(vector<Contenuto*> res);
};

#endif //RESEARCH_H
