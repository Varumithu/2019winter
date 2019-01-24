#ifndef GRAPHICAL_DOTH
#define GRAPHICAL_DOTH


#include <console.h>
#include <vector>

#include "tile.h"

const short wight_on_black = 0;


class painter final {
    painter();
    ~painter();

    void draw_tile(tile& that);

    void draw_board(std::vector<std::vector<tile>>& tiles);
};


#endif
