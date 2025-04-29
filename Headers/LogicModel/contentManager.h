#ifndef CONTENT_MANAGER_H
#define CONTENT_MANAGER_H

#include <array>
#include <vector>

#include "anime.h"
#include "film.h"
#include "libro.h"
#include "manga.h"
#include "creationVisitor.h"

using std::vector;
using std::array;

class ContentManager {
private:
    array<vector<Contenuto*>, 4> contenuti;
public:
    ContentManager();
    ~ContentManager();

    void creaContenuto(const int& index, const Visitors* visitor);
    void salvaContenuto(const int& index, Contenuto* contenuto);
    void cercaContenuto(const int& index, const Visitors* visitor);

    ContentManager& getManager();
};

#endif //CONTENT_MANAGER_H
