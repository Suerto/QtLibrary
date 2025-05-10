#include "../../Headers/GUI/animeFilters.h"
#include <string>

AnimeFilters::AnimeFilters(QWidget* parent) :Filters(parent), resolution(new QComboBox(this)), duration(new QSpinBox(this)), producer(new QLineEdit(this)), episodes(new QSpinBox(this)), seasons(new QSpinBox(this)), subtitled(new QCheckBox(this)), genre(new QComboBox(this)), cadence(new QComboBox(this)) {
   filtersLayout->addRow("Producer :", producer);

   filtersLayout->addRow("Sottotitolato :", subtitled);
    
   episodes->setMaximum(1000);
   filtersLayout->addRow("Episodi :", episodes);
    
   duration->setMaximum(120);
   filtersLayout->addRow("Durata episodio : ", duration);
    
   JsonHandler::loadEnumFromJson("Data/Dati.json", "Cadenze", cadence);
   filtersLayout->addRow("Cadenza :", cadence);
    
   seasons->setMaximum(10);
   filtersLayout->addRow("Stagioni :", seasons);

   JsonHandler::loadEnumFromJson("Data/Dati.json", "Risoluzioni", resolution);
   filtersLayout->addRow("Risoluzione :", resolution);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Anime", genre);
    filtersLayout->addRow("Genere :", genre);
    
    reset();
} 

unordered_map<string, string> AnimeFilters::raccogliDati() const {
    unordered_map<string, string> parametri;
    //Contenuto
    parametri.insert({"Anno", std::to_string(year->value())});
    (language->currentText().toStdString()).empty() ? parametri.insert({"Lingua", "Indefinita"}) : parametri.insert({"Lingua", language->currentText().toStdString()});
    
    //Digitale
    (resolution->currentText().toStdString()).empty() ? parametri.insert({"Risoluzione", "Indefinita"}) : parametri.insert({"Risoluzione", resolution->currentText().toStdString()});
    parametri.insert({"Durata", std::to_string(duration->value())});
    
    //Periodico
    (cadence->currentText().toStdString()).empty() ? parametri.insert({"Cadenza", "Indefinita"}) : parametri.insert({"Cadenza", cadence->currentText().toStdString()});

    //Anime
    parametri.insert({"Episodi", std::to_string(episodes->value())});
    parametri.insert({"Stagioni", std::to_string(seasons->value())});
    parametri.insert({"Sottotitolato", subtitled->isChecked() ? "true" : "false"});
    (producer->text().toStdString()).empty() ? parametri.insert({"Producer", "Indefinito"}) : parametri.insert({"Producer", producer->text().toStdString()});
    (genre->currentText().toStdString()).empty() ? parametri.insert({"Genere", "Indefinito"}) : parametri.insert({"Genere", genre->currentText().toStdString()});
    return parametri;
}

void AnimeFilters::reset() {
    Filters::reset();

    resolution->setCurrentIndex(-1);
    duration->setValue(0);

    cadence->setCurrentIndex(-1);
    producer->clear();
    subtitled->setChecked(false);
    episodes->setValue(0);
    seasons->setValue(0);
    genre->setCurrentIndex(-1);
}

void AnimeFilters::setResolution(const QString& rslt) {
    resolution->setCurrentText(rslt);
}
void AnimeFilters::setDuration(const unsigned int& drtn) {
    duration->setValue(drtn);
}

void AnimeFilters::setProducer(const QString& prdc) {
    producer->setText(prdc);
}
void AnimeFilters::setEpisodes(const unsigned int& epsd) {
    episodes->setValue(epsd);
}
void AnimeFilters::setSeasons(const unsigned int& ssns) {
    seasons->setValue(ssns);
}
void AnimeFilters::setSubtitle(const bool& sbtd) {
    subtitled->setChecked(sbtd);
}
void AnimeFilters::setGenre(const QString& gnr) {
    genre->setCurrentText(gnr);
}
void AnimeFilters::setCadence(const QString& cdnc) {
    cadence->setCurrentText(cdnc);
}

void AnimeFilters::setModifiable(const bool& mdf) {
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
        duration->setStyleSheet(!mdf ?
            "QSpinBox { border: none; background: transparent; }" : "");
        
        cadence->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        cadence->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        cadence->setStyleSheet(!mdf ?
                "QComboBox { border: none; background: transparent; padding-left: 2px; }"
                "QComboBox::drop-down { border: none; width: 0px; }"
                "QComboBox::down-arrow { image: none; }" : "");

        producer->setReadOnly(!mdf);
        producer->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        producer->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        producer->setStyleSheet(!mdf ?
            "QLineEdit { border: none; background: transparent; }" : "");

        genre->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        genre->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        genre->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");

        episodes->setReadOnly(!mdf);
        episodes->setButtonSymbols(mdf ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);
        episodes->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        episodes->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        episodes->setStyleSheet(!mdf ?
            "QSpinBox { border: none; background: transparent; }" : "");

        seasons->setReadOnly(!mdf);
        seasons->setButtonSymbols(mdf ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);
        seasons->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        seasons->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        seasons->setStyleSheet(!mdf ?
            "QSpinBox { border: none; background: transparent; }" : "");

        subtitled->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        subtitled->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);

        genre->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        genre->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        genre->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");
}

void AnimeFilters::setAttributes(const unordered_map<string, string>& attributes) {
    Filters::setAttributes(attributes);

    setResolution(QString::fromStdString(attributes.find("Risoluzione")->second));
    setDuration(std::stoi(attributes.find("Durata")->second));

    setCadence(QString::fromStdString(attributes.find("Cadenza")->second));

    setProducer(QString::fromStdString(attributes.find("Producer")->second));
    setEpisodes(std::stoi(attributes.find("Episodi")->second));
    setSeasons(std::stoi(attributes.find("Stagioni")->second));
    setSubtitle(attributes.find("Sottotitolato")->second == "true" ? 1 : 0);
    setGenre(QString::fromStdString(attributes.find("Genere")->second));
}
