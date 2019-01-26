#include "graphical.h"
#include "console.h"



painter::painter(){
    con_init();
    con_initPair(white_on_black, CON_COLOR_WHITE, CON_COLOR_BLACK);
    con_initPair(black_on_white, CON_COLOR_BLACK, CON_COLOR_WHITE);
    con_initPair(black_on_red, CON_COLOR_BLACK, CON_COLOR_RED);

}




void painter::draw_tile(size_t x_pos, size_t y_pos, size_t width, size_t height) {
    con_gotoXY(static_cast<int>(x_pos), static_cast<int>(y_pos));
    if ((x_pos + y_pos) % 2 == 0) {

        con_setColor(black_on_red);
        con_outTxt(" ");
    }
    else {

        con_setColor(black_on_white);
        con_outTxt(" ");
    }
}


painter::~painter() {
    con_deinit();
}
