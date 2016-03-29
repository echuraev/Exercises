#include <iostream>

int main()
{
	for (char ch = 'a'; ch <= 'z'; ++ch)
	{
		std::cout << ch << '\t' << std::dec << static_cast<int>(ch) << '\t' << std::hex << static_cast<int>(ch) << std::endl;
	}
	std::cout << std::endl;
	for (char ch = '0'; ch <= '9'; ++ch)
	{
		std::cout << ch << '\t' << std::dec << static_cast<int>(ch) << '\t' << std::hex << static_cast<int>(ch) << std::endl;
	}
	return 0;
}