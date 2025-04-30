#include "../../Headers/LogicModel/contentManager.h"

#include <QDebug>

ContentManager::ContentManager() : memoria() {}

std::unordered_map<int, std::function<Contenuto*()>> ContentManager::creatore = {
    {0, [](){ return new Libro(); } },
    {1, [](){ return new Manga(); } },
    {2, [](){ return new Film(); } },
    {3, [](){ return new Anime(); } }
};

void ContentManager::creaContenuto(const int& index, const Visitors* visitor) {  
    Contenuto* contenuto = creatore.find(index)->second();
    contenuto->accept(visitor);
    salvaContenuto(index, contenuto);
} 

void ContentManager::salvaContenuto(const int& index, Contenuto* contenuto) {
    memoria[index].push_back(contenuto);
}

vector<Contenuto*> ContentManager::cercaPerTitolo(const string& title) const {
    vector<Contenuto*> risultati;
    
    for(vector<Contenuto*> tipo : memoria) {
        for(Contenuto* riscontro : tipo) {
            if(title == riscontro->getNome()) risultati.push_back(riscontro); 
        }
    }
    return risultati;
}

ContentManager& ContentManager::getManager() { return *this; }

ContentManager::~ContentManager() = default;
