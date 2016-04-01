#include <iostream>
#include <math.h>
#include "defs.h"
#include "analyzer.h"
#include "common.h"

int main()
{
	char buff[512];
	insert("pi")->value = 3.1415926535897932385;
	insert("e")->value = 2.7182818284590452354;
	while (std::cin)
	{
		std::cout << "> ";
		std::cin.getline(buff, 512);
		const char *ch = buff;
		while(ch && *ch != '\0')
		{
			get_token(ch);
			std::cout << expr(ch) << '\n';
		}
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
	}
	return no_of_errors;
}