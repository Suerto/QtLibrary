#ifndef INDEX_VISITOR_H
#define INDEX_VISITOR_H

#include "visitors.h"
#include "libro.h"
#include "manga.h"
#include "film.h"
#include "anime.h"

class IndexVisitor : public Visitors {
private:
    int index;
public:
    virtual void visit(Libro& lib) override;
    virtual void visit(Manga& mng) override;
    virtual void visit(Film& flm) override;
    virtual void visit(Anime& anm) override;

    int getIndex() const;
};

#endif //INDEX_VISITOR_H
