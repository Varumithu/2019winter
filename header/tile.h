#ifndef TILE_DOTH
#define TILE_DOTH

#include "character.h"


class tile final {
public:
    tile(std::vector<bool>& pathways, size_t x_pos, size_t y_pos): pathways(pathways), x_pos(x_pos), y_pos(y_pos) {}
    void draw();
    size_t x_pos, y_pos;
    std::vector<bool> pathways; // from north clockwise 0 1 2 3
    character* inhabitant = nullptr;
};











#endif
