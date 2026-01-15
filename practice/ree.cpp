
#include <iostream>
#include <unistd.h>
#include <cctype>


int main(int argc, char **argv)
{
	// int *a = new int(10);
	// int* &q = a;
	// std::cout << *q << " "<< a << ", address of a is: " <<  &a << std::endl;
	// delete a;
	// 	std::cout << *q << " "<< a << ", address of a is: " <<  &a << std::endl;

	// int b = 4;
	// q = &b;
	// std::cout << *q << " "<< a << ", address of a is: " <<  &q << std::endl;

	std::string *ss = new std::string("hello world!");
	const std::string* s= ss;

	std::cout << &ss << ",  " << ss << ",  " << *ss << std::endl;

	*ss = std::string("riight\n");
	std::cout << &ss << ",  " << ss << ",  " << *ss << std::endl;

	std::cout << &s << ",  " << s << ",  " << *s << std::endl;

	return (0);
}