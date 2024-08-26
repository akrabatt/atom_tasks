#ifndef GRAPH_H
#define GRAPH_H

#include "./point.h"
#include "./edge.h"
#include <vector>
#include <unordered_map>
#include <limits>

class Graph
{
public:
	std::vector<Point> points;	// вектор с точками
	std::vector<Edge> edges;	// вектор ребер

	Graph();	// конструктор для созадния графа с случайным колличестов

	/**
	* @brief Метод для доавления ребра
	* 
	*/
	void addEdge(int fromId, int, toId, double weight, bool directed);

	/**
	* @brief метод для поиска кртчайшего пути от а до б методом дийкстры
	* 
	*/
	std::vector<Point> dijkstra(int startId, int endId);

	~Graph();	// деструктор
};


#endif	// GRAPH_H
