#include <iostream>
#include <cassert>
#include <cmath>
class Point
{
private:
	int x, y;
public:
	void setX(int);
	void setY(int);
	int getX();
	int getY();
public:
	Point();
	Point(int, int);
	Point(const Point& a);
	const Point& operator=(const Point& b);
};


class Line
{

public:
	int length();
private:
	Point a;
	Point b;
public:
    Line(Point, Point);
    Line(const Line& passedP);
	const Line& operator=(const Line& passedP);
};

Line::Line(Point passedA, Point passedB)
{
	std::cout << "Constructor - Line" << std::endl;
	a = passedA;
	b = passedB;
}

Line::Line(const Line& passedP)
{
	std::cout << "Copy constructor - Line" << std::endl;
	a = passedP.a;
	b = passedP.b;
}


const Line& Line::operator=(const Line& passedP)
{
	std::cout << "Assingment Operator - Line" << std::endl;
	if (this == &passedP){
		return *this;
	} else {
		a = passedP.a;
		b = passedP.b;
	}
	return *this;
}

int Line::length()
{
	return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY()-a.getY(),2));
}

Point::Point()
{
	std::cout << "Default constructor" << std::endl;
	x = 0;
	y = 0;
}

Point::Point(int passedX, int passedY)
{
	std::cout << "Constructor" << std::endl;
	x = passedX;
	y = passedY;
}

Point::Point(const Point& a)
{
	std::cout << "Copy constructor" << std::endl;
	x = a.x;
	y = a.y;
}

const Point& Point::operator=(const Point& b)
{
	std::cout << "Assingment Operator" << std::endl;
	if (this == &b){
		return *this;
	} else {
		x = b.x;
		y = b.y;
	}
	return *this;
}


void Point::setX(int passedX)
{
	x = passedX;
}


void Point::setY(int passedY)
{
	y = passedY;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}


int main()
{
	Point a(1,2);
	Point b;
	assert(a.getX() == 1);
	assert(a.getY() == 2);
	std::cout << a.getX() << std::endl;
	std::cout << a.getY() << std::endl;
	a.setX(4);
	a.setY(5);
	assert(a.getX() == 4);
	assert(a.getY() == 5);
	std::cout << a.getX() << std::endl;
	std::cout << a.getY() << std::endl;
	b.operator=(a);
	assert(b.getX() == 4);
	assert(b.getY() == 5);
	std::cout << b.getX() << std::endl;
	std::cout << b.getY() << std::endl;
	Point c(b);
	assert(c.getX() == 4);
	assert(c.getY() == 5);
	std::cout << c.getX() << std::endl;
	std::cout << c.getY() << std::endl;
	Point o(0,0);
	Line test(o,b);
	Line test_2(c,b);
	test_2.operator=(test);
	std::cout<<test.length()<<std::endl;
	return 0;
}
