#include <gtest/gtest.h>

#include "game_logic.h"
#include "controller.h"

#include <vector>
#include <string>


int main()
{
    std::vector<std::string> arg(16, "cross");

    std::vector<std::pair<size_t, size_t>> char_positions {{0, 0}, {15, 0}};
    std::map<std::pair<size_t, size_t>, size_t> ruleset;
    ruleset[{0, 0}] = 0;
    ruleset[{15, 0}] = 0;
    game_logic test(16, 11, char_positions, ruleset,
                    arg, 2, 2);

    test.draw();
    controller cntrl(&test);
    cntrl.control_loop();
}

