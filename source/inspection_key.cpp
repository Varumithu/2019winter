#include "inspection_key.h"



int inspection_key::process_key(int key) {
    this->game->draw();
    return switch_to_field;
}
