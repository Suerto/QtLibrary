#include "../../Headers/GUI/app.h"
#include "../../Headers/GUI/mainwindow.h"

App::App(int& argc, char** argv, ContentManager* mngr) : QApplication(argc, argv), main(new MainWindow(nullptr, mngr)) {
    //Per il salvataggio dei filtri generali dei contenuti all'interno della QCOmboBox
    JsonHandler::saveEnumToJson(Contenuto::getMappaLingue(), "Data/Dati.json" , "Lingue");

    JsonHandler::saveEnumToJson(Fisico::getMappaCopertine(), "Data/Dati.json", "Copertine");
    
    JsonHandler::saveEnumToJson(Periodico::getMappaCadenze(), "Data/Dati.json", "Cadenze");

    JsonHandler::saveEnumToJson(Digitale::getMappaRisoluzioni(), "Data/Dati.json", "Risoluzioni");

    JsonHandler::saveEnumToJson(Libro::getMappaGeneri(), "Data/Dati.json", "Generi Libri");
    
    JsonHandler::saveEnumToJson(Manga::getMappaGeneri(), "Data/Dati.json", "Generi Manga");

    JsonHandler::saveEnumToJson(Film::getMappaGeneri(), "Data/Dati.json", "Generi Film");
    
    JsonHandler::saveEnumToJson(Anime::getMappaGeneri(), "Data/Dati.json", "Generi Anime");
    main->show();
}
