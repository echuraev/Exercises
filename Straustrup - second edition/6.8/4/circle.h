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
    virtual void findMinAndMax();
private:
    static const int m_vertexCount;
    Point m_center;
    uint m_radius;
};

#endif
