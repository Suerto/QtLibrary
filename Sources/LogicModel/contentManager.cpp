#include "../../Headers/LogicModel/contentManager.h"

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

vector<Contenuto*> ContentManager::cercaContenuto(const int& index, const unordered_map<string, string>& map) const {
    vector<Contenuto*> risultati;
    CheckVisitor* check = new CheckVisitor(map);
    
    for(Contenuto* element : memoria[index]) {
       element->accept(check);
       if(check->isSimilar()) risultati.push_back(element);
    }
    return risultati;
}

vector<Contenuto*> ContentManager::cercaPerTitolo(const string& title) const {
    vector<Contenuto*> risultati;
    
    for(vector<Contenuto*> tipologia : memoria) {
        for(Contenuto* content : tipologia) {
            if(title == content->getNome()) risultati.push_back(content); 
        }
    }
    return risultati;
}

ContentManager::~ContentManager() = default;
