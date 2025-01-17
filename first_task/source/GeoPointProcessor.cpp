#include "../headders/GeoPointProcessor.h"
#include <iostream>
#include <thread>

//Конструктор
GeoPointProcessor::GeoPointProcessor()
    :done(false),
    gen(rd()),
    genSleepDist(200, 500),
    processSleepDist(100, 600),
    geoCoordDist(-90.0, 90.0) {
    std::cout << "\nthe object has been created\n";
}

    
// деструктор 
GeoPointProcessor::~GeoPointProcessor()
{
    stopProcessing();
    std::cout << "\nthe object has been deleted\n";
}


/**
* @brief запуск потоков для генерации и обработки данных
* @note создаются и запускаются два потока, один для генерации, второй для обработки
* 
*/
void GeoPointProcessor::startProcessing()
{
    producerThread = std::thread(&GeoPointProcessor::generateGeoPoints, this); 
    consumerThread = std::thread(&GeoPointProcessor::processGeoPoints, this);
}

/**
* @brief завершение работы потокв
* @note корректное завершение работы потов которые были запущены
* 
*/
void GeoPointProcessor::stopProcessing()
{
    done = true;
    dataCondition.notify_all(); // уведомляем все потоки о завершение работы
    if (producerThread.joinable()) { producerThread.join(); }
    if (consumerThread.joinable()) { consumerThread.join(); }
}

/**
* @brief метод для генерации точек 
* @note пока done != true выполняется генерация точки т.е. новые точки постоянно добавляются в очередь
*/
void GeoPointProcessor::generateGeoPoints()
{
    while (!done)
    {
        GeoPoint point1{ geoCoordDist(gen), geoCoordDist(gen) };    // сгенерили 1-ю точку
        GeoPoint point2{ geoCoordDist(gen), geoCoordDist(gen) };    // 2-ю точку

        {
            std::lock_guard<std::mutex> lock(queueMutex);   // "забронировали" доступ к контейнеру
            geoQueue.push({ point1, point2 });  // добавили и он освободится автоматически
        }
        dataCondition.notify_all(); // уведомляем поток обработки
        std::this_thread::sleep_for(std::chrono::milliseconds(genSleepDist(gen)));  // засыпаем на некоторе колличество времени сгенереного в диапазоне 
    }
}

/**
* @brief метод обработки геоточек
* @note пока done != true выполняется обработка новой точки
*/
void GeoPointProcessor::processGeoPoints()
{
    while (!done)
    {
        std::pair<GeoPoint, GeoPoint> points; // создаем пару для временного хранения точек
        {
            std::unique_lock<std::mutex> lock(queueMutex);  // бронируем 
            dataCondition.wait(lock, [this] {return !geoQueue.empty() || done; });  // Ждет, пока появятся данные или завершится производство

            if (geoQueue.empty() && done) {break;}

            points = geoQueue.front(); // переносим точки в локальную пару чтоб дальше с ней работать и освободить основную очередь
            geoQueue.pop(); // удаляем из основной очереди
        }
        int processTime = processSleepDist(gen);    // генерим рандомное время
        std::this_thread::sleep_for(std::chrono::milliseconds(processTime));    // засыпаем на это рандомное время

        std::cout << "Processed GeoPoints: \n"
            << "Point 1: (" << points.first.latitude << ", " << points.first.longtitude << ")\n"
            << "Point 2: (" << points.second.latitude << ", " << points.second.longtitude << ")\n"
            << "Processing Time: " << processTime << " ms\n" << std::endl;
    }
}


/**
*@brief метод по главному запуску
*@note данный метод регулирует длительность работы программы
*/
void GeoPointProcessor::runForDuration(std::chrono::seconds duration)
{
    startProcessing();  // запускаем потоки
    std::this_thread::sleep_for(duration);  // даем поработать опередленное время
    stopProcessing();   // останавливаем потоки и даем из завершить работу
}
