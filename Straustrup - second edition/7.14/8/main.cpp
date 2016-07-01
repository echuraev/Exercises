#include "integer.h"
#include <iostream>

int main()
{
    Integer i;
    i = 6;
    Integer j(5);
    std::cout << i << ' ' << j << std::endl;
    std::cout << "+ " << i+j << std::endl;
    std::cout << "* " << i*j << std::endl;
    std::cout << "/ " << i/j << std::endl;
    std::cout << "% " << i%j << std::endl;
    std::cout << "i>j " << (i>j) ? 1 : 0;
    std::cout << std::endl;
    return 0;
}