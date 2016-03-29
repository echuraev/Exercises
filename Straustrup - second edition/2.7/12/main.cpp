#include <iostream>
#include <string.h>

#define MONTH_COUNT 12

int main()
{
	char *month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	struct MonthDay
	{
		char month[4];
		int days;
	};
	MonthDay md[MONTH_COUNT];

	for (int i(0); i < MONTH_COUNT; ++i)
	{
		std::cout << month[i] << "\t" << days[i] << std::endl;
		strcpy_s(md[i].month, 4, month[i]);
		md[i].days = days[i];
	}
	std::cout << std::endl;

	for (int i(0); i < MONTH_COUNT; ++i)
	{
		std::cout << md[i].month << "\t" << md[i].days << std::endl;
	}
	return 0;
}