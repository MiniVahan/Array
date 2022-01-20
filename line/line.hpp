
#ifndef LINE_H
#define LINE_H

#include "point.hpp"

class Line
{
public:
	int length() const;
private:
	Point a;
	Point b;
public:
    Line();
    Line(const Point& a, const Point& b);
    Line(const Line& l);
	const Line& operator=(const Line& l);
};

#endif
