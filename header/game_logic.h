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




class game_logic final {


public:
    game_logic(size_t width, size_t height, std::vector<std::pair<std::pair<size_t, size_t>, Side>> char_positions,
               std::vector<bool> connection_rules, std::vector<std::string>& available_tiles,
               size_t tile_width, size_t tile_height);
    size_t width, height;

    void place_tile();

    void draw_menu();

    void print_rules();

    void inspect_tile();

    int abstract_x = static_cast<int>(width) - 1, abstract_y = static_cast<int>(height) - 1;

    size_t tile_width = 1, tile_height = 1;

    void shift_abstract_position(int dx, int dy);

    void check_win();

    std::vector<bool> connection_matrix, rules_matrix;

    void draw();

    menu game_menu;

    std::vector<std::vector<tile>> tiles;
    std::vector<character> chars;
    void labyrinth_step(size_t x_pos, size_t y_pos, Side where_from, std::vector<size_t>& current_set);

    void step_aux(size_t x_pos, size_t y_pos, std::vector<size_t>& current_set, size_t i);

    painter graphical;

    std::vector<bool> isvisited;
    game_logic();
    void place_character();

	void check_connections();
};


#endif
