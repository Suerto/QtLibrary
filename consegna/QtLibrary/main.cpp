#include "Headers/GUI/app.h"

int main(int argc, char** argv) {
    qputenv("QT_QPA_PLATFORM", "xcb");
    ContentManager appManager;
    App app(argc, argv, &appManager);
    return app.exec();
}
