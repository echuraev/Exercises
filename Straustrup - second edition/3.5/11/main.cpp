#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>

namespace my 
{
	int atoi(const char *str, bool *ok = 0)
	{
		int mult = 1;
		int num = 0;
		int base = 10;
		unsigned int i = 0;
		if(str[i] == '-')
		{
			mult = -1;
			i++;
		}
		if(str[i] == '0')
		{
			i++;
			base = (str[i] == 'x') ? 16 : 8;
			i = (base == 16) ? i + 1 : i;
		}

		for(; i < strlen(str); ++i)
		{
			if (!isdigit(str[i]))
			{
				if (ok != 0)
					*ok = false;
				return 0;
			}
			num *= base;
			num += (str[i] - '0');
		}
		return num*mult;
	}

	char *itoa(int num)
	{
		int len = 0;
		int tmp_num = num;
		while(tmp_num != 0)
		{
			tmp_num /= 10;
			len++;
		}
		len = (num < 0) ? len + 1 : len;
		char *str = new char[len + 1];
		str[0] = '-';
		for (int i = len - 1; num != 0; --i)
		{
			str[i] = abs(num % 10) + '0';
			num /= 10;
		}
		str[len] = '\0';
		return str;
	}
}

int main()
{
	std::cout << my::atoi("010") << '\t' << my::atoi("-10") << '\t' << my::atoi("10") << '\t' << my::atoi("0x10") << std::endl;
	std::cout << my::itoa(-157) << '\t' << my::itoa(157) << std::endl;
	return 0;
}