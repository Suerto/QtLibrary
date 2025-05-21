#ifndef CREATION_H
#define CREATION_H

#include "mainWidgets.h"
#include "errorDuplicate.h"
#include "messageSuccess.h"

class Creation : public MainWidget {
    Q_OBJECT 
private:
    ContentManager* manager;
    QPushButton* crea; 
public:
    Creation(QWidget* parent = nullptr, ContentManager* mngr = nullptr);
    bool checkMap(const std::unordered_map<string, string>& map) const;
    virtual ~Creation() override;
    Filters* getFilter();
public slots:
    void startCreation();
    void mostraFiltro(int id) override;
signals:
    void mostraPulsanteVetrina();
};

#endif //CREATION_H
