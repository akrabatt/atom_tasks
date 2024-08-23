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
	int N = distN(gen);

	// �������� ��������� ���-�� ���������� ��� �����
	std::uniform_int_distribution<> distK(1, 5);
	int K = distK(gen);

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
			// ������� ������, ����� ����� ������� �������� ��������� ����� �������� �������
			// �������� �����������
			Point midpoint((points[i].x + points[j].x) / 2, (points[i].y + points[j].y) / 2);	// ��������� �������� �����

			// ��������� ���������� �� �������� ����� �� ����� ������������ �����
			double distance = P.distanceTo(midpoint);

			// �������� �������� �������� �� ������� ���������� ����������
			if (distance < minDistance)
			{
				minDistance = distance;	// ��������� ����������� ����������
				R1 = points[i];	// ��������� ���� �������� ����� ���� ��� ��������� �� ������� ����� 
				R2 = points[j];	// ���������� ��������� ����� �� ������������ �����
			}
		}
	}
}

