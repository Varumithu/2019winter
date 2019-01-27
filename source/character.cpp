#include "character.h"

character::character() {
    x_pos = 0;
    y_pos = 0;
    side = Center;

}

std::string SideToString(Side side) {
    switch(side) {
    case 0:
        return "North";
    case 1:
        return "East";
    case 2:
        return "South";
    case 3:
        return "West";
    case 4:
        return "Center";
    }
}

void character::draw() {

}

character::character(const character& that) : x_pos(that.x_pos), y_pos(that.y_pos), side(that.side) {}
