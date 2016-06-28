#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(Screen *screen, Point a, Point b);
    inline virtual Point north() const {return Point((sw.x() + ne.x())/2, ne.y());}
    inline virtual Point south() const {return Point((sw.x() + ne.x())/2, sw.y());}
    inline virtual Point east() const {return Point();}
    inline virtual Point west() const {return Point();}
    inline virtual Point neast() const {return ne;}
    inline virtual Point seast() const {return Point();}
    inline virtual Point nwest() const {return Point();}
    inline virtual Point swest() const {return sw;}
    virtual void draw();
    virtual void move(int a, int b);
private:
    Point sw, ne;
};

#endif
