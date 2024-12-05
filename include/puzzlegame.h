#ifndef PIPEPUZZLE_H // Prevent multiple inclusions of this header
#define PIPEPUZZLE_H

#include <vector>

using namespace std;

struct Tile
{
    bool l, r, u, d, source, drain, is_selected;
    int x, y;
    int howmany();
    void draw_tile(int size, int bw, int pw);
    void rotate(int n);
    bool is_legal(int xe, int ye);
    bool does_match(Tile uj);
};

struct Table
{
    vector<vector<vector<Tile>>> routes;
    vector<vector<Tile>> v;
    vector<int> choices;
    vector<vector<bool>> options;
    // set<vector<vector<Tile>>> poss;

    Table(int XX, int YY, int res, int border_width);
    void rajzol();
    void add_tile(int i);
    void sub_tile(int i);
    void draw_choices(int YY);
    void set_selected(int a);
    void rotate_selected();
    Tile get_source();
    Tile get_drain();
    Tile choice_to_tile(int i);
    vector<Table> find_routes();
};

#endif