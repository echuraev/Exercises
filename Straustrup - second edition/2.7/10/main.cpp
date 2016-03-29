#include <iostream>

void swapPointers(int *a, int *b)
{
	std::cout << "Swap pointers" << std::endl;
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void swapLinks(int &a, int &b)
{
	std::cout << "Swap Links" << std::endl;
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 5, b = 7;
	std::cout << "a: " << a << "; b: " << b << std::endl;
	swapPointers(&a, &b);
	std::cout << "a: " << a << "; b: " << b << std::endl;
	swapLinks(a, b);
	std::cout << "a: " << a << "; b: " << b << std::endl;
	return 0;
}