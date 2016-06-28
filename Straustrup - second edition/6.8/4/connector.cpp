#include "connector.h"
#include <math.h>

void connector(Shape *s1, Shape *s2)
{
    Point *p1 = NULL;
    Point *p2 = NULL;
    double minDistance = (s1->m_screen->width() > s1->m_screen->height()) ? s1->m_screen->width() : s1->m_screen->height();

    for (auto&& it1 : s1->m_vertex)
    {
        for (auto&& it2 : s2->m_vertex)
        {
            double distance = sqrt(pow(it2.x() - it1.x(), 2) + pow(it2.y() - it1.y(), 2));
            if (distance < minDistance)
            {
                minDistance = distance;
                p1 = &it1;
                p2 = &it2;
            }
        }
    }
    if (p1 == NULL || p2 == NULL)
        return;
    s1->m_screen->put_line(*p1, *p2);
}
