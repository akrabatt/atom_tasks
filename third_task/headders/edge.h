#ifndef EDGE_H
#define EDGE_H

#include "./point.h"

class Edge 
{
public:
	Point* from;	// начало ребра
	Point* to;		// конец ребра
	double weight;  // вес ребра
	bool directed;	// флаг, однонаправленный (true) или двунаправленный (false).

	
	Edge(Point* form, Point* to, double weight, bool directed);	// конструктор
	~Edge();	// деструктор
};


#endif // !EDGE_H

