#ifndef GRAPH_H
#define GRAPH_H

#include "point.h"
#include "edge.h"
#include <vector>
#include <unordered_map>
#include <limits>

class Graph 
{
public:
    std::vector<Point> points;  // список всех точек 
    std::vector<Edge> edges;    // список всех ребер

    Graph();  // конструктор для создания графа с случайным количеством точек и ребер

    void addEdge(int fromId, int toId, double weight, bool directed);  // метод для добавления ребра
    std::vector<Point> dijkstra(int startId, int endId);  // метод для поиска кратчайшего пути от точки A до точки B

    ~Graph();  // деструктор
};

#endif // GRAPH_H
