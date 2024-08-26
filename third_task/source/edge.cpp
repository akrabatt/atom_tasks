#include "edge.h"

// конструктор
Edge::Edge(Point* from, Point* to, double weight, bool directed)
    : from(from), to(to), weight(weight), directed(directed) {}

// деструктор
Edge::~Edge() {}
