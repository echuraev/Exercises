#ifndef SCREEN_H
#define SCREEN_H

typedef unsigned int uint;

class Point
{
public:
    Point() {}
    Point(int a, int b) : m_x(a), m_y(b) {}
    ~Point() {}
    inline int x() {return m_x;}
    inline int y() {return m_y;}
private:
    int m_x;
    int m_y;
};

class Screen
{
public:
    Screen(uint xMax = 40, uint yMax = 24);
    ~Screen();
    void refresh();
    void clear();
    void put_point(int a, int b);
    inline void put_point(Point p) {put_point(p.x(), p.y());}
    void put_line(int x0, int y0, int x1, int y1);
    inline void put_line(Point a, Point b) {put_line(a.x(), a.y(), b.x(), b.y());}
    inline uint width() {return m_xMax;}
    inline uint height() {return m_yMax;}
private:
    void screenInit();
    inline bool onScreen(uint a, uint b) {return 0 <= a && a < m_xMax && 0 <= b && b < m_yMax;};
    uint m_xMax;
    uint m_yMax;
    enum color
    {
        black = '*',
        white = ' '
    };
    char **m_screen;
};

#include <iostream>

#endif
