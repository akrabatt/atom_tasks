#include "graph.h"
#include <queue>
#include <random>

// �����������
Graph::Graph() 
{
    // ������������� ���������� ��������� �����
    std::random_device rd;
    std::mt19937 gen(rd());

    // ��������� ���������� ���������� ����� �� 100 �� 150
    std::uniform_int_distribution<> distN(100, 150);
    int N = distN(gen);

    // ��������� ���� ���������� �������
    for (int i = 0; i < N; ++i) 
    {
        points.emplace_back(i, rand() % 1000, rand() % 1000);
    }

    // ��������� ���������� ���������� ����� �� 230 �� 300
    std::uniform_int_distribution<> distE(230, 300);
    int E = distE(gen);

    // ��������� �����
    std::uniform_int_distribution<> distPoint(0, N - 1);
    std::uniform_real_distribution<> distWeight(1.0, 10.0);
    std::uniform_int_distribution<> distDir(0, 1);

    for (int i = 0; i < E; ++i) 
    {
        int fromId = distPoint(gen);    // ��������� �����
        int toId = distPoint(gen);      // ������� �����
        double weight = distWeight(gen);    // ���
        bool directed = distDir(gen) == 1;

        addEdge(fromId, toId, weight, directed);    // ������� ����� � ��������� ���
    }
}

// ����� ���������� ����� � ����
void Graph::addEdge(int fromId, int toId, double weight, bool directed) {
    Point* from = &points[fromId];  // ��������� ��������� �� ���������
    Point* to = &points[toId];  // �� ��������
    edges.emplace_back(from, to, weight, directed);

    if (!directed) 
    {
        edges.emplace_back(to, from, weight, directed);  // ��������� �������� ����� ��� ���������������� �����
    }
}

// �������� �������� ��� ������ ����������� ����
std::vector<Point> Graph::dijkstra(int startId, int endId) 
{
    // ������� ���-������� ��� �������� ����������� ���������� �� ��������� ����� �� ������ ������ �����
    std::unordered_map<int, double> distances;

    // ������� ���-������� ��� �������� ���������� ����� �� ���������� ����
    std::unordered_map<int, Point*> previous;

    // ������� � �����������, ��� ����������� ���������� ����� ������ ���������
    std::priority_queue<std::pair<double, Point*>, std::vector<std::pair<double, Point*>>, std::greater<>> pq;

    // �������������� ��� ���������� �� ������������� � ���������� ����� ��� nullptr
    for (auto& point : points) 
    {
        distances[point.id] = std::numeric_limits<double>::max(); // ������������� ��������� ���������� ��� �������������
        previous[point.id] = nullptr; // ��� ���������� ����� �� ����
    }

    // ���������� �� ��������� ����� ����� 0 (��� ���� ����)
    distances[startId] = 0.0;

    // ��������� ��������� ����� � ������� � ����������� � ����������� 0
    pq.push({ 0.0, &points[startId] });

    // ���� ������� �� �����, ���������� ������������ �����
    while (!pq.empty()) 
    {
        // ��������� ����� � ����������� ����������� �� �������
        auto [currentDistance, currentPoint] = pq.top();
        pq.pop(); // ������� ��� ����� �� �������

        // ���� �� �������� �������� �����, ��������� ����
        if (currentPoint->id == endId) break;

        // �������� �� ���� ������, ��������� �� ������� �����
        for (auto& edge : edges) 
        {
            // ���������, ���� ������� ����� ������� �� ������� �����
            if (edge.from->id == currentPoint->id) 
            {
                // ��������� ����� ��������� ����������� ���������� �� �������� �����
                double newDist = currentDistance + edge.weight;

                // ���� ������� ������� ���������� �� �������� �����, ��������� ���
                if (newDist < distances[edge.to->id]) 
                {
                    distances[edge.to->id] = newDist; // ��������� ����������� ����������
                    previous[edge.to->id] = currentPoint; // ��������� ���������� ����� �� ����

                    // ��������� �������� ����� � ����������� ����������� � �������
                    pq.push({ newDist, edge.to });
                }
            }
        }
    }

    // ��������������� ����, ������� � �������� �����, ���� ����� �� ���������� ������
    std::vector<Point> path;
    for (Point* at = &points[endId]; at != nullptr; at = previous[at->id]) 
    {
        path.push_back(*at); // ��������� ����� � ����
    }

    // ���� ����� ������������ � �������� �������, ������� �������������� ���
    std::reverse(path.begin(), path.end());

    // ���������� ���������� ���� ��� ������ �����
    return path;
}

// ����������
Graph::~Graph() {}
