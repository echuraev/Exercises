#include <iostream>

int main()
{
	char *ch;
	int arr[10];
	int (&arr2)[10] = arr;
	char *str[5];
	char **pch;
	const int m = 3;
	const int *t = &m;
	int k = 5;
	int *const cpt = &k;
	return 0;
}