#ifndef POINT_H
#define POINT_H

class Point 
{
public:
    int id;  // id �����
    int x, y;  // ���������� �����

    Point();  // ����������� �� ���������
    Point(int id, int x, int y);  // ����������� � �����������

    ~Point();  // ����������
};

#endif // POINT_H
