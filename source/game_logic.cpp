#include "game_logic.h"


/*
for every character finds all characters it connects to
*/

void game_logic::labyrinth_step(size_t x_pos, size_t y_pos, size_t where_from) {
    this->isvisited[y_pos * this_board.width + x_pos] = true;
    for (size_t i = 0; i < 4; ++i) {// i == 0 - up, 1 - right, 2 - down, 3 - left
        if (this->this_board.tiles[y_pos][x_pos].pathways[where_from * 4 + i]) {
            switch (i) {
                case 0 : labyrinth_step(x_pos, y_pos - 1, 2);
                         break;
                case 1 : labyrinth_step(x_pos + 1, y_pos, 3);
                         break;
                case 2 : labyrinth_step(x_pos, y_pos + 1, 0);
                         break;
                case 3 : labyrinth_step(x_pos - 1, y_pos, 1);
                         break;
            }
        }
    }
}

void game_logic::check_connections() { 
    for (auto it = this->this_board.chars.begin(); it != this_board.chars.end(); ++it){

    }
}
