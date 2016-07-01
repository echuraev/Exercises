#include <iostream>
#include "string.h"

int main()
{
    String x;
    x = "Hello";
    String hello(x);
    String word("Word");
    hello += " ";
    String sentence = hello + word + "!";
    std::cout << sentence << std::endl;
    sentence(6, 9) = "User";
    std::cout << sentence << std::endl;
    sentence(6, 9) = "M";
    std::cout << sentence << std::endl;
    sentence(6, 6) = "007";
    std::cout << sentence << std::endl;
    return 0;
}
