#include <iostream>
#include <bitset>

int main()
{
	union
	{
		int i;
		int *pi;
	} u;

	u.pi = NULL;
	std::cout << std::bitset<32>(u.i) << std::endl;

	return 0;
}