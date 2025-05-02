#include "../../Headers/GUI/genericFilters.h"

Filters::Filters(QWidget* parent) : QWidget(parent), language(new QComboBox(this)), year(new QSpinBox(this)), filtersLayout(new QFormLayout(this)) {
    JsonHandler::loadEnumFromJson("Data/Dati.json", "Lingue", language);
    filtersLayout->addRow("Selezionare Lingua : ", language);
    
    year->setMinimum(0);
    year->setMaximum(2025);
    filtersLayout->addRow("Anno di Pubblicazione : ", year);

    setLayout(filtersLayout);

    reset();
}

void Filters::reset() { 
    language->setCurrentIndex(-1); 
    
    year->setValue(0);
}
