#include "graphical.h"



painter::painter(){
    con_init();
    con_initPair(wight_on_black, CON_COLOR_WHITE, CON_COLOR_BLACK);

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
