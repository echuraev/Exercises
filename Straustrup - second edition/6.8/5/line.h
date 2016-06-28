#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape
{
public:
    Line(Screen *screen, Point a, Point b);
    Line(Screen *screen, Point a, int l);
    inline virtual Point north() const {return Point((w.x() + e.x())/2, (e.y() < w.y()) ? w.y() : e.y());}
    inline virtual Point south() const {return Point((w.x() + e.x())/2, (e.y() < w.y()) ? e.y() : w.y());}
    inline virtual Point east() const {return Point();}
    inline virtual Point west() const {return Point();}
    inline virtual Point neast() const {return Point();}
    inline virtual Point seast() const {return Point();}
    inline virtual Point nwest() const {return Point();}
    inline virtual Point swest() const {return Point();}
    virtual void draw();
    virtual void move(int a, int b);
private:
    Point w, e;
};

#endif
