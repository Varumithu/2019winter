#include <gtest/gtest.h>

#include "game_logic.h"
#include "controller.h"

#include <vector>
#include <string>


int main()
{
    std::vector<std::string> arg(16, "cross");

    std::vector<std::pair<std::pair<size_t, size_t>, Side>> char_positions {{{0, 0}, South}, {{15, 0}, East}};
    std::vector<bool> ruleset = {true, true, true, true};

    game_logic test(16, 11, char_positions, ruleset,
                    arg, 3, 2);

    test.draw();
    controller cntrl(&test);
    cntrl.control_loop();
}

