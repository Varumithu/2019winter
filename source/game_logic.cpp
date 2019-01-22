#include "game_logic.h"

#include <vector>
#include <set>

/*
for every character finds all characters it connects to
*/

game_logic::game_logic(size_t width, size_t height, std::vector<std::pair<size_t, size_t>> char_positions,
                       std::map<std::pair<size_t, size_t>, size_t> connection_rules) : width(width), height(height)
{

}

void game_logic::labyrinth_step(size_t x_pos, size_t y_pos, Side where_from, size_t current_set) {
    this->isvisited[y_pos * width + x_pos] = true;
    if (this->tiles[y_pos][x_pos].inhabitant != NULL) {
        this->connected_chars_sets[tiles[y_pos][x_pos].inhabitant] = current_set;
    }
    for (size_t i = 0; i < 4; ++i) {// i == 0 - up, 1 - right, 2 - down, 3 - left
        if (this->tiles[y_pos][x_pos].pathways[where_from * 4 + i]) {
            switch (i) {
                case 0 : if (y_pos > 0)
                            if (!isvisited[(y_pos - 1) * width + x_pos])
                                labyrinth_step(x_pos, y_pos - 1, South, current_set);
                         break;

                case 1 : if (x_pos < width - 1)
                            if (!isvisited[(y_pos) * width + x_pos + 1])
                                labyrinth_step(x_pos + 1, y_pos, West, current_set);
                         break;
                case 2 : if (y_pos < height - 1)
                            if (!isvisited[(y_pos + 1) * width + x_pos])
                                labyrinth_step(x_pos, y_pos + 1, North, current_set);
                         break;
                case 3 : if (x_pos > 0)
                            if (!isvisited[(y_pos) * width + x_pos - 1])
                                labyrinth_step(x_pos - 1, y_pos, East, current_set);
                         break;
            }
        }
    }
}

void game_logic::check_connections( ) {
    size_t i = 0;
    for (auto it = this->chars.begin(); it != chars.end(); ++it){

        if (connected_chars_sets.find(&(*it)) == connected_chars_sets.end()) {
            labyrinth_step(it->x_pos, it->y_pos, it->side, i);
            ++i;
        }
    }
}
