#include <iostream>
#include <cassert>

class array
{
public:
    typedef int element_type;
    typedef unsigned int size_type;

public:
    size_type size();
    bool empty();
    element_type access(size_type index);
    void insert(size_type index, element_type value);
	void array_remove(size_type index);
	void array_modify(size_type index, element_type value);
	void print_elements();

private:
	element_type* m_start;
	size_type m_size;

public:
    array();
    array(size_type n, element_type default_value);
    ~array();
};

array::size_type array::size()
{
	return m_size;
}

array::array()
{
    std::cout << "Default constructor" << std::endl;
	m_size = 0;
	m_start = nullptr;
}

array::array(size_type n, element_type default_value)
{
	assert(n>0);
    std::cout << "Constructor" << std::endl;
	m_size = 0;
	m_size = n;
	m_start = new element_type[n];
	for (size_type i = 0; i < m_size; ++i) {
		m_start[i] = default_value;
	}
}

array::~array()
{
    std::cout << "Destructor" << std::endl;
    if (m_start != nullptr) {
        delete [] m_start;
    }
}

void array::insert(size_type index, element_type value)
{
	assert(index >= 0);
	assert(index <= m_size);
	m_size = m_size + 1;
	element_type* tmp = new element_type[m_size];
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
	tmp[index] = value;
	for (size_type i = index + 1; i < m_size; ++i) {
		tmp[i] = m_start[i - 1];
	}
    if (m_start != nullptr) {
        delete [] m_start;
    }
	m_start = tmp;
}

bool array::empty()
{
    assert(m_size >= 0);
	return m_size == 0;
}

array::element_type array::access(array::size_type index)
{
	assert(index >= 0);
	assert(index < m_size);
    assert(m_start != nullptr);
	return m_start[index];
}

void test_1()
{
    array a(4, 0);
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
	for (array::size_type i = 0; i < a.size(); ++i)  {
        std::cout << "a[" << i << "]" << a.access(i) << std::endl;
	}
}


void array::array_remove(size_type index)
{
	assert(index >= 0);
	assert(index <= m_size);
	element_type* tmp = new element_type[m_size-1];
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
	for (size_type i = index + 1; i < m_size; ++i) {
		tmp[i-1] = m_start[i];
	}
	m_size = m_size - 1;
	m_start = tmp;
}

void array::array_modify(size_type index, element_type value)
{
	assert(index <= m_size);
	assert(index >= 0);
	m_start[index] = value;
}

void test_2()
{
	array b;
    assert(b.size() == 0);
    assert(b.empty());
}

void test_3()
{
	array* c = new array(5, 8);
    assert(c->size() == 5);
    assert((*c).size() == 5);
    assert(! c->empty());
	delete c;
}

void test_4()
{
	array* d = new array[5];
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

void array::print_elements()
{
	for (size_type i = 0; i < m_size; ++i)  {
		printf("a[%d] = %d\n", i, *(m_start+i));
	}
}


int main()
{
    //test_1();
    //test_2();
    //test_3();
    //test_4();
	array a(3,0);
	a.print_elements();
    assert(a.size() == 3);
    assert(a.access(0) == 0);
    assert(a.access(1) == 0);
    assert(a.access(2) == 0);
	a.array_modify(2,100);
	a.print_elements();
    assert(a.size() == 3);
    assert(a.access(0) == 0);
    assert(a.access(1) == 0);
    assert(a.access(2) == 100);
	a.array_remove(1);
	a.print_elements();
    assert(a.size() == 2);
    assert(a.access(0) == 0);
    assert(a.access(1) == 100);
	a.insert(2,150);
	a.insert(3,200);
	a.print_elements();
    assert(a.size() == 4);
    assert(a.access(0) == 0);
    assert(a.access(1) == 100);
    assert(a.access(2) == 150);
    assert(a.access(3) == 200);
	return 0;
}
