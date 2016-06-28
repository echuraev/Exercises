#include "rectangle.h"

Rectangle::Rectangle(Screen *screen, Point a, Point b) : Shape(screen)
{
    if (a.x() <= b.x())
    {
        if (a.y() <= b.y())
        {
            sw = a;
            ne = b;
        }
        else
        {
            sw = Point(a.x(), b.y());
            ne = Point(b.x(), a.y());
        }
    }
    else
    {
        if (a.y() <= b.y())
        {
            sw = Point(b.x(), a.y());
            ne = Point(a.x(), b.y());
        }
        else
        {
            sw = b;
            ne = a;
        }
    }
}

void Rectangle::draw()
{
    Point nw(sw.x(), ne.y());
    Point se(ne.x(), sw.y());
    m_screen->put_line(nw, ne);
    m_screen->put_line(ne, se);
    m_screen->put_line(se, sw);
    m_screen->put_line(sw, nw);
}

void Rectangle::move(int a, int b)
{
    sw.setCoordinates((sw.x() + a), (sw.y() + b));
    ne.setCoordinates((ne.x() + a), (ne.y() + b));
}
