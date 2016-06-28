#include <iostream>
#include "expr.h"

int main()
{
    Expr expr("123/4+123*4-3", STR);
    std::cout << "x = " << expr.eval() << std::endl;
    expr.print();
    std::cout << std::endl;
    Expr ex("123/4+123*4-3", NODE);
    std::cout << "x = " << ex.eval() << std::endl;
    ex.print();
    return 0;
}
