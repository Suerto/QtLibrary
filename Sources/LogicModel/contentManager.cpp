#include "../../Headers/LogicModel/contentManager.h"

#include "../JSON/JsonHandler.hpp"
#include "qglobal.h"

std::unordered_map<int, std::function<Contenuto*()>> ContentManager::creatore = {
    {0, [](){ return new Libro(); } },
    {1, [](){ return new Manga(); } },
    {2, [](){ return new Film(); } },
    {3, [](){ return new Anime(); } }
};

ContentManager::ContentManager() : 
    json({"Data/libro.json", "Data/manga.json", "Data/film.json", "Data/anime.json"}),
    memoria{} {

    for(std::size_t i = 0; i < memoria.size(); ++i) {
        vector<unordered_map<string, string>> mappeContenuti = 
                JsonHandler::estraiArrayDiMappe(QString::fromStdString(json[i]));

        for(auto mappa : mappeContenuti) {
            CreationVisitor contenuto(mappa);
            creaContenuto(i, &contenuto);
        }
    }
}

void ContentManager::uploadContenuti() {
    for(std::size_t i = 0; i < memoria.size(); ++i) {
        JsonHandler::salvaArrayDiMappe(QString::fromStdString(json[i]), memoria[i]);
    }
}

void ContentManager::creaContenuto(const int& index, Visitors* visitor) {  
    Contenuto* contenuto = creatore.find(index)->second();
    contenuto->accept(visitor);
    salvaContenuto(index, contenuto);
}

void ContentManager::salvaContenuto(const int& index, Contenuto* contenuto) {
    memoria[index].push_back(contenuto);
}

vector<Contenuto*> ContentManager::cercaContenuto(const int& index,
        const unordered_map<string, string>& map) const {
    vector<Contenuto*> risultati;
    qDebug() << "Ingresso in cercaContenuto";
    const string& title = map.find("Titolo")->second;
    for(const auto&[T, V] : map) {
        qDebug() << QString::fromStdString(T) << " : " << QString::fromStdString(V);
    }
    for(Contenuto* element : memoria[index]) {
        CheckVisitor check(map); 
        //check.setDefault();
        if(element->getNome().size() >= title.size() && 
           std::equal(title.begin(), title.end(), element->getNome().begin(), 
           [](char a, char b) { return std::tolower(a) == std::tolower(b);})) {
                element->accept(&check);
                if(check.isSimilar()) risultati.push_back(element);
        }
    }
    qDebug() << risultati.size();
    return risultati;
}

bool ContentManager::controllaDuplicato(const int& index, 
        const unordered_map<string, string>& map) const {
    CheckVisitor check(map);
    const string& title = map.find("Titolo")->second;
    
    vector<Contenuto*> duplicati;
    for(Contenuto* duplicate : memoria[index]) {
        if(duplicate->getNome() == title) duplicati.push_back(duplicate); 
    }
    
    //se c'è solo un elemento, è quello che si vuole modificare
    if(duplicati.size() != 1) {
        for(Contenuto* element : duplicati) {
            element->accept(&check);
            if(check.isSimilar()) return true; 
        }
    }
    
    return false;
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

    return risultati;
}

void ContentManager::eliminaContenuto(const int& index, 
        const unordered_map<string, string>& attributi) {
    for(auto it = memoria[index].begin(); it != memoria[index].end(); ++it) {
        CheckVisitor visitor(attributi);
        (*it)->accept(&visitor);
        
        if(visitor.isSimilar()) {
            delete *it;
            memoria[index].erase(it);
            break;
        }
    }
}

void ContentManager::modificaContenuto(const int& index,
        const unordered_map<string, string>& original, 
        const unordered_map<string, string>& modifiche) {

    for(auto it = memoria[index].begin(); it != memoria[index].end(); ++it) {
        CheckVisitor visitor(original);

        (*it)->accept(&visitor);

        if(visitor.isSimilar()) {
            CreationVisitor visitor(modifiche);
            (*it)->accept(&visitor);
            break;
        }
    }
}

ContentManager::~ContentManager() = default;
