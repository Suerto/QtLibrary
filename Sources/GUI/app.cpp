#include "../../Headers/GUI/app.h"
#include "../../Headers/GUI/mainwindow.h"

#include "../../Headers/LogicModel/libro.h"
#include "../../Headers/LogicModel/manga.h"
#include "../../Headers/LogicModel/film.h"
#include "../../Headers/LogicModel/anime.h"

App::App(int& argc, char** argv) : QApplication(argc, argv) {
    MainWindow* main = new MainWindow();
   
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
