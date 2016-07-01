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
    String sub = sentence(6, 9);
    std::cout << sub << std::endl;
    return 0;
}
