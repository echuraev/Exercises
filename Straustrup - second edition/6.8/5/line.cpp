#include "line.h"

Line::Line(Screen *screen, Point a, Point b) : Shape(screen), w(a), e(b)
{}

Line::Line(Screen *screen, Point a, int l) : Shape(screen)
{
    w = Point(a.x()+l-1, a.y());
    e = a;
}

void Line::draw()
{
    m_screen->put_line(w,e);
}

void Line::move(int a, int b)
{
    w.setCoordinates((w.x() + a), (w.y() + b));
    e.setCoordinates((e.x() + a), (e.y() + b));
}

