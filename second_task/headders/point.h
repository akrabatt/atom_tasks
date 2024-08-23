#ifndef POINT_H
#define POINT_H

/**
 *@brief класс точки на координатной плоскости
 *
 */
class Point
{
public:
    // координаты точки
    int x, y; 

    // конструктор по умолчанию
    Point();
    // конструктор с параметрами
    Point(int x, int y);
    // деструктор
    //~Point();

    /**
    * @brief метод вычисления расстояние до другой точки
    * @param Point ссылка на другой объект
    * @note данный метод реализует вычисление уравнения евклидова расстояния
    */
    double distanceTo(const Point& other) const;
};
#endif // POINT_H
