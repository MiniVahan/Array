
#include "point.hpp"

#include <iostream>

void Point::setX(int d)
{
	x = d;
}

void Point::setY(int d)
{
	y = d;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

const Point& Point::operator=(const Point& b)
{
	std::cout << "Assignment Operator" << std::endl;
	if (this == &b) {
		return *this;
	}
    x = b.x;
    y = b.y;
	return *this;
}

Point::Point()
{
	std::cout << "Default constructor" << std::endl;
	x = 0;
	y = 0;
}

Point::Point(int x, int y)
{
	std::cout << "Constructor" << std::endl;
	this->x = x;
	this->y = y;
}

Point::Point(const Point& a)
{
	std::cout << "Copy constructor" << std::endl;
	x = a.x;
	y = a.y;
}

