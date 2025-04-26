#include "Headers/GUI/app.h"

int main(int argc, char** argv) {
    ContentManager appManager;
    App app(argc, argv, &appManager);
    return app.exec();
    qDebug() << "Applicazione chiusa";
}
