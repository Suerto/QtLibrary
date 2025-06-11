#include "../../Headers/GUI/duplicateVerifier.h"
#include <QDebug>

DuplicateVerifier::DuplicateVerifier(ContentManager* mngr) : manager(mngr) {}

bool DuplicateVerifier::isThereADuplicate(const int& index, const unordered_map<string, string>& map) const {
    return manager->controllaDuplicato(index, map);
}
