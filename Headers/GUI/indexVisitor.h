#ifndef INDEX_VISITOR_H
#define INDEX_VISITOR_H

#include "guiVisitor.h"

class IndexVisitor : public GuiVisitor {
private:
    int index;
public:
    virtual void visit(const AnimeFilters& anime) override;
    virtual void visit(const BookFilters& book) override;
    virtual void visit(const FilmFilters& film) override;
    virtual void visit(const MangaFilters& manga) override;

    int getIndex() const;
};

#endif //INDEX_VISITOR_H
