#include "rinteger.h"

RInteger::RInteger() : m_int(0)
{}

RInteger::RInteger(int i) : m_int(i)
{}

std::ostream& operator<<(std::ostream &s, const RInteger &i)
{
    return s << i.m_int;
}
