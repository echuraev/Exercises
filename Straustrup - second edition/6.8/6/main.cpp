#include "char_vec.h"
#include <iostream>

int main()
{
    char_vec *vec = char_vec::new_char_vec(10);
    for (int i(0); i < 10; ++i)
    {
        (*vec)[i] = 'A' + i;
    }
    for (int i(0); i < 10; ++i)
    {
        std::cout << (*vec)[i];
    }
    std::cout << std::endl;
    return 0;
}
