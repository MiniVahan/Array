#include "shape.hpp"

#include <cassert>

void test_operators()
{
	Rectangle test(1,2);
	Rectangle test2(1,2);
	Rectangle test3(110,20);
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
	assert(test.get_width()==1);
	assert(test.get_height()==2);
	assert(test == test2);
	assert(test.get_width()==test2.get_width());
	assert(test.get_height()==test.get_height());
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
