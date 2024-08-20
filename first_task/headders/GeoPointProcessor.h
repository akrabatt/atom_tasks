#ifndef GEO_H
#define GEO_H

#include <queue>
#include <utility>
#include <mutex>
#include <condition_variable>
#include <random>
#include <thread>

/**
 * @brief класс для хранения и обработки геоточек
 *
 */
class GeoPointProcessor
{

public:

    // структура для храниния данных геоточек
    struct GeoPoint
    {
        double latitude;
        double longtitude;
    };

    // конструктор
    GeoPointProcessor();

    // деструктор
    ~GeoPointProcessor();
    
    // метод запуска обработки данных
    void startProcessing();

    // Остановка обработки данных
    void stopProcessing();

private:

    // очередь хранения пар геоточек
    std::queue<std::pair<GeoPoint, GeoPoint>>;

    // мьютекс 
    std::mutex queueMutex;

    // условная переменная для синхронизации потоков
    bool done;

    // потоки для генерации и обработки данных
    std::thread producerThread;
    std::thread consumerThread;

    // генератор случайных числе
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> genSleepDist;
    std::uniform_int_distribution<> processSleepDist;
    std::uniform_real_distribution<> geoCoordDist;

    // метод для генерации геоточек
    void generateGeoPoints();

    // метод для обработки геоточек
    void processGeoPoints();
};



#endif // GEO_H
