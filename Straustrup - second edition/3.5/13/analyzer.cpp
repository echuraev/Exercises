#include "analyzer.h"
#include "common.h"
#include <ctype.h>
#include <map>
#include <iostream>
#include <string>
#include <math.h>

double number_value;
char name_string[256];
token_value curr_tok;

token_value get_token(const char *(&ch))
{
	while (*ch != '\n' && isspace(*ch)) 
	{
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
			while (++ch && isalnum(*ch))
			{
				*p++ = *ch;
			}
			*p = 0;
			return curr_tok = NAME;
		}
		error("Incorrect lexeme");
		return curr_tok = PRINT;
	}
}

double prim(const char *(&ch))
{
	std::map<std::string, double (*)(double)> mathFunctions;
	mathFunctions["sqrt"] = sqrt;
	mathFunctions["log"] = log;
	mathFunctions["sin"] = sin;
	double e;
	switch (curr_tok)
	{
	case NUMBER:
		get_token(ch);
		return number_value;
	case NAME:
		if (mathFunctions.count(name_string))
		{
			if (get_token(ch) != LP)
				return error("Missed ( after math function");
			get_token(ch);
			e = mathFunctions[name_string](expr(ch));
			if (curr_tok != RP)
				return error("Missed ) after math function");
			return e;
		}
		if (get_token(ch) == ASSIGN)
		{
			name *n = insert(name_string);
			get_token(ch);
			n->value = expr(ch);
			return n->value;
		}
		return look(name_string)->value;
	case MINUS:
		get_token(ch);
		return -prim(ch);
	case LP:
		get_token(ch);
		e = expr(ch);
		if (curr_tok != RP)
			return error("Missed )");
		get_token(ch);
		return e;
	case END:
		return 1;
	default:
		return error("Missed expr");
	}
}

double term(const char *(&ch))
{
	double d;
	double left = prim(ch);
	while(1)
	{
		switch (curr_tok)
		{
		case MUL:
			get_token(ch);
			left *= prim(ch);
			break;
		case DIV:
			get_token(ch);
			d = prim(ch);
			if (d == 0) 
				return error("Division by zero");
			left /= d;
			break;
		default:
			return left;
		}
	}
}

double expr(const char *(&ch))
{
	double left = term(ch);
	while(1)
	{
		switch (curr_tok)
		{
		case PLUS:
			get_token(ch);
			left += term(ch);
			break;
		case MINUS:
			get_token(ch);
			left -= term(ch);
			break;
		default:
			return left;
		}
	}
}
