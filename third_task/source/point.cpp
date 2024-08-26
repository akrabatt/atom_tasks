#include "point.h"

// конструктор по умолчанию
Point::Point() : id(0), x(0), y(0) {}

// конструктор с параметрами
Point::Point(int id, int x, int y) : id(id), x(x), y(y) {}

// деструктор
Point::~Point() {}
