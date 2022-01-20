
#include "line.hpp"

#include <cmath>
#include <iostream>

Line::Line()
    : a(0, 0)
    , b(0, 0)
{
	std::cout << "Default Constructor - Line" << std::endl;
}

Line::Line(const Point& s, const Point& e)
    : a(s)
    , b(e)
{
	std::cout << "Constructor - Line" << std::endl;
}

Line::Line(const Line& l)
	: a(l.a)
	, b(l.b)
{
	std::cout << "Copy constructor - Line" << std::endl;
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

