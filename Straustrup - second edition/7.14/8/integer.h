#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
public:
    Integer();
    Integer(int i);
    operator int();
private:
    int m_int;
};

#endif
