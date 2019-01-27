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
                    arg, 4, 4);

    test.draw();
    controller cntrl(&test);
    cntrl.control_loop();
}

