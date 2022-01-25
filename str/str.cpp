#include "str.hpp"

#include <iostream>
#include <cstring>

const string& string::swap(string& s)
{
	char * test = new char[strlen(s.str)];
	for (int i = 0; i<strlen(s.str); i++) {
		*(test+i) = *(s.str+i);
	}
	for (int i = 0; i<strlen(s.str); i++) {
		*(s.str+i) = str[i];
	}
	for (int i = 0; i<strlen(test); i++) {
		str[i] = *(test+i);
	}
	return *this;
}

bool string::operator<(const string& s)
{
	if ( strlen(str) < s.get_size()) {
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
	std::cout << "+= operator" << std::endl;
	int index = 0;
	for (int i = strlen(str); index<strlen(s.str); i++) {
		*(str+i) = *(s.str+index);
		index++;
	}
	return *this;
}

const string& string::operator+(const string& s)
{
	std::cout << "+ operator" << std::endl;
	int index = 0;
	for (int i = strlen(str); index<strlen(s.str); i++) {
		*(str+i) = *(s.str+index);
		index++;
	}
	return *this;
}


const string& string::operator=(const string& s)
{
	std::cout << "Assignment Operator" << std::endl;
	str = new char[strlen(s.str)];
	for (int i = 0; i<strlen(s.str); i++) {
		*(str+i) = *(s.str+i);
	}
	return *this;
}


char* string::append(char* new_str)
{
	char* result = new char[strlen(str)+strlen(new_str)];
	for (int i=0; i<strlen(str); i++) {
		result[i] += str[i];
	}
	int index = 0;
	for (int i=strlen(str); i<strlen(str)+strlen(new_str); i++) {
		result[i] += new_str[index];
		++index;
	}
	str = result;
	return str;
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
	if (this->str != nullptr) {
	std::cout << "Destructor" << std::endl;
	delete str; 
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
	std::cout << "Constructor" << std::endl;
	str = new char[strlen(new_str)];
	for (int i=0; i<strlen(new_str)+1; i++) {
		str[i] = new_str[i];
	}
}

string::string(const string& value)
{
	std::cout << "Copy Constructor" << std::endl;
	str = new char[value.get_size()];
	for (int i=0; i<value.get_size(); i++) {
		str[i] = value.getStr()[i];
	}
}
