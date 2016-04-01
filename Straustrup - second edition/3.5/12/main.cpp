#include <iostream>
#include <ctype.h>
#include <math.h>

enum token_value
{
	NAME,      NUMBER,     END,
	PLUS='+',  MINUS='-',  MUL='*', DIV='/',
	PRINT=';', ASSIGN='=', LP='(',  RP=')'
};

token_value curr_tok;
double number_value;
char name_string[256];
int no_of_errors = 0;
int error(const char *s)
{
	std::cerr << "Error: " << s << std::endl;
	no_of_errors++;
	return 1;
}

double parse_number(const char *(&ch))
{
	double num = 0;
	bool isFraction = false;
	int fraction = 0;
	while(isdigit(*ch) || *ch == '.')
	{
		if (*ch == '.')
		{
			ch++;
			isFraction = true;
			continue;
		}
		num *= 10;
		num += (*ch - '0');
		fraction = (isFraction) ? fraction + 1 : fraction;
		ch++;
	}
	return (fraction == 0) ? num : (num / pow(10, fraction));
}

token_value get_token(const char *(&ch))
{
	//const char *ch = buff;
	while (*ch != '\n' && isspace(*ch)) 
	{
		//if (!std::cin.get(ch)) return curr_tok = END;
		ch++;
	}

	switch(*ch)
	{
	case ';':
	case '\n':
	case '\0':
		return curr_tok = PRINT;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		curr_tok = token_value(*ch);
		ch++;
		return curr_tok;
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		number_value = parse_number(ch);
		return curr_tok = NUMBER;
	default:
		if (isalpha(*ch))
		{
			char* p = name_string;
			*p++ = *ch;
			while (++ch && isalnum(*ch)) *p++ = *ch;
			//std::cin.putback(ch);
			*p = 0;
			return curr_tok = NAME;
		}
		error("Incorrect lexeme");
		return curr_tok = PRINT;
	}
}

int main()
{
	char buff[512];
	while (std::cin)
	{
		std::cout << "> ";
		std::cin.getline(buff, 512);
		const char *ch = buff;
		while(ch && *ch != '\0')
		{
			get_token(ch);
		}
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
	}
	return no_of_errors;
}