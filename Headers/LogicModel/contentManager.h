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
    vector<Contenuto*> contenuti;
public:
    ContentManager();
    ~ContentManager();

    void creaContenuto(const int& index, const Visitors* visitor);
    void salvaContenuto(Contenuto* contenuto);

    ContentManager& getManager();
};

#endif //CONTENT_MANAGER_H
