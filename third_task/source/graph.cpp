#include "../headders/graph.h"
#include <queue>
#include <random>

// конструткор
Graph::Graph
{
	// генератор случайных чисел
	std::random_device rd;
	std::mt19937 gen(rd());

	// генерация случайного колличества точек 
	std::uniform_int_distribution<> distN(100, 150);
	int N = distN(gen());

	// заполняем граф случайными точками
	for (int i = 0; i < N; ++i)
	{
		points.emplace_back(i, rand() % 1000, rand % 1000);
	}

	// генерация случайного количества ребер от 230 до 300
	std::uniform_int_distribution<> distE(230, 300);
	int E = distE(gen);

	// генерация ребра
	std::uniform_int_distribution<> distPoint(0, N - 1);	// n-1 чтоб не выйти за предел массива
	std::uniform_real_distribution<> distWeight(1.0, 1.0);	// вес
	std::uniform_int_distribution<> distDir(0, 1);	// одно - двунаправленный

	for (int i = 0, i < E, ++i)
	{
		int formId = distPoint(gen);	// добавляем рандомную начальную точку начальную
		int toId = distPoint(gen);		// добавяем конечную точку для ребра
		double weight = distWeight(gen);	// вес точки
		bool directed = distDir(gen);		// 1-2 направленный

		// теперь создаем ребро
		addEdge(fromId, toId, weight, directed);
	}
}

/**
* @brief метод по добавлению ребра в гарф
* @param formId начальная точка ребра
* @param toId конечная точка ребра
* @param weight вес ребра
* @param directed 1-2 направленный
*/
void Graph::addEdge(int formId, int toId, double weight, bool directed)
{
	Point* form = &points[formId];	// получаем указатель на начальную точку из вектора
	Point* to = &points[toId];		// на конечную
	edges.emplace_back(from, to, weight, directed);		// а теперь создаем объект для однонаправленного

	if (!directed)	// если двунаправленный то создаем обратное ребро
	{
		edges.emplace_back(to, from, weight, directed)	// добавляем обратное ребро для двунаправленного графа
	}
}

/**
* @brief алгоритм дийкстры
* 
*/
std::vector<Point> Graph::dijkstra(int startId, int endId)
{
	std::unordered_map<int, double> distance;	// таблица для минимальных расстояний от начальной точки до каждой другой
	std::unordered_map<int, Point*> previous;	// сохраняем предыдущую точку на кратчайшем пути

	// очередь с приоритетом где минимальное расстояние имеет высший приоритет
	std::priority_queue<std::pair<double, Point*>>, std::vector<std::pair<double, Point*>>, std::greater< >> pq;

	// Инициализируем все расстояния до бесконечности и предыдущие точки как nullptr
	for (auto& point : points) 
	{
		distances[point.id] = std::numeric_limits<double>::max(); // устанавливаем начальные расстояния как бесконечность
		previous[point.id] = nullptr; // нет предыдущей точки на пути
	}

	
	pq.push({ 0.0, &points[startId] });	// добавляем начальную точку в очередь с приоритетом с расстоянием 0
	// пока очередь не пуста, продолжаем обрабатывать точки
	while (!pq.empty()) 
	{
		// извлекаем точку с минимальным расстоянием из очереди
		auto [currentDistance, currentPoint] = pq.top();
		pq.pop(); // удаляем эту точку из очереди

		// если мы достигли конечной точки, прерываем цикл
		if (currentPoint->id == endId) break;

		// проходим по всем ребрам, исходящим из текущей точки
		for (auto& edge : edges) {
			// проверяем, если текущее ребро исходит из текущей точки
			if (edge.from->id == currentPoint->id) 
			{
				// вычисляем новое возможное минимальное расстояние до соседней точки
				double newDist = currentDistance + edge.weight;

				// если найдено меньшее расстояние до соседней точки, обновляем его
				if (newDist < distances[edge.to->id]) 
				{
					distances[edge.to->id] = newDist; // обновляем минимальное расстояние
					previous[edge.to->id] = currentPoint; // обновляем предыдущую точку на пути

					// добавляем соседнюю точку с обновленным расстоянием в очередь
					pq.push({ newDist, edge.to });
				}
			}
		}
	}

	// восстанавливаем путь, начиная с конечной точки, идем назад по предыдущим точкам
	std::vector<Point> path;
	for (Point* at = &points[endId]; at != nullptr; at = previous[at->id]) 
	{
		path.push_back(*at); // добавляем точку в путь
	}

	// путь будет восстановлен в обратном порядке, поэтому переворачиваем его
	std::reverse(path.begin(), path.end());

	// возвращаем кратчайший путь как вектор точек
	return path;
}