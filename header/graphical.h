#ifndef GRAPHICAL_DOTH
#define GRAPHICAL_DOTH


#include <console.h>
#include <vector>
#include <string>
#include <map>

#include "character.h"

#include "color_dec.h"

class menu_painter {
public:
    void draw(std::vector<std::string> options, size_t selected);

};

class painter final {
public:
    painter();
    ~painter();
    void print_rules(std::map<const character*, size_t> con_rules);
    void print_info(size_t x_pos, size_t y_pos, std::string& name, character* inhabitant);
    void draw_tile(size_t x_pos, size_t y_pos, size_t width, size_t height, std::string& name);

   // void draw_board(std::vector<std::vector<tile>>& tiles);
};


#endif
