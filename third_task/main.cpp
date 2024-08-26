#include <iostream>
#include "graph.h"

int main() 
{
    // ������� ����
    Graph graph;

    // �������� ��� ������������ ����� ��� ������ ����������� ����
    int startId = 0;  // ��������, ��������� ����� � id 0
    int endId = graph.points.size() - 1;  // �������� ����� � ��������� id

    // ������� ���������� ���� � �������������� ��������� ��������
    std::vector<Point> shortestPath = graph.dijkstra(startId, endId);

    // ������� ���������
    std::cout << "the shortest path from the point " << startId << " to point " << endId << ":\n";
    for (const auto& point : shortestPath) 
    {
        std::cout << "point " << point.id << " (" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
