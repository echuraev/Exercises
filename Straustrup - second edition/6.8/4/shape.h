#ifndef SHAPE_H
#define SHAPE_H

#include "screen.h"
#include <vector>

class Shape
{
public:
    Shape(Screen *screen) : m_screen(screen)
    {}
    virtual void draw() = 0;
    virtual void setCoordinates(Point p, ...) = 0;
    virtual void fill(bool val) = 0;
    friend void connector(Shape *s1, Shape *s2);
protected:
    virtual bool contains(Point p) = 0;
    virtual void findMinAndMax() = 0;
    Screen *m_screen;
    std::vector<Point> m_vertex;
    bool m_fill;
    int m_minX;
    int m_maxX;
    int m_minY;
    int m_maxY;
};

#endif
