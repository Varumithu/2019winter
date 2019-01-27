#include "tile.h"
#include <console.h>

#include "color_dec.h"

void tile::draw() {
    graphical->draw_tile(this->x_pos, y_pos, this->tile_width, tile_height, name);
}
