#include <gtest/gtest.h>

#include "game_logic.h"
#include "controller.h"

#include <vector>
#include <string>


int main()
{
    std::vector<std::string> arg;
    arg.push_back("block");
    arg.push_back("block");
    arg.push_back("cross");

    game_logic test(4, 4, std::vector<std::pair<size_t, size_t>>(), std::map<std::pair<size_t, size_t>, size_t>(),
                    arg);

    test.draw();
    controller cntrl(&test);
    cntrl.control_loop();
}
/*
 *
game_logic::game_logic(size_t width, size_t height, std::vector<std::pair<size_t, size_t>> char_positions,
                       std::map<std::pair<size_t, size_t>, size_t> connection_rules) : width(width), height(height)
 */
