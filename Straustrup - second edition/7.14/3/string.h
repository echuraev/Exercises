#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string.h>

void error(const char *p);

class String
{
public:
    String();
    String(const char *s);
    String(const String &x);
    ~String();
    String& operator=(const char *);
    String& operator=(const String &);
    char& operator[](int i);
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);
    friend inline int operator==(const String &x, const char *s) {return strcmp(x.p->s, s) == 0;}
    friend inline int operator==(const String &x, const String &y) {return strcmp(x.p->s, y.p->s) == 0;}
    friend inline int operator!=(const String &x, const char *s) {return strcmp(x.p->s, s) != 0;}
    friend inline int operator!=(const String &x, const String &y) {return strcmp(x.p->s, y.p->s) != 0;}
    friend String operator+(const String &x1, const String &x2);
    String& operator+=(const String &x);
    String& operator()(int left, int right);
private:
    inline bool inBounds(int ind) {return (ind >= 0 && static_cast<size_t>(ind) < strlen(p->s));}
    bool addStrToSub(const String &x);
    struct srep {
        char *s;
        int n;
        srep() {n = 1;}
    };
    srep *p;
    int m_subLeft;
    int m_subRight;
};

#endif
