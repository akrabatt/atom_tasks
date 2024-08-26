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
	std::vector<Point> points;	// ������ � �������
	std::vector<Edge> edges;	// ������ �����

	Graph();	// ����������� ��� �������� ����� � ��������� �����������

	/**
	* @brief ����� ��� ��������� �����
	* 
	*/
	void addEdge(int fromId, int, toId, double weight, bool directed);

	/**
	* @brief ����� ��� ������ ���������� ���� �� � �� � ������� ��������
	* 
	*/
	std::vector<Point> dijkstra(int startId, int endId);

	~Graph();	// ����������
};


#endif	// GRAPH_H
