#include "game_logic.h"

#include <vector>
#include <set>

/*
for every character finds all characters it connects to
*/


void game_logic::draw() {
    for (size_t i = 0; i < tiles.size(); ++i) {
        for (size_t j = 0; j < tiles.begin()->size(); ++j) {
            tiles[i][j].draw();
        }
    }

}

void game_logic::shift_abstract_position(int dx, int dy) {
    int conx, cony;
    if (abstract_x + dx > -1 && abstract_x + dx < static_cast<int>(width) && abstract_y + dy > -1 && abstract_y + dy < static_cast<int>(height)) {
        abstract_x += dx;
        abstract_y += dy;
        con_getXY(&conx, &cony);
        con_gotoXY(conx + dx * static_cast<int>(tile_width), cony + dy * static_cast<int>(tile_height));
    }
}

game_logic::game_logic(size_t width, size_t height, std::vector<std::pair<size_t, size_t>> char_positions,
                       std::map<std::pair<size_t, size_t>, size_t> connection_rules) : width(width), height(height)
{
    size_t char_type = 0;
    isvisited = std::vector<bool>(false, width * height);
    tiles.resize(width);
    for (size_t i = 0; i < width * height; ++i) {
        tiles[i / width].push_back(tile(block, i % width, i / width, &graphical));

    }
    for (size_t i = 0; i < char_positions.size(); ++i) {

        this->chars.emplace_back();
        chars.back().x_pos = char_positions[i].first;
        chars.back().y_pos = char_positions[i].second;
        tiles[char_positions[i].second][char_positions[i].first].inhabitant = &chars.back();
        char_type = (++char_type) % amount_of_character_types;
        rules.insert({&chars.back(), connection_rules[{chars.back().x_pos, chars.back().y_pos}]});
    }
}

void game_logic::step_aux(size_t x_pos, size_t y_pos,  size_t current_set, size_t i) {
    switch (i) {
        case 0: if (y_pos > 0 && !isvisited[(y_pos - 1) * width + x_pos])
                    labyrinth_step(x_pos, y_pos - 1, South, current_set);
                break;

        case 1: if (x_pos < width - 1 && !isvisited[(y_pos) * width + x_pos + 1])
                    labyrinth_step(x_pos + 1, y_pos, West, current_set);
                break;
        case 2: if (y_pos < height - 1 && !isvisited[(y_pos + 1) * width + x_pos])
                    labyrinth_step(x_pos, y_pos + 1, North, current_set);
                break;
        case 3: if (x_pos > 0 && !isvisited[(y_pos) * width + x_pos - 1])
                    labyrinth_step(x_pos - 1, y_pos, East, current_set);
                break;
    }
}

void game_logic::labyrinth_step(size_t x_pos, size_t y_pos, Side where_from, size_t current_set) {
    this->isvisited[y_pos * width + x_pos] = true;
    if (this->tiles[y_pos][x_pos].inhabitant != nullptr) {
        this->connected_chars_sets[tiles[y_pos][x_pos].inhabitant] = current_set;
    }
    for (size_t i = 0; i < 4; ++i) {// i == 0 - up, 1 - right, 2 - down, 3 - left
        if (where_from == Center) {
            for (size_t j = 0; j < 4; ++j) {
                if (tiles[y_pos][x_pos].pathways[j * 4 + i]) {
                    step_aux(x_pos, y_pos, current_set, i);
                }
            }
        }
        else if (this->tiles[y_pos][x_pos].pathways[where_from * 4 + i]) {
            step_aux(x_pos, y_pos, current_set, i);
        }
    }
}

void game_logic::check_connections( ) {
    size_t i = 0;

    for (auto it = this->chars.begin(); it != chars.end(); ++it){

        if (connected_chars_sets.find(&(*it)) == connected_chars_sets.end()) {
            labyrinth_step(it->x_pos, it->y_pos, it->side, i);
            ++i;
        }
    }
}
