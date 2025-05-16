#include "Headers/GUI/app.h"

int main(int argc, char** argv) {
    ContentManager appManager;
    App app(argc, argv, &appManager);
    int end =  app.exec();
    
    appManager.uploadContenuti();

    return end;
}
