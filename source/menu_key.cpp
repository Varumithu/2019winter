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
        con_gotoXY(0, 0);
        this->game->draw();
        return switch_to_field;
    }
    return remain;
}
