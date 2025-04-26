#ifndef CREATION_VISITOR_H
#define CREATION_VISITOR_H

#include <unordered_map>
#include <string>

#include "visitors.h"
#include "libro.h"
#include "anime.h"
#include "manga.h"
#include "film.h"

using std::unordered_map;
using std::string;
using std::stoi;

class CreationVisitor : public Visitors {
private:
    unordered_map<string, string> parametri;
public:
    CreationVisitor(const unordered_map<string, string>& prmts);

    virtual void visit(Libro& lib) const override;
    virtual void visit(Film& flm) const override;
    virtual void visit(Manga& mng) const override;
    virtual void visit(Anime& anm) const override;
};

#endif //CREATION_VISITOR_H