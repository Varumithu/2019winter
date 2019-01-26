#ifndef GAME_LOGIC_DOTH_
#define GAME_LOGIC_DOTH_

#include <vector>
#include <set>
#include <map>

#include "character.h"
#include "graphical.h"
#include "tile.h"
#include "menu.h"

const size_t amount_of_character_types = 1;

/*
Tile has a 2d array (2*2) of booleans which says which exits are connected to which
Tile also has a pointer to character, NULL if empty

I actually see the point of inheritance, every character is a derived class with draw method overload

board has a 2d array of pointers to tiles

game_logic constructor takes arguments: std::vector<std::pair<std::pair<size_t, size_t>, std::string>> - correlation between
board positions and character names;
std::vector<std::set<std::string>>
*/




class game_logic final {


public:
    game_logic(size_t width, size_t height, std::vector<std::pair<size_t, size_t>> char_positions,
               std::map<std::pair<size_t, size_t>, size_t> connection_rules, std::vector<std::string>& available_tiles,
               size_t tile_width, size_t tile_height);
    size_t width, height;

    int abstract_x = static_cast<int>(width) - 1, abstract_y = static_cast<int>(height) - 1;

    size_t tile_width = 1, tile_height = 1;

    void shift_abstract_position(int dx, int dy);

    void draw();

    menu game_menu;

    std::vector<std::vector<tile>> tiles;
    std::vector<character> chars;
    std::map<const character*, size_t> rules;
    std::map<character*, size_t> connected_chars_sets;// first is pointer to character, second is the number of connected set it is a part of
    void labyrinth_step(size_t x_pos, size_t y_pos, Side where_from, size_t current_set);

    void step_aux(size_t x_pos, size_t y_pos, size_t current_set, size_t i);

    painter graphical;

    std::vector<bool> isvisited; // don't forget to put isvisited = std::vector<bool>(false, width * height)
    game_logic();
    void place_character();
   // board this_board;
	void check_connections();
};


#endif
