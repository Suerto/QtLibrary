#include "../../Headers/GUI/bookFilters.h"

BookFilters::BookFilters(QWidget* parent) : Filters(parent), cover(new QComboBox(this)), pages(new QSpinBox(this)), author(new QLineEdit(this)), editor(new QLineEdit(this)), publisher(new QLineEdit(this)), genre(new QComboBox(this)) { 
    filtersLayout->addRow("Autore : ", author);
    
    filtersLayout->addRow("Editore : ", editor);
 
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Generi Libri", genre);
    filtersLayout->addRow("Genere : ", genre);

    pages->setMinimum(0);
    pages->setMaximum(10000);
    filtersLayout->addRow("Numero di Pagine : ", pages);
    
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Copertine", cover);
    filtersLayout->addRow("Copertina : ", cover);

    filtersLayout->addRow("Publisher : ", publisher);
    
    reset();
}

unordered_map<string, string> BookFilters::raccogliDati() const {
    unordered_map<string, string> parametri; 
    //Contenuto
    parametri.insert({"Anno", std::to_string(year->value())});
    (language->currentText().toStdString()).empty() ? parametri.insert({"Lingua", "Indefinita"}) : parametri.insert({"Lingua", language->currentText().toStdString()});
    parametri.insert({"Anteprima", pathImmagine.toStdString()});
    
    //Fisico
    (cover->currentText().toStdString()).empty() ? parametri.insert({"Copertina", "Indefinita"}) : parametri.insert({"Copertina", cover->currentText().toStdString()});
    parametri.insert({"Pagine", std::to_string(pages->value())});
    
    //Libro
    (author->text().toStdString()).empty() ? parametri.insert({"Autore", "Indefinito"}) : parametri.insert({"Autore", author->text().toStdString()});
    (editor->text().toStdString()).empty() ? parametri.insert({"Editore", "Indefinito"}) :parametri.insert({"Editore", editor->text().toStdString()});
    (publisher->text().toStdString()).empty() ? parametri.insert({"Publisher", "Indefinito"}) : parametri.insert({"Publisher", publisher->text().toStdString()});
    (genre->currentText().toStdString()).empty() ? parametri.insert({"Genere", "Indefinito"}) : parametri.insert({"Genere", genre->currentText().toStdString()});

    return parametri;
}

void BookFilters::reset() {
   Filters::reset();
    
   author->setText("");
   editor->setText("");
   genre->setCurrentIndex(-1);
   pages->setValue(0);
   cover->setCurrentIndex(-1);
   publisher->setText("");
}

void BookFilters::setCover(const QString& cvr) {
    cover->setCurrentText(cvr);
}

void BookFilters::setPages(const unsigned int& pgs) {
    pages->setValue(pgs);
}

void BookFilters::setAuthor(const QString& athr) {
    author->setText(athr);
}

void BookFilters::setEditor(const QString& edtr) {
    editor->setText(edtr);
}

void BookFilters::setPublisher(const QString& pshr) {
    publisher->setText(pshr);
}

void BookFilters::setGenre(const QString& gnr) {
    genre->setCurrentText(gnr);
}

void BookFilters::setModifiable(const bool& mdf) {
    Filters::setModifiable(mdf);

    cover->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    cover->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    cover->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");

    pages->setReadOnly(!mdf);
    pages->setButtonSymbols(mdf ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);
    pages->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    pages->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    pages->setStyleSheet(!mdf ?
            "QSpinBox { border: none; background: transparent; }" : "");

    author->setReadOnly(!mdf);
    author->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    author->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    author->setStyleSheet(!mdf ?
        "QLineEdit { border: none; background: transparent; }" : "");
    
    editor->setReadOnly(!mdf);
    editor->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    editor->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    editor->setStyleSheet(!mdf ?
        "QLineEdit { border: none; background: transparent; }" : "");


    publisher->setReadOnly(!mdf);
    publisher->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    publisher->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    publisher->setStyleSheet(!mdf ?
        "QLineEdit { border: none; background: transparent; }" : "");

    genre->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
    genre->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
    genre->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");
}

void BookFilters::setAttributes(const unordered_map<string, string>& attributes) {
    Filters::setAttributes(attributes);

    setCover(QString::fromStdString(attributes.find("Copertina")->second));
    setPages(std::stoi(attributes.find("Pagine")->second));

    setAuthor(QString::fromStdString(attributes.find("Autore")->second));
    setEditor(QString::fromStdString(attributes.find("Editore")->second));
    setPublisher(QString::fromStdString(attributes.find("Publisher")->second));
    setGenre(QString::fromStdString(attributes.find("Genere")->second));
}


void BookFilters::accept(GuiVisitor* visitor) const {
    visitor->visit(this);
}

BookFilters::~BookFilters() = default;
