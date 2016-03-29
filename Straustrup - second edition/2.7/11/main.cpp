#include <iostream>
#include <string.h>

int main()
{
	char str[] = "a short string";
	std::cout << "sizeof(" << str << "): " << sizeof(str) << "; strlen(" << str << "): " << strlen(str) << std::endl;
	return 0;
}