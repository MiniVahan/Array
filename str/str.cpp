#include "str.hpp"

#include <iostream>
#include <cstring>
#include <cassert>

bool string::find_first_of(const string& s)
{
	int s_str = strlen(s.str);
	int str_len = strlen(str);
	char * test = new char[s_str];
	for (int i = 0; i<str_len; i++) {
		if (str[i] == s.str[0]) {
			int count = i;
			for (int index = 0; index<s_str; index++) {
				*(test+index) = *(str+count);
				count++;
			}
			if (strcmp(test, s.str) == 0) {
				return true;
			} else {
				delete [] test;
				test = new char[s_str];
			}
		}
	}
	return false;
}


const string& string::swap(string& s)
{
	string t;
	t = s;
	s = *this;
	*this = t;
	return *this;
}

bool string::operator<(const string& s)
{
	if (strcmp(str, s.str) < 0) {
		return true;
	}
	return false;
}

char string::operator[](int i)
{
	return str[i];
}

const string& string::operator+=(const string& s)
{
	return *this + s;
}

const string& string::operator+(const string& s)
{
	int str_len = strlen(str);
	int s_str_len = strlen(s.str);
	int index = 0;
	for (int i = str_len; index<s_str_len; i++) {
		*(str+i) = *(s.str+index);
		index++;
	}
	return *this;
}


const string& string::operator=(const string& s)
{
	std::cout << "Assignment Operator" << std::endl;
	str = new char[strlen(s.str)];
	*this + s;
	return *this;
}


const string& string::append(const string& new_str)
{
	return *this + new_str;
}

int string::get_size() const
{
	return strlen(str);
}

char* string::getStr() const
{
	return str;
}

string::~string()
{
	if (str!=nullptr) {
		std::cout << "Destructor" << std::endl;
		delete[] str;
	}
}

string::string()
	: str(new char[1])
{
	std::cout << "Default Constructor" << std::endl;
	str[0] = '\0';
}

string::string(char* new_str)
{
	assert(new_str != nullptr);
	std::cout << "Constructor" << std::endl;
	int s_len = strlen(new_str);
	str = new char[s_len];
	for (int i=0; i<s_len+1; i++) {
		str[i] = new_str[i];
	}
}

string::string(const string& value)
{
	assert(value.str != nullptr);
	std::cout << "Copy Constructor" << std::endl;
	int v_length = value.get_size();
	char * v_str = value.getStr();
	str = new char[v_length];
	for (int i=0; i<v_length; i++) {
		str[i] = v_str[i];
	}
}
