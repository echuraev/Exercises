#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape
{
public:
    Triangle(Screen *screen);
    Triangle(const Triangle &t);
    ~Triangle();
    Triangle& operator=(const Triangle &t);
    virtual void draw();
    virtual void setCoordinates(Point p, ...);
    virtual inline void fill(bool val) {m_fill = val;}
protected:
    virtual bool contains(Point p);
private:
    void copy(const Triangle &t);
    void findMinAndMax();
    static const int m_vertexCount;
    Point *m_vertex;
    bool m_fill;
    int m_minX;
    int m_maxX;
    int m_minY;
    int m_maxY;
};

#endif
