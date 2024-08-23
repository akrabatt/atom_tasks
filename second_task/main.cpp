#include <iostream>
#include "./headders/graph.h"
#include "./headders/point.h"
#include <thread>

int main()
{
	// ������� ����
	Graph graph;

	// ������������ ����� P
	Point P(500, 500);

	// ���������� ��� �������� ��������� �����
	Point R1, R2;

	// ��������� �����
	std::thread start_thread(&Graph::findClosestEdge, &graph, std::ref(P), std::ref(R1), std::ref(R2));

	// ������������ � ������� ����������
	start_thread.join();

	// ������� ���������
	std::cout << "R1: (" << R1.x << ", " << R1.y << ")\n";
	std::cout << "R2: (" << R2.x << ", " << R2.y << ")\n";

	return 0;
}