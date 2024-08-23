#include <iostream>
#include "./headders/graph.h"
#include "./headders/point.h"
#include <thread>

int main()
{
	// создаем граф
	Graph graph;

	// произвольная точка P
	Point P(500, 500);

	// переменные для хранения ближайших точек
	Point R1, R2;

	// запускаем поток
	std::thread start_thread(&Graph::findClosestEdge, &graph, std::ref(P), std::ref(R1), std::ref(R2));

	// присоединяем и ожидаем завершения
	start_thread.join();

	// выводим результат
	std::cout << "R1: (" << R1.x << ", " << R1.y << ")\n";
	std::cout << "R2: (" << R2.x << ", " << R2.y << ")\n";

	return 0;
}