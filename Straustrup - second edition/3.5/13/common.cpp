#include "common.h"
#include <string.h>
#include <math.h>
#include <iostream>

int no_of_errors = 0;
name *table[TBLSZ];

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

name *look(const char* p, int ins)
{
	int ii = 0; // hash
	const char *pp = p;
	while (*pp)
	{
		ii = ii<<1 ^ *pp++;
	}
	ii = (ii < 0) ? -ii : ii;
	ii %= TBLSZ;
	for (name *n = table[ii]; n; n = n->next)
	{
		if (!strcmp(p, n->string))
			return n;
	}
	if (ins == 0)
		error("Undefined variable");
	name *nn = new name;
	nn->string = new char[strlen(p) + 1];
	strcpy_s(nn->string, strlen(p) + 1, p);
	nn->value = 1;
	nn->next = table[ii];
	table[ii] = nn;
	return nn;
}

name *insert(const char* s)
{
	return look(s, 1);
}
