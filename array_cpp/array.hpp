#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class array
{
public:
    typedef T element_type;
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

#endif
