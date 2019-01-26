#ifndef MENU_DOTH
#define MENU_DOTH

#include <vector>

#include "tile.h"
#include "graphical.h"

class menu final{
public:
    menu_painter graphical;

    menu(std::vector<std::string>& available_tiles);
    size_t selected = 0;
    std::vector<std::string> available_tiles_names;
    std::vector<std::vector<bool>> available_tiles_pathways;

    void draw();
};


#endif
