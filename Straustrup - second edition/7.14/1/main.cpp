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
    return 0;
}
