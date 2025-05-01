#ifndef VISITORS_H
#define VISITORS_H

class Libro;
class Manga;
class Anime;
class Film;

#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

class Visitors {
public:
    virtual void visit(Libro& lib) const = 0;
    virtual void visit(Film& flm) const = 0;
    virtual void visit(Manga& mng) const = 0;
    virtual void visit(Anime& anm) const = 0;

    virtual std::unordered_map<string, string> getMap() const = 0;
};

#endif
