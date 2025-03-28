#ifndef VISITORS_H
#define VISITORS_H

class Libro;
class Manga;
class Anime;
class Film;

class Visitors {
public:
    virtual void visit(const Libro& lib) const = 0;
    virtual void visit(const Film& flm) const = 0;
    virtual void visit(const Manga& mng) const = 0;
    virtual void visit(const Anime& anm) const = 0;
};

#endif
