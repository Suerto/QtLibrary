#include "../../Headers/GUI/mangaFilters.h"
#include <string>

MangaFilters::MangaFilters(QWidget* parent) : Filters(parent), cover(new QComboBox(this)), cadence(new QComboBox(this)), mangaka(new QLineEdit(this)), editor(new QLineEdit(this)), pages(new QSpinBox(this)), chapters(new QSpinBox(this)), genre(new QComboBox(this)) {
    filtersLayout->addRow("Mangaka : ", mangaka);

    filtersLayout->addRow("Editore : ", editor);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Manga", genre);
    filtersLayout->addRow("Genere : ", genre);

    filtersLayout->addRow("Numero di Pagine : ", pages);

    filtersLayout->addRow("Numero di Capitoli : ", chapters);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Cadenze", cadence);
    filtersLayout->addRow("Cadenza : ", cadence);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Copertine", cover);
    filtersLayout->addRow("Copertina : ", cover);

    reset();
}

unordered_map<string, string> MangaFilters::raccogliDati() const {   
    unordered_map<string, string> parametri;

    parametri.insert({"Anno", std::to_string(year->value())});
    (language->currentText().toStdString()).empty() ? parametri.insert({"Lingua", "Indefinita"}) : parametri.insert({"Lingua", language->currentText().toStdString()});
    
    //Fisico
    (cover->currentText().toStdString()).empty() ? parametri.insert({"Copertina", "Indefinita"}) : parametri.insert({"Copertina", cover->currentText().toStdString()});
    parametri.insert({"Pagine", std::to_string(pages->value())});
    
    //Periodico
    (cadence->currentText().toStdString()).empty() ? parametri.insert({"Cadenza", "Indefinita"}) : parametri.insert({"Cadenza", cadence->currentText().toStdString()});

    //Manga
    (editor->text().toStdString()).empty() ? parametri.insert({"Editore", "Indefinito"}) :parametri.insert({"Editore", editor->text().toStdString()});
    (mangaka->text().toStdString()).empty() ? parametri.insert({"Mangaka", "Indefinito"}) : parametri.insert({"Mangaka", mangaka->text().toStdString()});
    (genre->currentText().toStdString()).empty() ? parametri.insert({"Genere", "Indefinito"}) : parametri.insert({"Genere", genre->currentText().toStdString()});

    parametri.insert({"Capitoli", std::to_string(chapters->value())});

    return parametri;
}

void MangaFilters::reset() {
    Filters::reset();
    
    cover->setCurrentIndex(-1);
    pages->setValue(0);

    cadence->setCurrentIndex(-1);

    mangaka->clear();
    editor->clear();
    genre->setCurrentIndex(-1);
    chapters->clear();
}

void MangaFilters::setCover(const QString& cvr) {
    cover->setCurrentText(cvr);
}

void MangaFilters::setPages(const unsigned int& pgs) {
    pages->setValue(pgs);
}

void MangaFilters::setCadence(const QString& cdnc) {
    cadence->setCurrentText(cdnc);
}

void MangaFilters::setMangaka(const QString& mngk) {
    mangaka->setText(mngk);
}

void MangaFilters::setEditor(const QString& edtr) {
    editor->setText(edtr);
}

void MangaFilters::setChapters(const unsigned int& chpt) {
    chapters->setValue(chpt);
}

void MangaFilters::setGenre(const QString& gnr) {
    genre->setCurrentText(gnr);
}

void MangaFilters::setModifiable(const bool& mdf) {
    Filters::setModifiable(mdf);

    cover->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    cover->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    cover->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");

    cadence->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    cadence->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    cadence->setStyleSheet(!mdf ?
                "QComboBox { border: none; background: transparent; padding-left: 2px; }"
                "QComboBox::drop-down { border: none; width: 0px; }"
                "QComboBox::down-arrow { image: none; }" : "");
    pages->setReadOnly(!mdf);
    pages->setButtonSymbols(mdf ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);
    pages->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    pages->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    pages->setStyleSheet(!mdf ?
            "QSpinBox { border: none; background: transparent; }" : "");

    mangaka->setReadOnly(!mdf);
    mangaka->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    mangaka->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    mangaka->setStyleSheet(!mdf ?
        "QLineEdit { border: none; background: transparent; }" : "");

    editor->setReadOnly(!mdf);
    editor->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    editor->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    editor->setStyleSheet(!mdf ?
        "QLineEdit { border: none; background: transparent; }" : "");

    chapters->setReadOnly(!mdf);
    chapters->setButtonSymbols(mdf ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);
    chapters->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    chapters->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    chapters->setStyleSheet(!mdf ?
            "QSpinBox { border: none; background: transparent; }" : "");

    genre->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    genre->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    genre->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");
}
