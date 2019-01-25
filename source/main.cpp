#include <gtest/gtest.h>

#include "game_logic.h"
#include "controller.h"



int main(int argc, char** argv)
{
    game_logic test(4, 4, std::vector<std::pair<size_t, size_t>>(), std::map<std::pair<size_t, size_t>, size_t>());
    test.graphical.draw_board(test.tiles);
    controller cntrl;
    cntrl.control_loop();
}
/*
 *
game_logic::game_logic(size_t width, size_t height, std::vector<std::pair<size_t, size_t>> char_positions,
                       std::map<std::pair<size_t, size_t>, size_t> connection_rules) : width(width), height(height)
 */
