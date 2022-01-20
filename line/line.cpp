
#include "line.hpp"

#include <cmath>
#include <iostream>

Line::Line(const Point& a, const Point& b)
{
	std::cout << "Constructor - Line" << std::endl;
    Line::a = a;
    Line::b = b;
}

Line::Line(const Line& l)
{
	std::cout << "Copy constructor - Line" << std::endl;
	a = l.a;
	b = l.b;
}

const Line& Line::operator=(const Line& l)
{
	std::cout << "Assignment Operator - Line" << std::endl;
	if (this == &l) {
		return *this;
	}
    a = l.a;
    b = l.b;
	return *this;
}

int Line::length() const
{
	return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
}

