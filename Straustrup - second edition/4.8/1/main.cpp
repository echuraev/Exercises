#include <iostream>

void func1(char *ch, int &num);
void (*pFunc1)(char *ch, int &num) = &func1;
void func2(void (*pFunc1)(char *ch, int &num));
void (*pFunc3())(char *ch, int &num);
typedef void (*fptr)(char *ch, int &num);
fptr func4(fptr func);

int main()
{
	return 0;
}