#include "../../Headers/LogicModel/contentManager.h"

#include "QDebug"
#include <algorithm>
#include <cctype>
ContentManager::ContentManager() : memoria() {}

std::unordered_map<int, std::function<Contenuto*()>> ContentManager::creatore = {
    {0, [](){ return new Libro(); } },
    {1, [](){ return new Manga(); } },
    {2, [](){ return new Film(); } },
    {3, [](){ return new Anime(); } }
};

void ContentManager::creaContenuto(const int& index, Visitors* visitor) {  
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
    
    const string& title = map.find("Titolo")->second;
    for(Contenuto* element : memoria[index]) {
        if(element->getNome().size() >= title.size() && 
           std::equal(title.begin(), title.end(), element->getNome().begin(), 
           [](char a, char b) { return std::tolower(a) == std::tolower(b);})) {
            element->accept(check);
            if(check->isSimilar()) risultati.push_back(element);
        }
    }
    return risultati;
}

vector<Contenuto*> ContentManager::cercaPerTitolo(const string& title) const {
    vector<Contenuto*> risultati;
    
    for(vector<Contenuto*> tipologia : memoria) {
        for(Contenuto* content : tipologia) {
            if(content->getNome().size() >= title.size() && 
                    std::equal(title.begin(), title.end(), content->getNome().begin(), 
                        [](char a, char b) {
                            return std::tolower(a) == std::tolower(b); 
                            }
                    )
            ) risultati.push_back(content); 
        }
    }
    qDebug() << risultati.size();
    return risultati;
}

void ContentManager::eliminaContenuto(const int& index, Contenuto* contenuto) {
    qDebug() << "Passo finale : eliminazione in ContentManager" << index << " " << static_cast<void*>(contenuto);
    for(auto it = memoria[index].begin(); it != memoria[index].end(); ++it) {
        if(*it == contenuto) {
            qDebug() << "Memoria pre-eliminazione : " << memoria[index].size();
            qDebug() << "Contenuto trovato!" << static_cast<void*>(contenuto) << " " << static_cast<void*>(*it);
            delete *it;
            memoria[index].erase(it);
            qDebug() << "Memoria post-eliminazione : " << memoria[index].size();
            break;
        }
    }
}

ContentManager::~ContentManager() = default;
