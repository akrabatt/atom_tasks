#include "edge.h"

// �����������
Edge::Edge(Point* from, Point* to, double weight, bool directed)
    : from(from), to(to), weight(weight), directed(directed) {}

// ����������
Edge::~Edge() {}
