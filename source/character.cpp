#include "character.h"

character::character() {
    x_pos = 0;
    y_pos = 0;
    side = Center;

}

void character::draw() {

}

character::character(const character& that) : x_pos(that.x_pos), y_pos(that.y_pos), side(that.side) {}
