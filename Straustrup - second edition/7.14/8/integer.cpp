#include "integer.h"

Integer::Integer() : m_int(0)
{}

Integer::Integer(int i) : m_int(i)
{}

Integer::operator int()
{
    return m_int;
}
