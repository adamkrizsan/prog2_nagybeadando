#include "puzzlegame.h"
#include <vector>
#include "graphics.hpp"

using namespace std;
using namespace genv;

Table::Table(int XX, int YY, int res, int border_width)
{
    for (int i = 0; i < YY / res; i++)
    {
        Tile t;

        t.l = false;
        t.r = false;
        t.u = false;
        t.d = false;
        t.source = false;
        t.drain = false;
        vector<Tile> tmp(XX / res, t);
        v.push_back(tmp);
    }

    Table::options = {
        vector<bool>{true, false, false, false, false, false},
        vector<bool>{true, false, true, false, false, false},
        vector<bool>{true, true, false, false, false, false},
        vector<bool>{true, true, true, false, false, false},
        vector<bool>{true, true, true, true, false, false},

        vector<bool>{false, false, false, false, true, false},
        vector<bool>{false, false, false, false, false, true}

    };

    for (size_t i = 0; i < options.size() - 2; i++)
    {
        tileset.push_back(0);
    }

    for (int i = 0; i < options.size(); i++)
    {
        for (int j = 0; j < options[i].size(); j++)
        {
            Tile t;
            t.l = options[i][0];
            t.r = options[i][1];
            t.u = options[i][2];
            t.d = options[i][3];
            t.source = options[i][4];
            t.drain = options[i][5];

            gout << move_to(10, 10 + i * YY / 7);
            t.draw_tile(100, border_width, 20);
        }
    }
}

void Table::rajzol()
{
    const int res = 250; //>100
    const int border_width = 5;
    const int pipe_width = res / 5;
    for (size_t j = 0; j < v.size(); j++)
    {
        for (size_t i = 0; i < v[j].size(); i++)
        {

            gout << move_to(i * res + border_width + 300, j * res + border_width);
            v[j][i].draw_tile(res, border_width, pipe_width);
        }
    }
    gout << refresh;
}

void Table::add_tile(int i)
{
    tileset[i]++;
}
void Table::sub_tile(int i)
{
    tileset[i]--;
    if (tileset[i] < 0)
    {
        tileset[i] = 0;
    }
}

void Table::draw_choices(int YY)
{
    for (int i = 0; i < tileset.size(); i++)
    {
        string s = "x" + to_string(tileset[i]);
        gout << move_to(150, 10 + i * YY / 7) << color(70, 70, 70) << box(70, 70) << genv::move(-35, -35) << color(150, 150, 150) << text(s) << refresh;
    }
}
void Table::set_selected(int a)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].is_selected && a == 5)
            {
                v[i][j].source = !v[i][j].source;
                if (v[i][j].drain)
                {
                    v[i][j].drain = false;
                }
            }
            if (v[i][j].is_selected && a == 6)
            {
                v[i][j].drain = !v[i][j].drain;
                if (v[i][j].source)
                {
                    v[i][j].source = false;
                }
            }
        }
    }
}
void Table::rotate_selected()
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].is_selected)
            {
                v[i][j].rotate(1);
            }
        }
    }
}
Tile Table::get_source()
{
    Tile t;
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].source)
            {
                t = v[i][j];
                t.x = i;
                t.y = j;
            }
        }
    }
    return t;
}
Tile Table::get_drain()
{
    Tile t;
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            if (v[i][j].drain)
            {
                t.x = i;
                t.y = j;
            }
        }
    }
    return t;
}
Tile Table::choice_to_tile(int i)
{
    Tile t;
    t.l = bool(options[i][0]);
    t.r = bool(options[i][1]);
    t.u = bool(options[i][2]);
    t.d = bool(options[i][3]);
    t.source = bool(options[i][4]);
    t.drain = bool(options[i][5]);
    return t;
}

vector<Table> Table::find_routes(pair<int, int> current)
{
    vector<Table> routes;
    Tile s = get_source();
    Tile d = get_drain();
    Tile most;
    most = v[current.first][current.second];
    most.x = current.first;
    most.y = current.second;
    Tile target = d;
    vector<int> tilesetbuffer = tileset;

    int j = 0;

    for (int i = -1; i < 2; i++)
    {
        if (i == 0)
        {
            continue;
        }

        if (most.x + i < 0)
        {
            continue;
        }

        Tile proba;

        for (size_t k = 0; k < tileset.size(); k++)
        {
            if (tileset[k] != 0)
            {
                proba = choice_to_tile(k);
                proba.x = most.x + j;
                proba.y = most.y + i;

                for (int l = 0; l < 4; l++)
                {

                    if (most.does_match(proba) && proba.is_legal(v[0].size(), v.size()))
                    {
                        v[most.x + j][most.y + i] = proba;

                        routes.push_back(*this);
                    }
                    proba.rotate(1);
                }
                if (tileset[k] > 0)
                    tileset[k]--;
            }
        }
    }
    tileset = tilesetbuffer;
    int i = 0;
    for (j = -1; j < 2; j++)
    {
        if (j == 0)
        {
            continue;
        }

        if (most.y + j < 0)
        {
            continue;
        }
        Tile proba;
        for (size_t k = 0; k < tileset.size(); k++)
        {
            if (tileset[k] != 0)
            {
                proba = choice_to_tile(k);
                proba.x = most.x + j;
                proba.y = most.y + i;

                for (int l = 0; l < 4; l++)
                {

                    if (most.does_match(proba) && proba.is_legal(v[0].size(), v.size()))
                    {
                        v[most.x + j][most.y + i] = proba;

                        routes.push_back(*this);
                    }
                    proba.rotate(1);
                }
                if (tileset[k] > 0)
                    tileset[k]--;
            } // ELFOGY A TILEset k
        }
    }
    return routes;
}

pair<int, int> Table::get_free_ends() // get_free_end would be more comprehensive (since the 0 multi end support)
{
    Tile free;
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[0].size(); j++)
        {
            v[i][j].x = i;
            v[i][j].y = j;
            if (v[i][j].u || v[i][j].d || v[i][j].l || v[i][j].r)
            {
                if (v[i][j].u && v[i][j].x - 1 != -1)
                {
                    if (!v[i - 1][j].d)
                    {
                        pair<int, int> p(i, j);
                        return p;
                    }
                }
                if (v[i][j].d && v[i][j].x + 1 != v[0].size())
                {
                    if (!v[i + 1][j].u)
                    {
                        pair<int, int> p(i, j);
                        return p;
                    }
                }
                if (v[i][j].l && v[i][j].y - 1 != -1)
                {
                    if (!v[i][j - 1].r)
                    {
                        pair<int, int> p(i, j);
                        return p;
                    }
                }
                if (v[i][j].r && v[i][j].y + 1 != v.size())
                {
                    if (!v[i][j + 1].l)
                    {
                        pair<int, int> p(i, j);
                        return p;
                    }
                }
            }
        }
    }
}