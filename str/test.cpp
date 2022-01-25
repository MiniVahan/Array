#include <iostream>
#include <cstring>

int main()
{
	char* temp = new char[2];
	temp[0] = 'a';
	temp[1] = 'b';
	temp[2] = 'c';
	std::cout << strlen(temp) <<std::endl;
	char str[] = "Hello world";
	int a = 0;
	int* ptr = &a;
	delete ptr;
	std::cout << ptr <<std::endl;
	std::cout << str <<std::endl;
	//char * new_ptr= new char[];
	return 0;
}
