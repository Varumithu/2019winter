#ifndef GRAPHICAL_DOTH
#define GRAPHICAL_DOTH


#include <console.h>
#include <vector>

#include "tile.h"
#include "color_dec.h"

class painter final {
public:
    painter();
    ~painter();

    void draw_tile(tile& that);

    void draw_board(std::vector<std::vector<tile>>& tiles);
};


#endif
