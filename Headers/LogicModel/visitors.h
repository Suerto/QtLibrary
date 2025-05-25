#ifndef VISITORS_H
#define VISITORS_H

#include <unordered_map>
#include <string>

class Libro;
class Manga;
class Anime;
class Film;

using std::string;
using std::unordered_map;

class Visitors {
public:
    virtual void visit(Libro& lib) = 0;
    virtual void visit(Film& flm) = 0;
    virtual void visit(Manga& mng) = 0;
    virtual void visit(Anime& anm) = 0;

    virtual ~Visitors() = default;
};

#endif
