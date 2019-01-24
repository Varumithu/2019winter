#include "tile.h"
#include <console.h>

#include "color_dec.h"

void tile::draw() {
    con_gotoXY(static_cast<int>(x_pos), static_cast<int>(y_pos));
    if ((x_pos + y_pos) % 2 == 0) {

        con_setColor(white_on_black);
        con_outTxt(" ");
    }
    else {

        con_setColor(black_on_white);
        con_outTxt(" ");
    }
}
