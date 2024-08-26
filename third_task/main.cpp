#include <iostream>
#include "graph.h"

int main() 
{
    // Создаем граф
    Graph graph;

    // выбираем две произвольные точки для поиска кратчайшего пути
    int startId = 0;  // например, начальная точка с id 0
    int endId = graph.points.size() - 1;  // конечная точка с последним id

    // находим кратчайший путь с использованием алгоритма Дейкстры
    std::vector<Point> shortestPath = graph.dijkstra(startId, endId);

    // выводим результат
    std::cout << "the shortest path from the point " << startId << " to point " << endId << ":\n";
    for (const auto& point : shortestPath) 
    {
        std::cout << "point " << point.id << " (" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
