#include "../../Headers/GUI/filmFilters.h"

FilmFilters::FilmFilters(QWidget* parent) : Filters(parent), resolution(new QComboBox(this)), duration(new QSpinBox(this)), director(new QLineEdit(this)), composer(new QLineEdit(this)), producer(new QLineEdit(this)), genre(new QComboBox(this)) {
    filtersLayout->addRow("Regista : ", director);

    filtersLayout->addRow("Compositore :", composer);

    filtersLayout->addRow("Produttore :", producer);
    
    duration->setMaximum(10000);
    filtersLayout->addRow("Durata : ", duration);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Film", genre);
    filtersLayout->addRow("Genere : ", genre);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Risoluzioni", resolution);
    filtersLayout->addRow("Risoluzione : ", resolution);

    reset();
}

unordered_map<string, string> FilmFilters::raccogliDati() const {
    unordered_map<string, string> parametri;

    //Contenuto
    parametri.insert({"Anno", std::to_string(year->value())});
    (language->currentText().toStdString()).empty() ? parametri.insert({"Lingua", "Indefinita"}) : parametri.insert({"Lingua", language->currentText().toStdString()});
    
    //Digitale
    (resolution->currentText().toStdString()).empty() ? parametri.insert({"Risoluzione", "Indefinita"}) : parametri.insert({"Risoluzione", resolution->currentText().toStdString()});
    parametri.insert({"Durata", std::to_string(duration->value())});
    
    //Film
    (director->text().toStdString()).empty() ? parametri.insert({"Regista", "Indefinito"}) : parametri.insert({"Regista", director->text().toStdString()});
    (composer->text().toStdString()).empty() ? parametri.insert({"Compositore", "Indefinito"}) :parametri.insert({"Compositore", composer->text().toStdString()});
    (producer->text().toStdString()).empty() ? parametri.insert({"Producer", "Indefinito"}) : parametri.insert({"Producer", producer->text().toStdString()});
    (genre->currentText().toStdString()).empty() ? parametri.insert({"Genere", "Indefinito"}) : parametri.insert({"Genere", genre->currentText().toStdString()});
    return parametri;
}

void FilmFilters::reset() {
    Filters::reset();
    
    resolution->setCurrentIndex(-1);
    duration->setValue(0);

    director->clear();
    composer->clear();
    producer->clear();
    genre->setCurrentIndex(-1);
    resolution->setCurrentIndex(-1);
}

void FilmFilters::setResolution(const QString& rslt) {
    resolution->setCurrentText(rslt);
}
void FilmFilters::setDuration(const unsigned int& drtn) {
    duration->setValue(drtn);
}

void FilmFilters::setDirector(const QString& drct) {
    director->setText(drct);
}
void FilmFilters::setComposer(const QString& cmps) {
    composer->setText(cmps);
}
void FilmFilters::setProducer(const QString& prdc) {
    producer->setText(prdc);
}
void FilmFilters::setGenre(const QString& gnr) {
    genre->setCurrentText(gnr);
}

void FilmFilters::setModifiable(const bool& mdf) {
    Filters::setModifiable(mdf);
    
    resolution->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    resolution->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    resolution->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");

    duration->setReadOnly(!mdf);
    duration->setButtonSymbols(mdf ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);
    duration->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    duration->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    duration->setStyleSheet(!mdf ? "QSpinBox { border: none; background: transparent; }" : "");

    director->setReadOnly(!mdf);
    director->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    director->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    director->setStyleSheet(!mdf ? "QLineEdit { border: none; background: transparent; }" : "");

    composer->setReadOnly(!mdf);
    composer->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    composer->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    composer->setStyleSheet(!mdf ? "QLineEdit { border: none; background: transparent; }" : "");

    producer->setReadOnly(!mdf);
    producer->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    producer->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    producer->setStyleSheet(!mdf ? "QLineEdit { border: none; background: transparent; }" : "");

    genre->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    genre->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    genre->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");
}
