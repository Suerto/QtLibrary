#ifndef DUPLICATE_VERIFIER_H
#define DUPLICATE_VERIFIER_H

#include "../LogicModel/contentManager.h"

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class DuplicateVerifier {
private:
    bool duplicate;
    ContentManager* manager;
public:
    DuplicateVerifier(ContentManager* mngr);
    bool isThereADuplicate(const int& index, const unordered_map<string, string>& map) const;
};

#endif //DUPLICATE_VERIFIER_H
       //
//Valutare la possibilità di far partire il DuplicateVerifier direttamente dal main e poi a scalata portarlo fino a ContentViewer
