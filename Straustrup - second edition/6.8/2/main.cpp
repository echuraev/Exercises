#include <iostream>
#include "screen.h"

int main()
{
    Screen screen;
    screen.put_point(screen.width()/4, screen.height()/4*3);
    screen.put_point(screen.width()/4*3, screen.height()/4);
    screen.put_line(0, 0, screen.width() - 1, screen.height() - 1);
    screen.refresh();
    return 0;
}