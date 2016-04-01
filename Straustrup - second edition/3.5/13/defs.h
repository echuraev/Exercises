#ifndef DEFS_H
#define DEFS_H

enum token_value
{
	NAME,      NUMBER,     END,
	PLUS='+',  MINUS='-',  MUL='*', DIV='/',
	PRINT=';', ASSIGN='=', LP='(',  RP=')'
};

struct name 
{
	char *string;
	name *next;
	double value;
};

extern token_value curr_tok;
extern int no_of_errors;

#endif