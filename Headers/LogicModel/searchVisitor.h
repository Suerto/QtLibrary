#ifndef SEARCH_VISITOR_H
#define SEARCH_VISITOR_H

#include "visitors.h"
#include "anime.h"
#include "manga.h"
#include "libro.h"
#include "film.h"
#include <unordered_map>
#include <string>

using std::string;
using std::unordered_map;

class SearchVisitor : public Visitors {
private:
    unordered_map<string, string> parametri;
    bool similar;

    static string toLower(const string& str);
    bool matches(const string& criterio, const string& valore) const;

public:
    SearchVisitor(unordered_map<string, string> prm = unordered_map<string, string>(),
                  bool sml = true);

    void visit(Libro& lib) override;
    void visit(Film& flm) override;
    void visit(Manga& mng) override;
    void visit(Anime& anm) override;

    bool isSimilar() const;
    void setDefault();
    unordered_map<string, string> getMap() const;

    virtual ~SearchVisitor() override;
};

#endif // SEARCH_VISITOR_H

