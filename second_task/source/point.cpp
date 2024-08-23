#include "../headders/point.h"
#include <cmath> // для функции sqrt


// конструктор по умолчанию
Point::Point() : x(0), y(0) {}

// конструктор с параметрами
Point::Point(int x, int y) : x(x), y(y) {}

/**
* @brief метод вычисления расстояние до другой точки
* @param Point ссылка на другой объект
* @note данный метод реализует вычисление уравнения евклидова расстояния
*/
double Point::distanceTo(const Point& other) const
{
    return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y)); // a^2 = a * a (евклидово расстояние)
}
