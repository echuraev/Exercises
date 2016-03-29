#include <iostream>

void f(const char* type, char ch)
{
	std::cout << "f(const char* type, char ch): " << type << " : " << ch << std::endl;
}

void g(const char* type, char &ch)
{
	std::cout << "g(const char* type, char &ch): " << type << " : " << ch << std::endl;
}

void h(const char* type, const char &ch)
{
	std::cout << "h(const char* type, const char &ch): " << type << " : " << ch << std::endl;
}

int main()
{
	f("'a'", 'a');
	// g("'a'", 'a'); // incorrect
	h("'a'", 'a');
	std::cout << std::endl;

	f("49", 49);
	// g("49", 49); // incorrect
	h("49", 49);
	std::cout << std::endl;

	f("3300", 3300);
	// g("3300", 3300); // incorrect
	h("3300", 3300);
	std::cout << std::endl;

	char ch = 'm';
	f("char", ch);
	g("char", ch);
	h("char", ch);
	std::cout << std::endl;

	unsigned char uch = 't';
	f("unsigned char", uch);
	// g("unsigned char", uch); // incorrect
	h("unsigned char", uch);
	std::cout << std::endl;

	signed char sch = 's';
	f("signed char", sch);
	//g("signed char", sch); // incorrect
	h("signed char", sch);
	std::cout << std::endl;
	return 0;
}