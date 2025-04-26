#include "../../Headers/LogicModel/contentManager.h"

ContentManager::ContentManager() : contenuti() {}

void ContentManager::creaContenuto(const int& index, const Visitors* visitor) {  
    Contenuto* contenuto = nullptr;
    switch(index) {
        case 0 : contenuto = new Libro(); break;
        case 1 : contenuto = new Manga(); break;
        case 2 : contenuto = new Film(); break;
        case 3 : contenuto = new Anime(); break;
    }
    contenuto->accept(visitor);
    salvaContenuto(index, contenuto);
} 

void ContentManager::salvaContenuto(const int& index, Contenuto* contenuto) {
    contenuti[index].push_back(contenuto);
}

ContentManager& ContentManager::getManager() { return *this; }

ContentManager::~ContentManager() {
    for(auto& type : contenuti) {
        for(auto& content : type) delete content; 
    }     
}
