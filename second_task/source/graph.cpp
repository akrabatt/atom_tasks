#include "../headders/graph.h"
#include <random>
#include <limits>

// конструктор графа
Graph::Graph()
{
	// сразу инициализируем генератор случайных чисел
	std::random_device rd;	// внутренний 
	std::mt19937 gen(rd());	// алгоритм 

	// сгенерим случайное кол-во точек
	std::uniform_int_distribution<> distN(50, 100);
	int N = disN(gen);

	// сгенерим случайное кол-во соединений для точки
	std::uniform_int_distribution<> distK(1, 5);
	int K = disK(gen);

	// зарезервируем место для списка точек в нашем векторе
	points.reserve(N);

	// расставим случайные точки на плоскости т.е. на ХУ
	std::uniform_int_distribution<> distCoord(0, 999); // отрезок для x и для y
	for (int i = 0; i < N; i++)
	{
		points.emplace_back(distCoord(gen), distCoord(gen));
	}
}


/**
 * @brief метод поиска ближайшего ребра
 * @note P точка к которой ищем ближайшее ребро(ссылка на объект Point)
 * @note R1 R2 в эти точки будут записаны координаты ближайших ребер
 */
void Graph::findClosestEdge(const Point& P, Point& R1, Point& R2)
{
	double minDistance = std::numeric_limits<double>::max();	// инициализируем самым большим числом чтоб каждый раз как будет находиться значение меньше, эта переменная обновлялась
	for (size_t i = 0; i < points.size(); ++i)	// выбираем первую точку отрезка
	{
		for (size_t j = i + 1; j < points.size(); ++j)	// выбираем вторую точку отрезка тем самым образуем ребро
		{

		}
	}
}