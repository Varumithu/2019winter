#include "graphical.h"
#include "console.h"



void menu_painter::draw(std::vector<std::string> options, size_t selected) {
    con_clearScr();

    con_setColor(black_on_white);
    for (size_t i = 0; i < selected; ++i) {

        con_outTxt("%s\n", options[i].c_str());
    }
    con_setColor(black_on_red);
    con_outTxt("%s\n", options[selected].c_str());
    con_setColor(black_on_white);
    for (size_t i = selected + 1; i < options.size(); ++i) {

        con_outTxt("%s\n", options[i].c_str());
    }
}

painter::painter(){
    con_init();
    con_initPair(white_on_black, CON_COLOR_WHITE, CON_COLOR_BLACK);
    con_initPair(black_on_white, CON_COLOR_BLACK, CON_COLOR_WHITE);
    con_initPair(black_on_red, CON_COLOR_BLACK, CON_COLOR_RED);

}




void painter::draw_tile(size_t x_pos, size_t y_pos, size_t width, size_t height) {

    if ((x_pos + y_pos) % 2 == 0) {

        con_setColor(black_on_red);
    }
    else {
        con_setColor(black_on_white);

    }
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < height; ++j) {
            con_gotoXY(static_cast<int>(x_pos * width + i), static_cast<int>(y_pos * height + j));
            con_outTxt(" ");
        }

    }
}


painter::~painter() {
    con_deinit();
}
