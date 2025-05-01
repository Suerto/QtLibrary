#ifndef CHECK_VISITOR_H
#define CHECK_VISITOR_H

#include "visitors.h"
#include "anime.h"
#include "manga.h"
#include "libro.h"
#include "film.h"

class CheckVisitor : public Visitors {
private:
    unordered_map<string, string> parametri;
    mutable bool similar;
public:
    CheckVisitor(unordered_map<string, string> prm = unordered_map<string, string>(), bool sml = true);

    virtual void visit(Libro& lib) const override;
    virtual void visit(Film& flm) const override;
    virtual void visit(Manga& mng) const override;
    virtual void visit(Anime& anm) const override;

    bool isSimilar() const;

    virtual unordered_map<string, string> getMap() const override;
};

//Spiegazione del perché ho usato mutable bool similar

#endif //CHECK_VISITOR_H
