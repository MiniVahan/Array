#include <iostream>
#include <cassert>

#include "array.hpp"
#include "array.cpp"

void test_1()
{
    array<double> a(4, 0);
    assert(a.size() == 4);
    assert(! a.empty());
    assert(a.access(0) == 0);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
	a.insert(a.size(), 8);
	a.insert(a.size(), 9);
    assert(a.size() == 6);
    assert(a.access(0) == 0);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
    assert(a.access(4) == 8);
    assert(a.access(5) == 9);
	a.insert(0, 5);
    assert(a.size() == 7);
    assert(a.access(0) == 5);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
    assert(a.access(4) == 0);
    assert(a.access(5) == 8);
    assert(a.access(6) == 9);
	a.insert(5, 15);
    assert(a.size() == 8);
    assert(a.access(0) == 5);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
    assert(a.access(3) == 0);
    assert(a.access(4) == 0);
    assert(a.access(5) == 15);
    assert(a.access(6) == 8);
    assert(a.access(7) == 9);
	a.print_elements();
}


void test_2()
{
	array<int> b;
    assert(b.size() == 0);
    assert(b.empty());
}

void test_3()
{
	array<int>* c = new array<int>(5, 8);
    assert(c->size() == 5);
    assert((*c).size() == 5);
    assert(! c->empty());
	delete c;
}

void test_4()
{
	array<float>* d = new array<float>[5];
    assert(d[0].size() == 0);
    assert(d[1].size() == 0);
    assert(d[2].size() == 0);
    assert(d[3].size() == 0);
    assert(d[4].size() == 0);
    for (int i = 0; i < 5; ++i) {
        assert(d[i].empty());
    }
	delete [] d;
}

int main()
{
    test_1();
    test_2();
    test_3();
    test_4();
	array<unsigned int> a(3,0);
    assert(a.size() == 3);
    assert(a.access(0) == 0);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
	a.array_modify(2,100);
    assert(a.size() == 3);
    assert(a.access(0) == 0);
    assert(a.access(1) == 0);
    assert(a.access(2) == 100);
	a.array_remove(1);
    assert(a.size() == 2);
    assert(a.access(0) == 0);
    assert(a.access(1) == 100);
	a.insert(2,150);
	a.insert(3,200);
    assert(a.size() == 4);
    assert(a.access(0) == 0);
    assert(a.access(1) == 100);
    assert(a.access(2) == 150);
    assert(a.access(3) == 200);
	return 0;
}
