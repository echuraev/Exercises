#include "screen.h"
#include "shape.h"
#include "rectangle.h"
#include "line.h"

int main()
{
    Screen screen;
    Shape *p1 = new Rectangle(&screen, Point(0, 0), Point(10, 10));
    Shape *p2 = new Line(&screen, Point(0, 15), 17);
    Shape::stack(p1, p2);
    p2->shape_refresh();
    return 0;
}