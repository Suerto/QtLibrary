#include "../../Headers/GUI/duplicateVerifier.h"
#include <QDebug>

DuplicateVerifier::DuplicateVerifier(ContentManager* mngr) : manager(mngr) {
    qDebug() << "Manager passato : " << static_cast<void*>(manager);
}

bool DuplicateVerifier::isThereADuplicate(const int& index, const unordered_map<string, string>& map) const {
    return manager->cercaContenuto(index, map).size() != 0;
}
