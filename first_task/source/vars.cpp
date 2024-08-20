#include "../headders/vars.h"
#include <condition_variable>
#include <queue>
#include <random>
#include <utility>
#include <mutex>

// создаем две точки из наших структур {широта, долгота}
struct GeoPoint
{
    double latitude;
    double longitude;
}point1, point2;

//GeoPoint point1;
//GeoPoint point2;

// очередь для пары точек
std::queue<std::pair<GeoPoint, GeoPoint>> geoQueue;

// мьютекс для защиты доступа к очереди
std::mutex queueMutex;

// переменная для синхронизации потоков, уведомляет о добавлении 
std::condition_variable dataCondition;

// флаг завершеиня работы
bool done = false;

// генератор случайных числе
// хардвар
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> genSleepDist(200, 500);
std::uniform_int_distribution<> processSleepDist(100, 600);
std::uniform_real_distribution<> geoCoordDist(-90.0, 90.0);

