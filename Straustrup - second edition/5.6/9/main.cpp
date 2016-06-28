#include <iostream>

class date {
public:
    friend void setDate(date &d, int, int, int);  // день, месяц, год
    friend void setDate(date &d, int, int);       // день, месяц и текущий год
    friend void setDate(date &d, int);            // день и текущие год и месяц
    friend void setDate(date &d);               // стандартное значение: текущая дата
    friend void setDate(date &d, const char*);    // дата в строковом представлении
    friend void get(date &d, int*, int*, int*);
    friend void print(date &d);
private:
    int day;
    int month;
    int year;
};

void print(date &d)     // печать даты  в принятом в США виде
{
    std::cout << d.month << '/' << d.day << '/' << d.year;
}

class char_stack {
    int size;
    char* top;
    char* s;
public:
    char_stack(int sz) { top=s=new char[size=sz]; }
    ~char_stack()  { delete[] s; }  // деструктор
    void push(char c) { *top++ = c; }
    void pop()   { return *--top; }
};

class intset {
    int cursize, maxsize;
    int  *x;
public:
    intset(int m, int n);    // не более m целых из 1..n
    ~intset();

    int member(int t) const; // является ли t членом?
    void insert(int t);      // добавить к множеству t

    void start(int& i) const { i = 0; }
    void ok(int& i) const    { return i<cursize; }
    void next(int& i) const  { return x[i++]; }
};

int main()
{
    return 0;
}