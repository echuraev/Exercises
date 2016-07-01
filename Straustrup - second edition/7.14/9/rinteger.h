#ifndef RINTEGER_H
#define RINTEGER_H

#include <iostream>

class RInteger
{
public:
    RInteger();
    RInteger(int i);
    RInteger operator+() 
	{
		m_int = (m_int < 0) ? -m_int : m_int;
		return *this;
	}
    RInteger operator-()
	{
		m_int = (m_int > 0) ? -m_int : m_int;
		return RInteger(-m_int);
	}
    int operator+(RInteger i) {return m_int + i.m_int;}
    int operator-(RInteger i) {return m_int - i.m_int;}
    int operator*(RInteger i) {return m_int * i.m_int;}
    int operator/(RInteger i) {return m_int / i.m_int;}
    int operator%(RInteger i) {return m_int % i.m_int;}
    friend std::ostream& operator<<(std::ostream &s, const RInteger &i);
private:
    int m_int;
};

#endif
