#include "error.h"
#include <iostream>

int error(const char *s)
{
    std::cerr << "Error: " << s << std::endl;
    return 1;
}
