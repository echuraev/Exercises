#include <iostream>

int main() 
{
	std::cout << "sizeof(bool): " << sizeof(bool) << std::endl;
	std::cout << "sizeof(char): " << sizeof(char) << std::endl;
	std::cout << "sizeof(signed char): " << sizeof(signed char) << std::endl;
	std::cout << "sizeof(unsigned char): " << sizeof(unsigned char) << std::endl;
	std::cout << "sizeof(short): " << sizeof(short) << std::endl;
	std::cout << "sizeof(signed short): " << sizeof(signed short) << std::endl;
	std::cout << "sizeof(unsigned short): " << sizeof(unsigned short) << std::endl;
	std::cout << "sizeof(int): " << sizeof(int) << std::endl;
	std::cout << "sizeof(signed int): " << sizeof(signed int) << std::endl;
	std::cout << "sizeof(unsigned int): " << sizeof(unsigned int) << std::endl;
	std::cout << "sizeof(long): " << sizeof(long) << std::endl;
	std::cout << "sizeof(signed long): " << sizeof(signed long) << std::endl;
	std::cout << "sizeof(unsigned long): " << sizeof(unsigned long) << std::endl;
	std::cout << "sizeof(long long): " << sizeof(long long) << std::endl;
	std::cout << "sizeof(signed long long): " << sizeof(signed long long) << std::endl;
	std::cout << "sizeof(unsigned long long): " << sizeof(unsigned long long) << std::endl;
	std::cout << "sizeof(float): " << sizeof(float) << std::endl;
	std::cout << "sizeof(double): " << sizeof(double) << std::endl;
	std::cout << "sizeof(long double): " << sizeof(long double) << std::endl;
	std::cout << "sizeof(char*): " << sizeof(char*) << std::endl;
	std::cout << "sizeof(int*): " << sizeof(int*) << std::endl;

	enum Enum1 {a};
	enum Enum2 {b, c, d};

	std::cout << "sizeof(Enum1): " << sizeof(Enum1) << std::endl;
	std::cout << "sizeof(Enum2): " << sizeof(Enum2) << std::endl;

	return 0;
}