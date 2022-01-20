
#include "point.hpp"

#include <iostream>

unsigned int Point::count = 0;

unsigned int Point::get_count()
{
    return count;
}

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

bool Point::operator==(const Point& b)
{
	if (this->x == b.x and this->y == b.y) {
		return true;
	}
	return false;
}

bool Point::operator!=(const Point& b)
{
	if (this->x == b.x and this->y == b.y) {
		return false;
	}
	return true;
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
    ++count;
}

Point::Point(int x, int y)
{
	std::cout << "Constructor" << std::endl;
	this->x = x;
	this->y = y;
    ++count;
}

Point::Point(const Point& a)
{
	std::cout << "Copy constructor" << std::endl;
	x = a.x;
	y = a.y;
    ++count;
}

Point::~Point()
{
	std::cout << "Destructor" << std::endl;
    --count;
}

