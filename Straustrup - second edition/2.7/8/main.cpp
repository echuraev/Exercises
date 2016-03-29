#include <iostream>
#include <limits>

template<class T>
void print(const char *name)
{
	std::cout << "Type: " << name << "; min: " << std::numeric_limits<T>::min() << "; max: " << std::numeric_limits<T>::max() << std::endl;
}

int main()
{
	print<bool>("bool");
	print<char>("char");
	print<short>("short");
	print<int>("int");
	print<long>("long");
	print<float>("float");
	print<double>("double");
	print<long double>("long double");
	print<unsigned>("unsigned");
	//print<char*>("char*");
	print<int*>("int*");
	print<void*>("void*");
	return 0;
}