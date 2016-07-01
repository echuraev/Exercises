#include "rinteger.h"
#include <iostream>

int main()
{
    RInteger i;
    i = 6;
    RInteger j(5);
    std::cout << i << ' ' << j << std::endl;
    std::cout << "+ " << i+j << std::endl;
    std::cout << "* " << i*j << std::endl;
    std::cout << "/ " << i/j << std::endl;
    std::cout << "% " << i%j << std::endl;
    return 0;
}