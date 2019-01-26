#ifndef TILE_DOTH
#define TILE_DOTH

#include "character.h"
#include "graphical.h"


/*
 * north, east, south, west // north
 * north, east, south, west // east
 * north, east, south, west // south
 * north, east, south, west // west
 */

static std::vector<bool> block {
    false, false, false, false,
    false, false, false, false,
    false, false, false, false,
    false, false, false, false,
};


static std::vector<bool> west_to_north {
    false, false, false, true,
    false, false, false, false,
    false, false, false, false,
    true, false, false, false,
};


static std::vector<bool> north_to_south {
    false, false, true, false,
    false, false, false, false,
    true, false, false, false,
    false, false, false, false,
};


static std::vector<bool> west_to_east {
    false, false, false, false,
    false, false, false, true,
    false, false, false, false,
    false, true, false, false,
};


static std::vector<bool> north_to_east {
    false, true, false, false,
    true, false, false, false,
    false, false, false, false,
    false, false, false, false,
};


static std::vector<bool> west_to_south {
    false, false, false, false,
    false, false, false, false,
    false, false, false, true,
    false, false, true, false,
};


static std::vector<bool> cross {
    false, true, true, true,
    true, false, true, true,
    true, true, false, true,
    true, true, true, false,
};

class tile final {
public:

    tile(std::vector<bool>& pathways, size_t x_pos, size_t y_pos, painter* graphical, std::string name,
         size_t tile_width, size_t tile_height): graphical(graphical),
        pathways(pathways), x_pos(x_pos), y_pos(y_pos), name(name), tile_width(tile_width), tile_height(tile_height) {}

    std::string name = "block";

    painter* graphical;
    size_t tile_width = 1, tile_height = 1;
    void draw();
    size_t x_pos, y_pos;
    std::vector<bool> pathways; // from north clockwise 0 1 2 3
    character* inhabitant = nullptr;
};











#endif
