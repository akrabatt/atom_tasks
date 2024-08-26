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
    std::vector<Point> points;  // ������ ���� ����� 
    std::vector<Edge> edges;    // ������ ���� �����

    Graph();  // ����������� ��� �������� ����� � ��������� ����������� ����� � �����

    void addEdge(int fromId, int toId, double weight, bool directed);  // ����� ��� ���������� �����
    std::vector<Point> dijkstra(int startId, int endId);  // ����� ��� ������ ����������� ���� �� ����� A �� ����� B

    ~Graph();  // ����������
};

#endif // GRAPH_H
