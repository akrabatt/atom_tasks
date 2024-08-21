#include <iostream>
#include <chrono>
#include <thread>
#include "./headders/GeoPointProcessor.h"

int main()
{
	GeoPointProcessor processor;	// создаем класс
	processor.startProcessing();	// запускаем генерацию координат

	std::this_thread::sleep_for(std::chrono::seconds(5));	// останавливаем поток main на 5 секунд

	processor.stopProcessing();	// останавливаем процесс
}
