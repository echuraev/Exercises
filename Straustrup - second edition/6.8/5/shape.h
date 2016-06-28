#ifndef SHAPE_H
#define SHAPE_H

#include "screen.h"

class Shape
{
public:
    Shape(Screen *screen);
    virtual Point north() const = 0;
    virtual Point south() const = 0;
    virtual Point east() const = 0;
    virtual Point west() const = 0;
    virtual Point neast() const = 0;
    virtual Point seast() const = 0;
    virtual Point nwest() const = 0;
    virtual Point swest() const = 0;
    virtual void draw() = 0;
    virtual void move(int, int) = 0;
    void shape_refresh();
    static void stack(Shape *p, const Shape *q);
protected:
    static Shape *m_list;
    Shape *m_next;
    Screen *m_screen;
};

#endif
