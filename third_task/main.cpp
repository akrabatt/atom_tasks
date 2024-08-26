#include <iostream>
#include "Graph.h"

int main() 
{
    // создаем граф
    Graph graph;

    // выбираем две произвольные точки для поиска кратчайшего пути
    int startId = 0;  // например начальная точка с id 0
    int endId = graph.points.size() - 1;  // конечная точка с последним id

    // находим кратчайший путь с использованием алгоритма дейкстры
    std::vector<Point> shortestPath = graph.dijkstra(startId, endId);

    // выводим результат
    std::cout << "Кратчайший путь из точки " << startId << " в точку " << endId << ":\n";
    for (const auto& point : shortestPath) 
    {
        std::cout << "Точка " << point.id << " (" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
