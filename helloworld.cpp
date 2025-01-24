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
const int res = 50; //>100
const int gridx = 3;
const int gridy = 3;
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
    
    Table t(gridx, gridy, YY, res, border_width);

    //elagazas feladat

    // t.v[0][0] = t.choice_to_tile(0);
    // t.v[0][0].rotate(2);
    // t.v[0][0].source = true;
    // t.v[0][2] = t.choice_to_tile(0);
    // t.v[0][2].drain = true;
    // t.v[1][1] = t.choice_to_tile(0);
    // t.v[1][1].rotate(1);
    // t.v[1][1].drain = true;

    //kanyar feladat

    // t.v[0][0] = t.choice_to_tile(0);
    // t.v[0][0].rotate(2);
    // t.v[0][0].source = true;
    // t.v[1][2] = t.choice_to_tile(0);
    // t.v[1][2].drain = true;

    //nagy kanyar feladat

    // t.v[0][0] = t.choice_to_tile(0);
    // t.v[0][0].rotate(2);
    // t.v[0][0].source = true;
    // t.v[2][2] = t.choice_to_tile(0);
    // t.v[2][2].drain = true;
    


    // t.v[0][1] = t.choice_to_tile(2);
    // t.v[0][2] = t.choice_to_tile(1);
    // t.v[0][2].rotate(3);
    // t.v[1][2] = t.choice_to_tile(2);
    // t.v[1][2].rotate(1);
    // Tile asd = t.get_free_ends();

    //parallel 2 feladat

    // t.v[0][1] = t.choice_to_tile(1);
    // t.v[0][1].rotate(3);
    // t.v[0][1].source = true;
    // t.v[1][0] = t.choice_to_tile(1);
    // t.v[1][0].rotate(1);
    // t.v[1][0].drain = true;

    //tobb forras feladat

    t.v[0][0] = t.choice_to_tile(0);
    t.v[0][0].rotate(2);
    t.v[0][0].source = true;
    t.v[0][2] = t.choice_to_tile(0);
    //t.v[0][2].rotate(2);
    t.v[0][2].source = true;
    t.v[2][2] = t.choice_to_tile(0);
    //t.v[2][2].rotate(2);
    t.v[2][2].drain = true;



    t.rajzol();
    t.draw_choices(YY);
    gout << refresh;

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
                
                pair<int, int> sourcecoords;
                sourcecoords.first = t.get_source().x;
                sourcecoords.second = t.get_source().y;
                temp = t.find_routes(sourcecoords);
                tables.insert(tables.end(), temp.begin(), temp.end());
                
                int tilesetsum;
                for (size_t i = 0; i < t.tileset.size(); i++)
                {
                    tilesetsum += t.tileset[i];
                }
                

                for (size_t i = 0; i < tilesetsum -1; i++)
                {
                    t = tables[i];
                    pair<int, int> asd = t.get_free_ends();
                    temp = t.find_routes(asd);
                    tables.insert(tables.end(), temp.begin(), temp.end());
                    t = tables[2];
                    t.rajzol();
                }
                
                
                
                // t = tables[tables.size() - 1];
                // asd = t.get_free_ends();
                // temp = t.find_routes(asd);
                // tables.insert(tables.end(), temp.begin(), temp.end());
                // t.rajzol();

                
            }
        }
    }

    return 0;
}
