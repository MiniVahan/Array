
#include "list.hpp"

#include <iostream>
#include <cassert>

class list::node
{
public:
    value_type m_value;
    node* m_next;

public:
    node(value_type v, node* n)
        : m_value(v)
        , m_next(n)
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
    node* new_node = new node(value, m_head);
    m_head = new_node;
}


void list::push_back(const value_type& value)
{
	node* new_node = new node(value, nullptr);
	if (m_head == nullptr) {
		m_head = new_node;
	} else {
  		node* current = m_head;
   		while (current != nullptr) {
   	 		if (current->m_next == nullptr) {
   	 			current->m_next = new_node;
   	 			break;
   	 		}
   			current = current->m_next;
		}
  	}
}

void list::pop_front()
{
	m_head = m_head->m_next;
}

void list::pop_back()
{
	if (m_head->m_next == nullptr) {
		m_head = nullptr;
	} else {
	node* current = m_head;
	node* previous = current;
	while (current != nullptr) {
		previous = current;
		current = current->m_next;
 		if (current->m_next == nullptr) {
 			previous->m_next = nullptr;
			break;
 		}
	}
	}
}

int list::access(const size_type& index)
{
	node* current = m_head;
    for (size_type i = 0; i < index; ++i) {
        current = current->m_next;
	}
	return current->m_value;
}

list::list()
    : m_head(nullptr)
{
	std::cout << "Default constructor" << std::endl;
}

list::list(size_type n, const value_type& default_value)
    : m_head(nullptr)
{
	std::cout << "Constructor" << std::endl;
    node* current = nullptr;
    for (size_type i = 0; i < n; ++i) {
        node* new_node = new node(default_value, nullptr);
        if (current != nullptr) {
            current->m_next = new_node;
        } else {
            assert(m_head == nullptr);
            m_head = new_node;
        }
        current = new_node;
    }
}

list::list(const list& b)
	: m_head(nullptr)
{
	std::cout << "Copy constructor" << std::endl;
 	node* current = b.m_head;
 	node* previous = nullptr;
	while (current!=nullptr) {
	   	node* new_node = new node(current->m_value, nullptr);
        if (this->m_head != nullptr) {
			previous->m_next = new_node;
			previous = previous->m_next;
        } else {
            m_head = new_node;
			previous = m_head;
        }
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
	std::cout << "Destructor" << std::endl;
	node* current = m_head;
	while (current != nullptr) {
		m_head = current;
		current = current->m_next;
		delete m_head;
}
	delete current;
}
