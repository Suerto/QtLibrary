#include "../../Headers/GUI/genericFilters.h"
#include "qcombobox.h"
#include "qformlayout.h"

Filters::Filters(QWidget* parent) : QWidget(parent), language(new QComboBox(this)), year(new QSpinBox(this)), filtersLayout(new QFormLayout(this)) {
    //carica le lingue
    filtersLayout->setSpacing(10);

    JsonHandler::loadEnumFromJson(language, "Data/lingue.json", "Lingue");
    language->setBaseSize(50, 20);
    filtersLayout->addRow("Selezionare una lingua : ", language);
    
    year->setMaximum(2025);
    filtersLayout->addRow("Indicare l'anno di pubblicazione : ", year);

    setLayout(filtersLayout);
}

void Filters::reset() {
    language->setCurrentIndex(6);
} 
