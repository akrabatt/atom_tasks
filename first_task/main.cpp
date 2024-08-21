#include <iostream>
#include <chrono>
#include <thread>
#include "./headders/GeoPointProcessor.h"

int main()
{
	GeoPointProcessor processor;	// создаем объект
	processor.startProcessing();	// запускаем

	std::this_thread::sleep_for(std::chrono::seconds(5));	// main ждет 5 секунд

	processor.stopProcessing();	// останавливаем обработку
}
