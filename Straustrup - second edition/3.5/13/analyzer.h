#ifndef ANALYZER_H
#define ANALYZER_H

#include "defs.h"

token_value get_token(const char *(&ch));
double prim(const char *(&ch));
double term(const char *(&ch));
double expr(const char *(&ch));

#endif