#ifndef POINT_H
#define POINT_H

class Point 
{
public:
    int id;  // id точки
    int x, y;  // координаты точки

    Point();  // конструктор по умолчанию
    Point(int id, int x, int y);  // конструктор с параметрами

    ~Point();  // деструктор
};

#endif // POINT_H
