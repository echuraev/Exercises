#include "char_vec.h"
#include <new>

char_vec* char_vec::new_char_vec(int s)
{
    char *rawbytes = static_cast<char*>(::operator new(sizeof(char_vec) + s - 1));
    char_vec * vec = new (rawbytes) char_vec;
    vec->sz = s;
    return vec;
}