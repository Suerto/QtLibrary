#include "../../Headers/GUI/genericFilters.h"
#include "qcombobox.h"
#include "qformlayout.h"

Filters::Filters(QWidget* parent) : QWidget(parent), language(new QComboBox(this)), year(new QSpinBox(this)), filtersLayout(new QFormLayout(this)) {
    filtersLayout->setSpacing(10);

    JsonHandler::loadEnumFromJson("Data/Dati.json", "Lingue", language);
    language->setBaseSize(50, 20);
    filtersLayout->addRow("Selezionare una lingua : ", language);
    
    year->setMaximum(2025);
    filtersLayout->addRow("Indicare l'anno di pubblicazione : ", year);

    setLayout(filtersLayout);
}

void Filters::reset() { language->setCurrentIndex(-1); } 
