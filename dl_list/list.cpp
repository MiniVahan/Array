#include "list.hpp"

#include <iostream>
#include <cassert>

class list::node
{
public:
    value_type m_value;
    node* m_next;
    node* m_prev;

public:
    node(value_type v, node* n, node* p)
        : m_value(v)
        , m_next(n)
		, m_prev(p)
    {
    }

    ~node()
    {
    }
};

std::ostream& operator<<(std::ostream& out, const list& l)
{
    list::node* current = l.m_head;
    while (current != nullptr) {
        out << current->m_value << " ";
        current = current->m_next;
    }
    return out;
}

list::size_type list::size() const
{
    node* current = m_head;
    size_type count = 0;
    while (current != nullptr) {
        current = current->m_next;
        ++count;
    }
    return count;
}

bool list::empty() const
{
    return (m_head == nullptr);
}


void list::push_front(const value_type& value)
{
    node* new_node = new node(value, m_head, nullptr);
	if (m_head == nullptr) {
		m_head = new_node;
		m_tail = new_node;
	} else {
		m_head->m_prev = new_node;
    	m_head = new_node;
	}
}


void list::push_back(const value_type& value)
{
	node* new_node = new node(value, nullptr, m_tail);
	if (m_head == nullptr) {
		m_head = new_node;
		m_tail = new_node;
	} else {
		m_tail->m_next = new_node;
		m_tail = new_node;
	}
}

void list::pop_front()
{
    assert(m_head != nullptr);
    node* n = m_head;
    m_head = m_head->m_next;
    delete n;
}

void list::pop_back()
{
	assert(m_tail != nullptr);
	if (m_tail == m_head) {
		m_head = nullptr;
		delete m_tail;
	} else {
	    node* p = m_tail;
	    m_tail = m_tail->m_prev;
	    delete p;
	}
}

list::node* list::access_helper(const size_type& index) const
{
    assert(index >= 0);
    assert(index < size());
    node* current = m_head;
    for (size_type i = 0; i < index; ++i) {
        assert(current != nullptr);
        current = current->m_next;
	}
    assert(current != nullptr);
    return current;
}

list::value_type list::access(const size_type& index) const
{
    node* current = access_helper(index);
    assert(current != nullptr);
    return current->m_value;
}

list::list()
    : m_head(nullptr)
	, m_tail(nullptr)
{
	std::cout << "Default constructor" << std::endl;
}

list::list(size_type n, const value_type& default_value)
    : m_head(nullptr)
	, m_tail(nullptr)
{
	std::cout << "Constructor" << std::endl;
    for (size_type i = 0; i < n; ++i) {
        node* new_node = new node(default_value, nullptr, nullptr);
        if (m_tail != nullptr) {
            m_tail->m_next = new_node;
			m_tail->m_next->m_prev = m_tail;
        } else {
            assert(m_head == nullptr);
            m_head = new_node;
        }
		m_tail = new_node;
    }
}

list::list(const list& b)
{
	std::cout << "Copy constructor" << std::endl;
	while (! empty()) {
		pop_front();
	}
 	node* current = b.m_head;
	while (current!=nullptr) {
	   	node* new_node = new node(current->m_value, nullptr, nullptr);
        if (m_head != nullptr) {
            m_tail->m_next = new_node;
			m_tail->m_next->m_prev = m_tail;
        } else {
            m_head = new_node;
        }
    	m_tail = new_node;
		current = current->m_next;
	}
}



const list& list::operator=(const list& c)
{
	std::cout << "Assignment Operator" << std::endl;
    this->m_head = c.m_head;
    return *this;
}

list::~list()
{
	std::cout <<"Destructor" << std::endl;
	while (! empty()) {
		pop_back();
	}
}

