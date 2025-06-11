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
    bool similar;
public:
    CheckVisitor(unordered_map<string, string> prm = unordered_map<string, string>(),
                 bool sml = true);

    virtual void visit(Libro& lib) override;
    virtual void visit(Film& flm) override;
    virtual void visit(Manga& mng) override;
    virtual void visit(Anime& anm) override;

    bool isSimilar() const;
    void setDefault();
    unordered_map<string, string> getMap() const;

    virtual ~CheckVisitor() override;
};

#endif //CHECK_VISITOR_H