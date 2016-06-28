#include "circle.h"
#include <stdarg.h>
#include <math.h>

Circle::Circle(Screen *screen) : Shape(screen), m_fill(false)
{}

Circle::~Circle()
{
}

void Circle::draw()
{
    if (m_vertex.size() == 0)
        return;
    for (auto it = m_vertex.begin(); it != m_vertex.end(); ++it)
    {
        m_screen->put_point(*it);
    }
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

void Circle::setCoordinates(Point p, ...)
{
    m_center = p;
    va_list ap;
    va_start(ap, p);
    m_radius = va_arg(ap, uint);
    va_end(ap);

    for (int alpha(0); alpha < 360; ++alpha)
    {
        int x = m_center.x() + static_cast<int>(m_radius*cos(alpha));
        int y = m_center.y() + static_cast<int>(m_radius*sin(alpha));
        m_vertex.push_back(Point(x, y));
    }

    findMinAndMax();
}

bool Circle::contains(Point p)
{
    double res = pow(p.x() - m_center.x(), 2) + pow(p.y() - m_center.y(), 2);
    if (res >= pow(m_radius, 2))
        return false;
    return true;
}

void Circle::findMinAndMax()
{
    m_minX = m_center.x() - m_radius;
    m_maxX = m_center.x() + m_radius;
    m_minY = m_center.y() - m_radius;
    m_maxY = m_center.y() + m_radius;
}
