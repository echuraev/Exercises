#ifndef SHAPE_H
#define SHAPE_H

#include "screen.h"

class Shape
{
public:
    Shape(Screen *screen) : m_screen(screen)
    {}
    virtual void draw() = 0;
    virtual void setCoordinates(Point p, ...) = 0;
    virtual void fill(bool val) = 0;
protected:
    virtual bool contains(Point p) = 0;
    Screen *m_screen;
};

#endif
