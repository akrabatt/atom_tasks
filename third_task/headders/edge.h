#ifndef EDGE_H
#define EDGE_H

#include "point.h"

class Edge 
{
public:
    Point* from;  // начальная точка ребра
    Point* to;    // конечная точка ребра
    double weight; // вес ребра
    bool directed; // флаг, указывающий, является ли ребро однонаправленным

    Edge(Point* from, Point* to, double weight, bool directed);  // конструктор

    ~Edge();  // деструктор
};

#endif // EDGE_H
