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
        game->draw_menu();
        return switch_to_menu;
    case 'i':
        game->inspect_tile();
        return switch_to_inspection;
    case 'r':
        game->print_rules();
        return switch_to_ruleset;
    case 'w':
        game->check_win();
        return switch_to_resscreen;
    default:
        return 0;
    }

    return remain;
}
