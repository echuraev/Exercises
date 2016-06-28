#include <iostream>

class base
{
public:
    virtual void iam()
    {
        std::cout << "base" << std::endl;
    }
};

class custom1 : public base
{
public: 
    virtual void iam()
    {
        std::cout << "custom1" << std::endl;
    }
};

class custom2 : public base
{
public:
    virtual void iam()
    {
        std::cout << "custom2" << std::endl;
    }
};

int main()
{
    base *b = new base();
    custom1 *c1 = new custom1();
    custom2 *c2 = new custom2();

    b->iam();
    c1->iam();
    c2->iam();

    b = c1;
    b->iam();
    b = c2;
    b->iam();

    return 0;
}