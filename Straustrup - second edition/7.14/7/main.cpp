#include <iostream>

struct X
{
    int i;
    X(int n) {i = n;}
    X operator+(int n)
    {
        return X(i + n);
    }
};

struct Y
{
    int i;
    Y(X x)
    {
        i = x.i;
    }
    Y operator+(X x)
    {
        return Y(X(i + x.i));
    }
    operator int()
    {
        return i;
    }
};

X operator*(X x,Y y)
{
    return X(x.i*y.i);
}
int f(X x)
{
    return x.i;
}

X x = 1;
Y y = x;
int i = 2;

int main()
{
    std::cout << i + 10 << '\n';
    std::cout << static_cast<int>(y) + 10 << '\n';
    std::cout << static_cast<int>(y) + 10*static_cast<int>(y) << '\n';
    std::cout << (x + y + i).i << '\n';
    std::cout << (x*x + i).i << '\n';
    std::cout << f(7) << '\n';
    std::cout << f(y.operator int()) << '\n';
    std::cout << y + y << '\n';
    std::cout << 106 + y << '\n';
    return 0;
}
