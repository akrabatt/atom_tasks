#include <iostream>
#include <chrono>
#include <thread>
#include "./headders/GeoPointProcessor.h"

int main()
{
	GeoPointProcessor processor;	// создаем 
	processor.runForDuration(std::chrono::seconds(1));	// запускаем
}
