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
    json{},
    memoria{} {}

void ContentManager::setJsonFiles(const array<string, 4>& js) { json = js; }

void ContentManager::downloadContenuti() {
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
    for (const auto& [T, V] : map) {
        qDebug() << QString::fromStdString(T) << " : " << QString::fromStdString(V);
    }
    for (Contenuto* element : memoria[index]) {
        SearchVisitor check(map);

        const string& nome = element->getNome();

        // Cerca se 'title' è contenuto in 'nome' (case-insensitive)
        auto it = std::search(
                nome.begin(), nome.end(),
                title.begin(), title.end(),
                [](char ch1, char ch2) {
                return std::tolower(ch1) == std::tolower(ch2);
                });

        if (it != nome.end()) {
            element->accept(&check);
            if (check.isSimilar())
                risultati.push_back(element);
        }
    }
    qDebug() << risultati.size();
    return risultati;
}

bool ContentManager::controllaDuplicato(const int& index, 
        const unordered_map<string, string>& map) const {
    qDebug() << "Ingresso in controllo duplicato di ContentManager ok";
    const string& title = map.find("Titolo")->second;
    
    vector<Contenuto*> duplicati;
    for(Contenuto* duplicate : memoria[index]) {
        if(duplicate->getNome() == title) duplicati.push_back(duplicate); 
    }
    
    CheckVisitor check(map);
    //se c'è solo un elemento, è quello che si vuole modificare
    if(duplicati.size() != 1) {
        for(Contenuto* element : duplicati) {
            check.setDefault();
            qDebug() << "Più di 1 contenuto";
            qDebug() << static_cast<void*>(&check);
            qDebug() << "Contenuti con stesso titolo trovati " << duplicati.size();
            element->accept(&check);
            if(check.isSimilar()) return true; 
        }
    }
    
    qDebug() << "Non ci sono duplicati";
    return false;
}

vector<Contenuto*> ContentManager::cercaPerTitolo(const string& title) const {
    vector<Contenuto*> risultati;

    for (const vector<Contenuto*>& tipologia : memoria) {
        for (Contenuto* content : tipologia) {
            const string& nome = content->getNome();
            if (!title.empty() && std::search(
                    nome.begin(), nome.end(),
                    title.begin(), title.end(),
                    [](char a, char b) {
                        return std::tolower(a) == std::tolower(b);
                    }) != nome.end()) {
                risultati.push_back(content);
            }
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
            qDebug() << "Trovato il contenuto da modificare";
            CreationVisitor visitor(modifiche);
            (*it)->accept(&visitor);
            qDebug() << "Contenuto modificato correttamente";
            break;
        }
    }
}

ContentManager::~ContentManager() {
    for(auto& vettore : memoria) {
        for(auto ptr : vettore) {
            delete ptr;
        }
        vettore.clear();
    }
}
