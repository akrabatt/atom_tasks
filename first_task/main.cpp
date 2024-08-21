#include <iostream>
#include <chrono>
#include <thread>
#include "./headders/GeoPointProcessor.h"

int main()
{
	GeoPointProcessor processor;	// ������� ������
	processor.startProcessing();	// ���������

	std::this_thread::sleep_for(std::chrono::seconds(5));	// main ���� 5 ������

	processor.stopProcessing();	// ������������� ���������
}
