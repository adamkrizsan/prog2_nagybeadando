#include "puzzlegame.h"
#include "graphics.hpp"
#include <vector>

using namespace std;
using namespace genv;

void draw_circle(int r)
{
    for (int y = -r; y <= r; ++y)
    {
        for (int x = -r; x <= r; ++x)
        {
            if (x * x + y * y <= r * r)
            {
                gout << genv::move(x, y) << genv::dot;
                gout << genv::move(-x, -y);
            }
        }
    }
}

int Tile::howmany()
{
    return l + r + u + d;
}

void Tile::draw_tile(int size, int bw, int pw)
{

    gout << color(150, 150, 150);
    if (is_selected)
        gout << color(255, 100, 100);
    gout << box(size - 2 * bw, size - 2 * bw) << genv::move((-size + 2 * bw) / 2, (-size + 2 * bw) / 2);
    gout << color(100, 100, 100);

    if (howmany() != 0)
        draw_circle(pw / 2);

    if (l)
    {

        gout << genv::move(0, (-pw) / 2) << box((-size / 2) + bw, pw) << genv::move((size / 2) - bw, (-(pw) / 2));
    }
    if (r)
    {
        int offset = 0;
        if (!l)
            offset = 1;

        gout << genv::move(0, (+pw) / 2) << box((size / 2) + offset - bw, -pw) << genv::move((-size / 2) + bw, (+(pw) / 2));
    }
    if (u)
    {
        gout << genv::move((pw) / 2, 0) << box(-pw, (-size / 2) + bw) << genv::move((pw) / 2, (size / 2) - bw);
    }
    if (d)
    {
        int offset = 0;
        if (!u)
            offset = 1;
        gout << genv::move((-pw) / 2, 0) << box(pw, (+size / 2) + offset - bw) << genv::move((-(pw) / 2), -(size / 2) - bw);
    }

    if (source)
    {
        draw_circle(pw);
        gout << color(255, 0, 0);
        draw_circle(pw / 2);
    }
    if (drain)
    {
        draw_circle(pw);
        gout << color(255, 0, 0);
        draw_circle(pw / 2);
        gout << color(100, 100, 100);
        draw_circle(pw / 3);
    }
}

// member function that rotates the tile by 90 degrees]
void Tile::rotate(int n)
{
    for (int i = 0; i < n; i++)
    {
        bool tmp = l;
        l = d;
        d = r;
        r = u;
        u = tmp;
    }
}
bool Tile::is_legal(int xe, int ye)
{
    if (x == 0)
    {
        if (l)
        {
            return false;
        }
    }
    if (y == 0)
    {
        if (u)
        {
            return false;
        }
    }
    if (x == xe - 1)
    {
        if (r)
        {
            return false;
        }
    }
    if (y == ye - 1)
    {
        if (d)
        {
            return false;
        }
    }

    return true;
}
bool Tile::does_match(Tile uj)
{
    if (x < uj.x)
    {
        if (r and uj.l)
        {
            return true;
        }
    }
    if (uj.x < x)
    {
        if (uj.r and l)
        {
            return true;
        }
    }
    if (y < uj.y)
    {
        if (d and uj.u)
        {
            return true;
        }
    }
    if (uj.y < y)
    {
        if (uj.d and u)
        {
            return true;
        }
    }

    return false;
};