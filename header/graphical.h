#ifndef GRAPHICAL_DOTH
#define GRAPHICAL_DOTH


#include <console.h>
#include <vector>

#include "color_dec.h"

class menu_painter {
public:
    menu_painter();
    ~menu_painter();


};

class painter final {
public:
    painter();
    ~painter();

    void draw_tile(size_t x_pos, size_t y_pos, size_t width, size_t height);

   // void draw_board(std::vector<std::vector<tile>>& tiles);
};


#endif
