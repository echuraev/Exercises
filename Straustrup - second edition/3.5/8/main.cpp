#include <iostream>

void f(int a, int b)
{
    if (a = 3) {std::cout << "a: " << a << "; b: " << b << std::endl;}// ...
    a = 0;
    if (a&077 == 0) {std::cout << "a: " << a << "; b: " << b << std::endl;} // ...
    //a := b+1; // error: expected primary-expression before ‘=’ token
}

int main()
{
    f(1, 2);
    return 0;
}
