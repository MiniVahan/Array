#include "shape.hpp"

#include <cassert>

void test_operators()
{
	Rectangle test(1,2);
	Rectangle test2(1,2);
	Rectangle test3(110,20);
	Triangle t1;
	Triangle t2(110,20);
	t1 = t2;
	assert(t1.get_width()==t2.get_width());
	assert(test == test2);
	assert(test.get_width()==test2.get_width());
	assert(test.get_height()==test.get_height());
	test2 = test3;
	assert(test2 == test3);
}

void test_copy()
{
	Rectangle test(1,2);
	Rectangle test2(test);
	Circle c(5);
	Circle c2(c);
	assert(c==c2);
	assert(test.get_width()==1);
	assert(test.get_height()==2);
	assert(test == test2);
	assert(test.get_width()==test2.get_width());
	assert(test.get_height()==test.get_height());
	Triangle t1(110,20);
	Triangle t2(t1);
	assert(t1 == t2);
}

void test_set()
{
	Rectangle test(1,2);
	assert(test.get_width()==1);
	assert(test.get_height()==2);
}

int main()
{
	test_set();
	test_copy();
	test_operators();
	return 0;
}
