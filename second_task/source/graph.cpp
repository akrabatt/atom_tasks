#include "../headders/graph.h"
#include <random>
#include <limits>

// ����������� �����
Graph::Graph()
{
	// ����� �������������� ��������� ��������� �����
	std::random_device rd;	// ���������� 
	std::mt19937 gen(rd());	// �������� 

	// �������� ��������� ���-�� �����
	std::uniform_int_distribution<> distN(50, 100);
	int N = disN(gen);

	// �������� ��������� ���-�� ���������� ��� �����
	std::uniform_int_distribution<> distK(1, 5);
	int K = disK(gen);

	// ������������� ����� ��� ������ ����� � ����� �������
	points.reserve(N);

	// ��������� ��������� ����� �� ��������� �.�. �� ��
	std::uniform_int_distribution<> distCoord(0, 999); // ������� ��� x � ��� y
	for (int i = 0; i < N; i++)
	{
		points.emplace_back(distCoord(gen), distCoord(gen));
	}
}


/**
 * @brief ����� ������ ���������� �����
 * @note P ����� � ������� ���� ��������� �����(������ �� ������ Point)
 * @note R1 R2 � ��� ����� ����� �������� ���������� ��������� �����
 */
void Graph::findClosestEdge(const Point& P, Point& R1, Point& R2)
{
	double minDistance = std::numeric_limits<double>::max();	// �������������� ����� ������� ������ ���� ������ ��� ��� ����� ���������� �������� ������, ��� ���������� �����������
	for (size_t i = 0; i < points.size(); ++i)	// �������� ������ ����� �������
	{
		for (size_t j = i + 1; j < points.size(); ++j)	// �������� ������ ����� ������� ��� ����� �������� �����
		{

		}
	}
}