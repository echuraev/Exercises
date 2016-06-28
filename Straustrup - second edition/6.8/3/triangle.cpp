#include "triangle.h"
#include <stdarg.h>

const int Triangle::m_vertexCount = 3;

Triangle::Triangle(Screen *screen) : Shape(screen), m_vertex(NULL), m_fill(false)
{}

Triangle::Triangle(const Triangle &t) : Shape(t.m_screen)
{
    copy(t);
}

Triangle::~Triangle()
{
    if (m_vertex != NULL)
        delete [] m_vertex;
}

Triangle& Triangle::operator=(const Triangle &t)
{
    if (this != &t)
    {
        if (m_vertex != NULL)
            delete [] m_vertex;
        copy(t);
    }
    return *this;
}

void Triangle::draw()
{
    if (m_vertex == NULL)
        return;
    m_screen->put_line(m_vertex[0], m_vertex[1]);
    m_screen->put_line(m_vertex[1], m_vertex[2]);
    m_screen->put_line(m_vertex[0], m_vertex[2]);
    if (m_fill)
    {
        for (int x (m_minX); x < m_maxX; ++x)
        {
            for (int y(m_minY); y < m_maxY; ++y)
            {
                if (contains(Point(x, y)))
                    m_screen->put_point(x, y);
            }
        }
    }
}

void Triangle::setCoordinates(Point p, ...)
{
    if (m_vertex == NULL)
        m_vertex = new Point[m_vertexCount];
    m_vertex[0] = p;
    va_list ap;
    va_start(ap, p);
    m_vertex[1] = va_arg(ap, Point);
    m_vertex[2] = va_arg(ap, Point);
    va_end(ap);

    findMinAndMax();
}

void Triangle::copy(const Triangle &t)
{
    m_screen = t.m_screen;
    m_fill = t.m_fill;
    m_minX = t.m_minX;
    m_maxX = t.m_maxX;
    m_minY = t.m_minY;
    m_maxY = t.m_maxY;

    if (t.m_vertex != NULL)
    {
        m_vertex = new Point[m_vertexCount];
        m_vertex[0] = t.m_vertex[0];
        m_vertex[1] = t.m_vertex[1];
        m_vertex[2] = t.m_vertex[2];
    }
    else
    {
        m_vertex = NULL;
    }
}

void Triangle::findMinAndMax()
{
    m_minX = m_vertex[0].x();
    m_maxX = m_vertex[0].x();
    m_minY = m_vertex[0].y();
    m_maxY = m_vertex[0].y();
    for (int i(1); i < m_vertexCount; ++i)
    {
        m_minX = (m_minX > m_vertex[i].x()) ? m_vertex[i].x() : m_minX;
        m_maxX = (m_maxX < m_vertex[i].x()) ? m_vertex[i].x() : m_maxX;
        m_minY = (m_minY > m_vertex[i].y()) ? m_vertex[i].y() : m_minY;
        m_maxY = (m_maxY < m_vertex[i].y()) ? m_vertex[i].y() : m_maxY;
    }
}

bool Triangle::contains(Point p)
{
    int a = (m_vertex[0].x() - p.x()) * (m_vertex[1].y() - m_vertex[0].y()) - (m_vertex[1].x() - m_vertex[0].x()) * (m_vertex[0].y() - p.y());
    int b = (m_vertex[1].x() - p.x()) * (m_vertex[2].y() - m_vertex[1].y()) - (m_vertex[2].x() - m_vertex[1].x()) * (m_vertex[1].y() - p.y());
    int c = (m_vertex[2].x() - p.x()) * (m_vertex[0].y() - m_vertex[2].y()) - (m_vertex[0].x() - m_vertex[2].x()) * (m_vertex[2].y() - p.y());
    return ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)) ? true : false;
}
