#include <gtest/gtest.h>

#include "game_logic.h"




int main(int argc, char** argv)
{
    game_logic(4, 4, std::vector<std::pair<size_t, size_t>>(), std::map<std::pair<size_t, size_t>, size_t>());

}
/*
 *
game_logic::game_logic(size_t width, size_t height, std::vector<std::pair<size_t, size_t>> char_positions,
                       std::map<std::pair<size_t, size_t>, size_t> connection_rules) : width(width), height(height)
 */
