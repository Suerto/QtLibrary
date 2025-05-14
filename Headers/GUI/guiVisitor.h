#ifndef GUI_VISITOR_H
#define GUI_VISITOR_H

class AnimeFilters;
class BookFilters;
class FilmFilters;
class MangaFilters;

class GuiVisitor {
public:
    virtual void visit(const AnimeFilters& anime) = 0;
    virtual void visit(const BookFilters& book) = 0;
    virtual void visit(const FilmFilters& film) = 0;
    virtual void visit(const MangaFilters& manga) = 0;
};

#endif //GUI_VISITOR_H
