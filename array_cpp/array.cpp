#include <iostream>
#include <cassert>

#include "array.hpp"

template <typename T>
typename array<T>::size_type array<T>::size()
{
	return m_size;
}

template <typename T>
void array<T>::insert(array<T>::size_type index, array<T>::element_type value)
{
	assert(index >= 0);
	assert(index <= m_size);
	m_size = m_size + 1;
	array<T>::element_type* tmp = new array<T>::element_type[m_size];
	for (array<T>::size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
	tmp[index] = value;
	for (array<T>::size_type i = index + 1; i < m_size; ++i) {
		tmp[i] = m_start[i - 1];
	}
    if (m_start != nullptr) {
        delete [] m_start;
    }
	m_start = tmp;
}

template <typename T>
bool array<T>::empty()
{
    assert(m_size >= 0);
	return m_size == 0;
}

template <typename T>
T array<T>::access(array<T>::size_type index)
{
	assert(index >= 0);
	assert(index < m_size);
    assert(m_start != nullptr);
	return m_start[index];
}

template <typename T>
void array<T>::array_remove(array<T>::size_type index)
{
	assert(index >= 0);
	assert(index <= m_size);
	array<T>::element_type* tmp = new array<T>::element_type[m_size-1];
	for (array<T>::size_type i = 0; i < index; ++i) {
		tmp[i] = m_start[i];
	}
	for (array<T>::size_type i = index + 1; i < m_size; ++i) {
		tmp[i-1] = m_start[i];
	}
	m_size = m_size - 1;
	m_start = tmp;
}

template <typename T>
void array<T>::array_modify(array<T>::size_type index, array<T>::element_type value)
{
	assert(index <= m_size);
	assert(index >= 0);
	m_start[index] = value;
}

template <typename T>
void array<T>::print_elements()
{
	for (array<T>::size_type i = 0; i < m_size; ++i)  {
        std::cout << "a[" << i << "] = " << access(i) << std::endl;
	}
}


template <typename T>
array<T>::array()
{
    std::cout << "Default constructor" << std::endl;
	m_size = 0;
	m_start = nullptr;
}

template <typename T>
array<T>::array(array<T>::size_type n,array<T>::element_type default_value)
{
	assert(n>0);
    std::cout << "Constructor" << std::endl;
	m_size = 0;
	m_size = n;
	m_start = new  array<T>::element_type[n];
	for (array<T>::size_type i = 0; i < m_size; ++i) {
		m_start[i] = default_value;
	}
}

template <typename T>
array<T>::~array()
{
    std::cout << "Destructor" << std::endl;
    if (m_start != nullptr) {
        delete [] m_start;
    }
}
