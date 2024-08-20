#ifndef VARS_H
#define VARS_H

// долгота и широта
#include <condition_variable>
#include <queue>
#include <utility>
#include <mutex>
#include <random>

struct GeoPoint;

extern GeoPoint point1, point2;

// экспортируем очередь для точек
extern std::queue<std::pair<GeoPoint, GeoPoint>> geoQueue;

// экспорт мьютекса для зациты доступа к очереди
extern std::mutex queueMutex;

// экспорт условной переменной о добавлении
extern std::condition_variable dataCondition;

// флаг завершения работы
extern bool done;


// генератор
extern std::random_device rd;
extern std::mt19937 gen;
extern std::uniform_int_distribution<> genSleepDist;
extern std::uniform_int_distribution<> processSleepDist;
extern std::uniform_real_distribution<> geoCoordDist;

#endif // VARS_H
