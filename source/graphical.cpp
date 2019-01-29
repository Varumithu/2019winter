#include "graphical.h"
#include "console.h"



void menu_painter::draw(std::vector<std::string> options, size_t selected) {
    con_clearScr();
    if (options.size() == 0) {
        con_outTxt("No choice");
        return;

    }
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

void painter::print_rules(const std::vector<bool>& con_rules, const std::vector<character>& chars){
    con_clearScr();
    con_setColor(black_on_white);
    for (size_t i = 0; i < chars.size(); ++i) {
        for (size_t j = 0; j < chars.size() - i; ++j) {
            con_outTxt("%s at %d, %d with %s at %d, %d - DO ", chars[i].name.c_str(), chars[i].x_pos, chars[i].y_pos,
                       chars[j].name.c_str(), chars[j].x_pos, chars[j].y_pos);
            if (!con_rules[j + i * chars.size()]) {
                con_outTxt("NOT");
            }
            con_outTxt("CONNECT\n");
        }
    }

}

void painter::print_res(bool res) {
    con_clearScr();
    con_setColor(white_on_black);
    if (res) {
        con_outTxt("THE WINRAR IS YOU");
    }
    else {
        con_outTxt("YOU FAILED");
    }
}

painter::painter(){
    con_init();
    con_initPair(white_on_black, CON_COLOR_WHITE, CON_COLOR_BLACK);
    con_initPair(black_on_white, CON_COLOR_BLACK, CON_COLOR_WHITE);
    con_initPair(black_on_red, CON_COLOR_BLACK, CON_COLOR_RED);

}

void painter::print_info(size_t x_pos, size_t y_pos, std::string& name, character* inhabitant) {
    con_clearScr();
    con_setColor(black_on_white);

    con_outTxt("Tile at x = %d, y = %d of type %s\ntile inhabitant is ", x_pos, y_pos, name.c_str());
    if (inhabitant == nullptr) {
        con_outTxt(" NULL");
    }
    else {
        con_outTxt("%s, lives on %s side\n", inhabitant->name.c_str(), SideToString(inhabitant->side).c_str());
    }
}


void painter::draw_tile(size_t x_pos, size_t y_pos, size_t width, size_t height, std::string& name) {
    char tiletext = '#';

    if (name == "cross") {
        tiletext = '1';
    }
    else if (name == "west to north") {
        tiletext = '2';
    }
    else if (name == "north to south") {
        tiletext = '3';
    }
    else if (name == "west to east") {
        tiletext = '4';
    }
    else if (name == "north to east") {
        tiletext = '5';
    }
    else if (name == "west to south") {
        tiletext = '6';
    }

    if ((x_pos + y_pos) % 2 == 0) {
        con_setColor(black_on_red);
    }
    else {
        con_setColor(black_on_white);

    }
    for (size_t i = 0; i < width; ++i) {
        for (size_t j = 0; j < height; ++j) {
            con_gotoXY(static_cast<int>(x_pos * width + i), static_cast<int>(y_pos * height + j));
            con_outTxt("%c", tiletext);
        }

    }
}


painter::~painter() {
    con_deinit();
}
