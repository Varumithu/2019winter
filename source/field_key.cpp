#include "field_key.h"



int field_key::process_key(int key) {
    switch (key) {
    case CON_KEY_ESCAPE:
        return 0;
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
        return switch_to_menu;
    case 'i':
        game->inspect_tile();
        return switch_to_inspection;
    default:
        return 0;
    }

    return remain;
}
