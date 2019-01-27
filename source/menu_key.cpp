#include "menu_key.h"


int menu_key::process_key(int key) {
    switch (key) {
    case CON_KEY_UP:
        game->game_menu.shift_selection(-1);
        break;
    case CON_KEY_DOWN:
        game->game_menu.shift_selection(1);
        break;
    case CON_KEY_ESCAPE:
        this->game->draw();
        return switch_to_field;
    case CON_KEY_ENTER:
        this->game->draw();
        if (game->game_menu.available_tiles_names.size() > 0) {
            return switch_to_placement;
        }
        else {
            return switch_to_field;
        }
    }

    return remain;
}
