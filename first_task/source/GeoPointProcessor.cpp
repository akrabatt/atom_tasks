#include "../headders/GeoPointProcessor.h"

//Конструктор
GeoPointProcessor::GeoPointProcessor()
    :done(false),
    gen(rd()),
    genSleepDist(200, 500),
    processSleepDist(100, 600),
    geoCoordDist(-90.0, 90.0) {}

    
// деструктор 
GeoPointProcessor::~GeoPointProcessor()
{
    stopProcessing();
}


// запус потоков для генерации и обработки данных
