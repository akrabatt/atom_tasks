#ifndef EDGE_H
#define EDGE_H

#include "./point.h"

class Edge 
{
public:
	Point* from;	// ������ �����
	Point* to;		// ����� �����
	double weight;  // ��� �����
	bool directed;	// ����, ���������������� (true) ��� ��������������� (false).

	
	Edge(Point* form, Point* to, double weight, bool directed);	// �����������
	~Edge();	// ����������
};


#endif // !EDGE_H

