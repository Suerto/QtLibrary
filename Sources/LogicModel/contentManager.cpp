#include "../../Headers/LogicModel/contentManager.h"
#include "qglobal.h"

#include <QDebug>

ContentManager::ContentManager() : contenuti() {}

void ContentManager::creaContenuto(const int& index, const Visitors* visitor) {
    bool visit = 0;
    if(visitor != nullptr) visit = 1;
    qDebug() << "Indice passato? : " << index << ", Visitor Passato? " << visit << "\n";
    Contenuto* contenuto = nullptr;
    switch(index) {
        case 0 : contenuto = new Libro(); break;
        case 1 : contenuto = new Manga(); break;
        case 2 : contenuto = new Film(); break;
        case 3 : contenuto = new Anime(); break;
    }
    qDebug() << "Contenuto creato";
    contenuto->accept(visitor);
    qDebug() << "Modifica avvenuta";
    salvaContenuto(contenuto);
} 

void ContentManager::salvaContenuto(Contenuto* contenuto) {
    contenuti.push_back(contenuto);
    qDebug() << "Contenuto salvato con successo!!!";
}

ContentManager& ContentManager::getManager() { return *this; }
ContentManager::~ContentManager() {
    for(auto& content : contenuti) delete content;
}
