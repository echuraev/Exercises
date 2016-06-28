#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include <vector>
#include "triangle.h"

class Circle : public Shape
{
public:
    Circle(Screen *screen);
    ~Circle();
    virtual void draw();
    virtual void setCoordinates(Point p, ...);
    virtual inline void fill(bool val) {m_fill = val;}
protected:
    virtual bool contains(Point p);
private:
    void findMinAndMax();
    static const int m_vertexCount;
    std::vector<Point> m_vertex;
    Point m_center;
    uint m_radius;
    bool m_fill;
    int m_minX;
    int m_maxX;
    int m_minY;
    int m_maxY;
};

#endif
