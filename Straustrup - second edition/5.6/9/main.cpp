#include <iostream>

class date {
public:
    friend void setDate(date &d, int, int, int);  // ����, �����, ���
    friend void setDate(date &d, int, int);       // ����, ����� � ������� ���
    friend void setDate(date &d, int);            // ���� � ������� ��� � �����
    friend void setDate(date &d);               // ����������� ��������: ������� ����
    friend void setDate(date &d, const char*);    // ���� � ��������� �������������
    friend void get(date &d, int*, int*, int*);
    friend void print(date &d);
private:
    int day;
    int month;
    int year;
};

void print(date &d)     // ������ ����  � �������� � ��� ����
{
    std::cout << d.month << '/' << d.day << '/' << d.year;
}

class char_stack {
    int size;
    char* top;
    char* s;
public:
    char_stack(int sz) { top=s=new char[size=sz]; }
    ~char_stack()  { delete[] s; }  // ����������
    void push(char c) { *top++ = c; }
    void pop()   { return *--top; }
};

class intset {
    int cursize, maxsize;
    int  *x;
public:
    intset(int m, int n);    // �� ����� m ����� �� 1..n
    ~intset();

    int member(int t) const; // �������� �� t ������?
    void insert(int t);      // �������� � ��������� t

    void start(int& i) const { i = 0; }
    void ok(int& i) const    { return i<cursize; }
    void next(int& i) const  { return x[i++]; }
};

int main()
{
    return 0;
}