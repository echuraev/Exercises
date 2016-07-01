#include "string.h"

void error(const char *p)
{
    std::cerr << p << '\n';
    exit(1);
}

String::String()
{
    p = new srep;
    p->s = 0;
}

String::String(const char *s)
{
    p = new srep;
    p->s = new char[strlen(s)+1];
    strcpy_s(p->s, strlen(s) + 1, s);
}

String::String(const String &x)
{
    x.p->n++;
    p = x.p;
}

String::~String()
{
    if (--p->n == 0)
    {
        delete [] p->s;
        delete p;
    }
}

String& String::operator=(const char *s)
{
    if (p->n > 1)
    {
        p->n--;
        p = new srep;
    }
    else
    {
        delete [] p->s;
    }
    p->s = new char [strlen(s) + 1];
    strcpy_s(p->s, strlen(s) + 1, s);
    return *this;
}

String& String::operator=(const String &x)
{
    x.p->n++;
    if (--p->n == 0)
    {
        delete[] p->s;
        delete p;
    }
    p = x.p;
    return *this;
}

std::ostream& operator<<(std::ostream &s, const String &x)
{
    return s << x.p->s << " [" << x.p->n << "]\n";
}

std::istream& operator>>(std::istream &s, String &x)
{
    char buf[256];
    s >> buf;
    x = buf;
    std::cout << "echo: " << x << '\n';
    return s;
}

char& String::operator[](int i)
{
    if (!inBounds(i))
        error("Out of bounds");
    return p->s[i];
}

String operator+(const String &x1, const String &x2)
{
    String x = x1;
    x += x2;
    return x;
}

String& String::operator+=(const String &x)
{
    char * tmp = new char [strlen(p->s) + strlen(x.p->s) + 1];
    strcpy_s(tmp, strlen(p->s) + strlen(x.p->s) + 1, p->s);
    strcat_s(tmp, strlen(p->s) + strlen(x.p->s) + 1, x.p->s);
    delete [] p->s;
    p->s = tmp;
    return *this;
}

String String::operator()(int left, int right)
{
    if (!inBounds(left) || !inBounds(right))
        error("Out of bounds");
    if (left <= right)
    {
        char *tmp = new char [right - left + 2];
        memcpy(tmp, p->s + left, right - left + 1);
        tmp[right - left + 1] = '\0';
        String res(tmp);
        delete [] tmp;
        return res;
    }
    else
    {
        return String("");
    }
}
