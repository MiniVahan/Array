#include "point.hpp"
#include "line.hpp"

#include <iostream>
#include <cassert>

int main()
{
	Point a(1, 2);
	Point b;
	assert(a.getX() == 1);
	assert(a.getY() == 2);
	a.setX(4);
	a.setY(5);
	assert(a.getX() == 4);
	assert(a.getY() == 5);
	b = a;
	assert(b.getX() == 4);
	assert(b.getY() == 5);
	Point c(b);
	assert(c.getX() == 4);
	assert(c.getY() == 5);
	Point o(0, 0);
	Line l(o, b);
	Line l2(c, b);
	l2 = l;
    assert(l.length() == l2.length());
	assert(a == b);
	assert(a != o);
	return 0;
}
