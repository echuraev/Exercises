#include "shape.h"

Shape* Shape::m_list = NULL;

Shape::Shape(Screen *screen) : m_screen(screen)
{
    m_next = m_list;
    m_list = this;
}

void Shape::shape_refresh()
{
    m_screen->clear();
    for (Shape *p = m_list; p; p = p->m_next)
    {
        p->draw();
    }
    m_screen->refresh();
}

void Shape::stack(Shape *p, const Shape *q)
{
    Point n = q->north();
    Point s = p->south();
    p->move(n.x() - s.x(), n.y() -s.y() +1);
}
