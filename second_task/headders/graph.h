#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "../headders/point.h"

/**
 * @brief класс графа
 *
 */
class Graph
{
public:
    // вектор список точек графа N
    std::vector<Point> points;

    // колличество соединений каждой точки
    int K; 

    // конструктор по умолчанию
    Graph();

    /**
     * @brief метод поиска ближайшего ребра
     * @note P точка к которой ищем ближайшее ребро(ссылка на объект Point)
     * @note R1 R2 в эти точки будут записаны координаты ближайших ребер
     */
    void findClosestEdge(const Point& P, Point& R1, Point& R2);
};
#endif // GRAPH_H
