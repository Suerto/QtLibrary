#include "../../Headers/GUI/app.h"
#include "../../Headers/GUI/mainwindow.h"

#include "../../Headers/LogicModel/libro.h"

App::App(int& argc, char** argv) : QApplication(argc, argv) {
    MainWindow* main = new MainWindow();
   
    //Per il salvataggio dei filtri generali dei contenuti all'interno della QCOmboBox
    JsonHandler::saveEnumToJson(Contenuto::getMappaLingue(), "Data/Dati.json" , "Lingue");

    JsonHandler::saveEnumToJson(Fisico::getMappaCopertine(), "Data/Dati.json", "Copertine");

    JsonHandler::saveEnumToJson(Libro::getMappaGeneri(), "Data/Dati.json", "Generi Libri");
    main->show();
}
