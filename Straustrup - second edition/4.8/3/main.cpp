#include <iostream>
#include <stdarg.h>

void print(const char * name, ...)
{
	std::cout << "Hello, " << name;
	va_list ap;
	va_start(ap, name);
	while(1)
	{
		char *p = va_arg(ap, char*);
		if (p == 0)
			break;
		std::cout << ", " << p;
	}
	va_end(ap);
	std::cout << "!" << std::endl;
}

int main()
{
	print("Vasily", "Misha", "Oleg", 0);
	return 0;
}