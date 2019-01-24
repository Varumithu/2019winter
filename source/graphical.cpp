#include "graphical.h"



painter::painter(){
    con_init();
    con_initPair(white_on_black, CON_COLOR_WHITE, CON_COLOR_BLACK);
    con_initPair(black_on_white, CON_COLOR_BLACK, CON_COLOR_WHITE);

}



void painter::draw_board(std::vector<std::vector<tile>>& tiles){
    for (size_t i = 0; i < tiles.size(); ++i) {
        for (size_t j = 0; j < tiles.begin()->size(); ++j) {
            tiles[i][j].draw();
        }
    }
}


painter::~painter() {
    con_deinit();
}
