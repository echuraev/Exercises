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
    void findMinAndMax();
private:
    void copy(const Triangle &t);
    static const int m_vertexCount;
};

#endif
