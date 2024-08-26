#include "graph.h"
#include <queue>
#include <random>

// конструктор
Graph::Graph() 
{
    // инициализация генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());

    // генерация случайного количества точек от 100 до 150
    std::uniform_int_distribution<> distN(100, 150);
    int N = distN(gen);

    // заполняем граф случайными точками
    for (int i = 0; i < N; ++i) 
    {
        points.emplace_back(i, rand() % 1000, rand() % 1000);
    }

    // генерация случайного количества ребер от 230 до 300
    std::uniform_int_distribution<> distE(230, 300);
    int E = distE(gen);

    // генерация ребер
    std::uniform_int_distribution<> distPoint(0, N - 1);    // n - 1 чтоб не вылететь за предел
    std::uniform_real_distribution<> distWeight(1.0, 10.0);
    std::uniform_int_distribution<> distDir(0, 1);

    for (int i = 0; i < E; ++i) 
    {
        int fromId = distPoint(gen);    // начальную точку
        int toId = distPoint(gen);      // кончную точку
        double weight = distWeight(gen);    // вес
        bool directed = distDir(gen) == 1;

        addEdge(fromId, toId, weight, directed);    // создаем ребро и добавляем его
    }
}

/**
* @brief метод добавления ребра в граф
* 
*/ 
void Graph::addEdge(int fromId, int toId, double weight, bool directed) {
    Point* from = &points[fromId];  // извлекаем указатель на начальную
    Point* to = &points[toId];  // на конечную
    edges.emplace_back(from, to, weight, directed);

    if (!directed) 
    {
        edges.emplace_back(to, from, weight, directed);  // добавляем обратное ребро для двунаправленного графа
    }
}

/**
* @brief метод дийкстры
* 
*/
std::vector<Point> Graph::dijkstra(int startId, int endId) 
{
    // cоздаем хеш-таблицу для хранения минимальных расстояний от начальной точки до каждой другой точки
    std::unordered_map<int, double> distances;

    // cоздаем хеш-таблицу для хранения предыдущей точки на кратчайшем пути
    std::unordered_map<int, Point*> previous;

    // очередь с приоритетом, где минимальное расстояние имеет высший приоритет
    std::priority_queue<std::pair<double, Point*>, std::vector<std::pair<double, Point*>>, std::greater<>> pq;

    // иициализируем все расстояния до бесконечности и предыдущие точки как nullptr
    for (auto& point : points) 
    {
        distances[point.id] = std::numeric_limits<double>::max(); // устанавливаем начальные расстояния как бесконечность
        previous[point.id] = nullptr; // нет предыдущей точки на пути
    }

    // расстояние до начальной точки равно 0 (она сама себе)
    distances[startId] = 0.0;

    // добавляем начальную точку в очередь с приоритетом с расстоянием 0
    pq.push({ 0.0, &points[startId] });

    // пока очередь не пуста, продолжаем обрабатывать точки
    while (!pq.empty()) 
    {
        // извлекаем точку с минимальным расстоянием из очереди
        auto [currentDistance, currentPoint] = pq.top();
        pq.pop(); // Удаляем эту точку из очереди

        // усли мы достигли конечной точки, прерываем цикл
        if (currentPoint->id == endId) break;

        // проходим по всем ребрам, исходящим из текущей точки
        for (auto& edge : edges) 
        {
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

// деструктор
Graph::~Graph() {}
