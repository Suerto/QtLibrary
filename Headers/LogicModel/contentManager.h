#ifndef CONTENT_MANAGER_H
#define CONTENT_MANAGER_H

#include <array>
#include <vector>
#include <functional>

#include "anime.h"
#include "film.h"
#include "libro.h"
#include "manga.h"
#include "creationVisitor.h"
#include "checkVisitor.h"

using std::vector;
using std::array;
using std::function;

class ContentManager {
private:
    array<vector<Contenuto*>, 4> memoria;
    static unordered_map<int, std::function<Contenuto*()>> creatore;
public:
    ContentManager();
    ~ContentManager();

    void creaContenuto(const int& index, Visitors* visitor);
    void salvaContenuto(const int& index, Contenuto* contenuto);
    void eliminaContenuto(const int& index, const unordered_map<string, string>& attributi);    
    vector<Contenuto*> cercaPerTitolo(const string& title) const; 
    vector<Contenuto*> cercaContenuto(const int& index, const unordered_map<string, string>& map) const;
    void modificaContenuto(const int& index, const unordered_map<string, string>& original, const unordered_map<string, string>& modifiche);
};

#endif //CONTENT_MANAGER_H
