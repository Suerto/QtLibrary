#ifndef CREATION_VISITOR_H
#define CREATION_VISITOR_H

#include "visitors.h"
#include "libro.h"
#include "anime.h"
#include "manga.h"
#include "film.h"

using std::stoi;

class CreationVisitor : public Visitors {
private:
    unordered_map<string, string> parametri;
public:
    CreationVisitor(const unordered_map<string, string>& prmts);

    virtual void visit(Libro& lib) override;
    virtual void visit(Film& flm) override;
    virtual void visit(Manga& mng) override;
    virtual void visit(Anime& anm) override;

    unordered_map<string, string> getMap() const;
};

#endif //CREATION_VISITOR_H
