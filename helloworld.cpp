#include "graphics.hpp"
#include "puzzlegame.h"
#include <vector>
#include <set>
#include <iostream>
#include <unistd.h>

using namespace genv;
using namespace std;

const int XX = 1000;
const int YY = 750;
const int res = 250; //>100
const int border_width = 5;
const int pipe_width = res / 5;
vector<Table> tables;
vector<Table> temp;

int main()
{
    gout.open(XX + 300, YY);
    gout << refresh;
    event ev;
    gin.timer(100);
    gout << color(70, 70, 70) << move_to(0, 0) << box(XX + 300, YY) << move_to(0, 0);

    Table t(XX, YY, res, border_width);

    t.v[1][1] = t.choice_to_tile(4);
    // t.v[1][1].rotate(2);
    t.v[1][1].source = true;
    t.v[2][3] = t.choice_to_tile(0);
    t.v[2][3].drain = true;
    t.rajzol();
    t.draw_choices(YY);

    while (gin >> ev && ev.keycode != key_escape)
    {
        if (ev.type == ev_mouse)
        {
            if (ev.button == btn_left)
            {
                int x = ev.pos_x;
                int y = ev.pos_y;
                // gout << move_to(10, 10 + i* YY2*

                if (x > 5 && x < 100 && y > 10 && y < 550)
                {
                    int i = y / 110;
                    t.add_tile(i);
                    t.draw_choices(YY);
                }
                if (x > 100 && x < 300 && y > 10 && y < 550)
                {
                    int i = y / 110;
                    t.sub_tile(i);
                    t.draw_choices(YY);
                }
                if (x > 5 && x < 100 && y > 550)
                {
                    int a = y / 110;
                    // cout << i << endl;
                    t.set_selected(a);
                    t.rajzol();
                }
                if (x > 300)
                {
                    int i = (x - 300) / res;
                    int j = y / res;
                    t.v[j][i].is_selected = !t.v[j][i].is_selected;
                    gout << move_to(i * res + border_width + 300, j * res + border_width);
                    t.v[j][i].draw_tile(res, border_width, pipe_width);
                    gout << refresh;
                }
            }
        }
        if (ev.type == ev_key)
        {
            if (ev.keycode == key_space)
            {
                t.rotate_selected();
                t.rajzol();
            }
        }
        if (ev.type == ev_key)
        {
            if (ev.keycode == key_enter)
            {
                temp = t.find_routes();
                tables.insert(tables.end(), temp.begin(), temp.end());
                for (Table t : tables)
                {
                    t.rajzol();
                    usleep(500000);
                }
            }
        }
    }

    return 0;
}
