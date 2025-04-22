#ifndef CREATION_VISITOR_H
#define CREATION_VISITOR_H

#include <QVariantMap>

#include "../LogicModel/visitors.h"
#include "../LogicModel/libro.h"
#include "../LogicModel/anime.h"
#include "../LogicModel/manga.h"
#include "../LogicModel/film.h"

class CreationVisitor : public Visitors {
private:
    QVariantMap creationParameters;
public:
    CreationVisitor(const QVariantMap& prmts);

    virtual void visit(Libro& lib) const override;
    virtual void visit(Film& flm) const override;
    virtual void visit(Manga& mng) const override;
    virtual void visit(Anime& anm) const override;
};

#endif //CREATION_VISITOR_H
