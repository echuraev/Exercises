#include <iostream>
#include "screen.h"
#include "triangle.h"
#include "circle.h"

int main()
{
    Screen screen;

    Triangle triangle(&screen);
    triangle.setCoordinates(Point(5, 5),
        Point(screen.width()/4, screen.height()-5),
        Point(screen.width()/2-5, 5));
    //triangle.fill(true);
    triangle.draw();

    Circle circle(&screen);
    circle.setCoordinates(Point(screen.width()/4*3, screen.height()/2), screen.width()/4);
    //circle.fill(true);
    circle.draw();

    connector(&triangle, &circle);

    screen.refresh();
    return 0;
}