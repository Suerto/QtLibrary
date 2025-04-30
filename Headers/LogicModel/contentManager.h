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

    void creaContenuto(const int& index, const Visitors* visitor);
    void salvaContenuto(const int& index, Contenuto* contenuto);
    
    vector<Contenuto*> cercaPerTitolo(const string& title) const;

    ContentManager& getManager();

    template<class T>
    vector<T*> cercaContenuto(const int& index, const Visitors* visitor) const;
};

#endif //CONTENT_MANAGER_H
