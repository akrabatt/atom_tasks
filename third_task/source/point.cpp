#include "../headders/point.h"

Point::Point() : x(0), y(0), id(0) {}		// ����������� �� ���������
Point::Point(int x, int y, int id) : x(x), y(y), id(id) {}	// ������������������� �����������

Point::~Point(){}	// ����������