#include "../../Headers/GUI/errorStructure.h"

ErrorStructure::ErrorStructure(QWidget* parent) : QDialog(parent), text(new QLabel(this)), errorLayout(new QVBoxLayout(this)) {
    errorLayout->addWidget(text, Qt::AlignCenter);

    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    setModal(true);  // se vuoi bloccare l'interazione con altre finestre
    
    adjustSize();
    setStyleSheet(R"(
        QLabel {
            color : white;
            font-family : Fira Code;
            font-size : 15px;
        }

        QDialog {
            background-color: #848687;
            border: 2px solid #0078D7;
        }
        )");
}
