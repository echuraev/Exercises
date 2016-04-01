#ifndef COMMON_H
#define COMMON_H

#include "defs.h"

const int TBLSZ = 23;

int error(const char *s);
double parse_number(const char *(&ch));
name *look(const char* p, int ins = 0);
name *insert(const char* s);

#endif