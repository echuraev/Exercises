#include "screen.h"

Screen::Screen(unsigned int xMax, unsigned int yMax) : m_xMax(xMax), m_yMax(yMax)
{
    m_screen = new char * [m_xMax];
    for (size_t i(0); i < m_xMax; ++i)
    {
        m_screen[i] = new char [m_yMax];
    }

    screenInit();
}

Screen::~Screen()
{
    if (m_screen != NULL)
    {
        for (size_t i(0); i < m_xMax; ++i)
        {
            if (m_screen[i] != NULL)
            {
                delete [] m_screen[i];
            }
        }
        delete [] m_screen;
    }
}

void Screen::refresh()
{
    for (int y = m_yMax - 1; y >= 0; --y)
    {
        for(size_t x (0); x < m_xMax; ++x)
        {
            std::cout << m_screen[x][y];
        }
        std::cout << std::endl;
    }
}

void Screen::clear()
{
    screenInit();
}

void Screen::put_point(int a, int b)
{
    if (onScreen(a, b))
        m_screen[a][b] = black;
}

void Screen::put_line(int x0, int y0, int x1, int y1)
{
    register int dx = 1;
    int a = x1 - x0;
    if (a < 0)
    {
        dx = -1;
        a = -a;
    }

    register int dy = 1;
    int b = y1 - y0;
    if (b < 0)
    {
        dy = -1;
        b = -b;
    }

    int two_a = 2*a;
    int two_b = 2*b;
    int xcrit = -b + two_a;
    register int eps = 0;

    while (1)
    {
        put_point(x0, y0);
        if (x0 == x1 && y0 == y1)
            break;
        if (eps <= xcrit)
        {
            x0 += dx;
            eps += two_b;
        }
        if (eps >= a || a < b)
        {
            y0 += dy;
            eps -= two_a;
        }
    }
}

void Screen::screenInit()
{
    for (size_t i(0); i < m_xMax; ++i)
    {
        for (size_t j(0); j < m_yMax; ++j)
        {
            m_screen[i][j] = white;
        }
    }
}
