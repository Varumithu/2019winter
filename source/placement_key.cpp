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
        game->tiles[static_cast<size_t>(game->abstract_y)][static_cast<size_t>(game->abstract_x)].pathways = game->game_menu.available_tiles_pathways[game->game_menu.selected];
        game->tiles[static_cast<size_t>(game->abstract_y)][static_cast<size_t>(game->abstract_x)].name = game->game_menu.available_tiles_names[game->game_menu.selected];
        game->draw();
        return switch_to_field;
    default:
        return exit_all;
    }
    return remain;
}
