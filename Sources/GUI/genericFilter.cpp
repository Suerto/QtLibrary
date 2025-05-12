#include "../../Headers/GUI/genericFilters.h"

Filters::Filters(QWidget* parent) : QWidget(parent), language(new QComboBox(this)), year(new QSpinBox(this)), filtersLayout(new QFormLayout(this)) {
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Lingue", language);
    filtersLayout->addRow("Lingua : ", language);
    
    year->setMinimum(0);
    year->setMaximum(2025);
    filtersLayout->addRow("Anno di Pubblicazione : ", year);

    setLayout(filtersLayout);

    reset();

    setStyleSheet(R"(    
        QComboBox { 
            background-color : #ABADAB;  
        }

        QCheckBox {
            background-color : #F9F6EE;
        }
    )");
}

void Filters::reset() { 
    language->setCurrentIndex(-1); 
    
    year->setValue(0);
}

void Filters::setLanguage(const QString& lng) {
    language->setCurrentText(lng);
}

void Filters::setYear(const unsigned int& yr) {
    year->setValue(yr);
}

void Filters::setModifiable(const bool& mdf) {
        language->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        language->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        language->setStyleSheet(!mdf ?
            "QComboBox { border: none; background: transparent; padding-left: 2px; }"
            "QComboBox::drop-down { border: none; width: 0px; }"
            "QComboBox::down-arrow { image: none; }" : "");
        
        year->setReadOnly(!mdf);
        year->setButtonSymbols(mdf ? QAbstractSpinBox::UpDownArrows : QAbstractSpinBox::NoButtons);
        year->setFocusPolicy(mdf ? Qt::StrongFocus : Qt::NoFocus);
        year->setAttribute(Qt::WA_TransparentForMouseEvents, !mdf);
        year->setStyleSheet(!mdf ?
            "QSpinBox { border: none; background: transparent; }" : "");
}

void Filters::setAttributes(const std::unordered_map<string, string>& attributes) {
    setLanguage(QString::fromStdString(attributes.find("Lingua")->second));
    setYear(std::stoi(attributes.find("Anno")->second));
}
