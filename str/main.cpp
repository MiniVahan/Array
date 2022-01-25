#include "str.hpp"

#include <cassert>
#include <iostream>


void test_operators()
{
	char test1[] = "hello";
	char test2[] = ", world";
	string my_str(test1);
	string new_str(test2);
	my_str.swap(new_str);
	std::cout << my_str.getStr() << std::endl;
	std::cout << new_str.getStr() << std::endl;
	my_str+new_str;
	//std::cout << my_str.getStr() << std::endl;
	my_str += new_str;
	//std::cout << my_str.getStr() << std::endl;
	//std::cout << my_str[5] << std::endl;
	bool test = new_str < my_str;
	//std::cout << "my_str < new_stri = " <<test << std::endl;
	char test3[] = "Hello world wrld";
	char test4[] = "wrld";
	string str(test3);
	string str2(test4);
	bool test_find = str.find_first_of(str2);
	assert( test_find == true);
	std::cout << "find = " << test_find << std::endl;
}


void test_assignment()
{
	char test1[] = "hello";
	string my_str(test1);
	string new_str;
	new_str = my_str;
	std::cout << new_str.getStr() << std::endl;
	std::cout << my_str.getStr() << std::endl;
	assert (new_str.get_size() == my_str.get_size());
}

void test_append()
{
	char test1[] = "hello";
	char test2[] = ", world";
	string new_str(test1);
	new_str.append(test2);
	std::cout << new_str.getStr() << std::endl;
}

void test_get_size()
{
	char test1[] = "hellooooo";
	string new_str(test1);
	std::cout << new_str.getStr() << std::endl;
	std::cout << new_str.get_size() << std::endl;
}

void test_default_constructor()
{
	string new_str;
	std::cout << new_str.getStr() << std::endl;
	std::cout << new_str.get_size() << std::endl;
}

void test_constructor()
{
	char test2[] = "Hello World";
	string new_str(test2);
	std::cout << new_str.getStr() << std::endl;
	std::cout << new_str.get_size() << std::endl;
	assert(new_str.get_size() == 11);
}

void test_copy_constructor()
{
	char test3[] = "Hello Worldddd";
	string new_str(test3);
	string new_str2(new_str);
	assert(new_str2.get_size() == new_str.get_size());
}

int main()
{
	test_default_constructor();
	test_copy_constructor();
	test_constructor();
	test_get_size();
	test_append();
	test_assignment();
	test_operators();
	return 0;

}
