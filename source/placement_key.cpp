#include "placement_key.h"

int placement_key::process_key(int key) {
    switch (key) {
    case CON_KEY_ESCAPE:
        return exit_all;
    case CON_KEY_UP:
        game->shift_abstract_position(0, -1);
        break;
    case CON_KEY_LEFT:
        game->shift_abstract_position(-1, 0);
        break;
    case CON_KEY_DOWN:
        game->shift_abstract_position(0, 1);
        break;
    case CON_KEY_RIGHT:
        game->shift_abstract_position(1, 0);
        break;
    case CON_KEY_ENTER:
        game->place_tile();
        return switch_to_field;
    default:
        return exit_all;
    }
    return remain;
}
