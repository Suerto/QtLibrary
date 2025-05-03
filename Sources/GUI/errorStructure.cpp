#include "../../Headers/GUI/errorStructure.h"

ErrorStructure::ErrorStructure(QWidget* parent) : QDialog(parent), text(new QLabel(this)), errorLayout(new QVBoxLayout(this)) {
   errorLayout->addWidget(text, Qt::AlignCenter); 
}
