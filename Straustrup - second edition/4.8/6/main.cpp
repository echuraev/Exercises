#include <iostream>

typedef int (*CFT)(int, int);

template <typename T>
void sort(T *base, int n, CFT cmp)
{
	int i = 0;
	int j = n;
	T x = base[n>>1];

	do
	{
		while((*cmp)(base[i], x) < 0) i++;
		while((*cmp)(base[j], x) > 0) j--;
		if (i <= j)
		{
			T tmp = base[i];
			base[i] = base[j];
			base[j] = tmp;
			i++;
			j--;
		}
	}
	while (i <= j);

	if (i < n)
		sort(base + i, n - i, cmp);
	if (j > 0)
		sort(base, j, cmp);
}

inline int cmpint(const int num1, const int num2)
{
	return num1 - num2;
}

int main()
{
	const int size = 14;
	int a[size] = { 0, 7, 8, 3, 52, 14, 16, 18, 15, 13, 42, 30, 35, 26 };
	for (int i (0); i < size; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	sort<int>(a, size-1, cmpint);
	for (int i (0); i < size; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
