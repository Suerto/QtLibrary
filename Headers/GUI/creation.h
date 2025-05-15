#ifndef CREATION_H
#define CREATION_H

#include "mainWidgets.h"

class Creation : public MainWidget {
    Q_OBJECT 
private:
    ContentManager* manager;
    QPushButton* crea;
public:
    Creation(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
    bool checkMap(const std::unordered_map<string, string>& map) const;
    virtual ~Creation() override;
public slots:
    void startCreation();
    void mostraFiltro(int id) override;
};

#endif //CREATION_H
