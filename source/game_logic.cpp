#include "game_logic.h"

#include <vector>
#include <set>

/*
for every character finds all characters it connects to
*/

void game_logic::place_tile() {
    game_menu.available_tiles_pathways.push_back(tiles[static_cast<size_t>(abstract_y)][static_cast<size_t>(abstract_x)].pathways);
    game_menu.available_tiles_names.push_back(tiles[static_cast<size_t>(abstract_y)][static_cast<size_t>(abstract_x)].name);
    tiles[static_cast<size_t>(abstract_y)][static_cast<size_t>(abstract_x)].pathways = game_menu.available_tiles_pathways[game_menu.selected];
    tiles[static_cast<size_t>(abstract_y)][static_cast<size_t>(abstract_x)].name = game_menu.available_tiles_names[game_menu.selected];
    game_menu.available_tiles_names.erase(game_menu.available_tiles_names.begin() + static_cast<long>(game_menu.selected));
    game_menu.available_tiles_pathways.erase(game_menu.available_tiles_pathways.begin() + static_cast<long>(game_menu.selected));
    game_menu.selected = 0;
    draw();
}

void game_logic::print_rules() {
    graphical.print_rules(rules_matrix, chars);

}

void game_logic::draw_menu() {
    game_menu.graphical.draw(game_menu.available_tiles_names, game_menu.selected);
}

void game_logic::check_win() {
    check_connections();
    bool res = true;
    if (rules_matrix != connection_matrix) {
        res = false;
    }

    graphical.print_res(res);
    connection_matrix = std::vector<bool>(chars.size() * chars.size(), false);
    isvisited = std::vector<bool>(isvisited.size(), false);
    for (auto it = chars.begin(); it != chars.end(); ++it) {
        it->isvisited = false;
    }
}

// TODO implement isvisited for individual parts of tile

void game_logic::draw() {
    con_clearScr();
    for (size_t i = 0; i < tiles.size(); ++i) {
        for (size_t j = 0; j < tiles.begin()->size(); ++j) {
            tiles[i][j].draw();
        }
    }
    con_gotoXY(abstract_x * static_cast<int>(tile_width), abstract_y * static_cast<int>(tile_height));

}

void game_logic::inspect_tile() {
    graphical.print_info(tiles[static_cast<size_t>(abstract_y)][static_cast<size_t>(abstract_x)].x_pos,
                         tiles[static_cast<size_t>(abstract_y)][static_cast<size_t>(abstract_x)].y_pos,
                         tiles[static_cast<size_t>(abstract_y)][static_cast<size_t>(abstract_x)].name,
                         tiles[static_cast<size_t>(abstract_y)][static_cast<size_t>(abstract_x)].inhabitant);
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

game_logic::game_logic(size_t width, size_t height, std::vector<std::pair<std::pair<size_t, size_t>, Side>> char_positions,
                       std::vector<bool> connection_rules, // a matrix, order the same as char_positions
                       std::vector<std::string>& available_tiles,
                       size_t tile_width, size_t tile_height) : width(width),
    height(height), tile_width(tile_width), tile_height(tile_height), rules_matrix(connection_rules), game_menu(available_tiles)
{
    size_t char_type = 0;
    isvisited = std::vector<bool>(width * height, false);
    tiles.resize(height);

    for (size_t i = 0; i < width * height; ++i) {
        tiles[i / width].push_back(tile(block, i % width, i / width, &graphical, "block", tile_width, tile_height));

    }
    chars.resize(char_positions.size());
    for (size_t i = 0; i < char_positions.size(); ++i) {

        //this->chars.push_back(character());
        chars[i].x_pos = char_positions[i].first.first;
        chars[i].y_pos = char_positions[i].first.second;
        chars[i].name = std::string("default"); // TODO make a thing to choose char type
        chars[i].number = i;
        chars[i].side = char_positions[i].second;
        tiles[char_positions[i].first.second][char_positions[i].first.first].inhabitant = &chars[i];
        char_type = (++char_type) % amount_of_character_types;
        //rules.insert({&chars.back(), connection_rules[{chars.back().x_pos, chars.back().y_pos}]});

    }
    this->connection_matrix.resize(rules_matrix.size());
}

void game_logic::step_aux(size_t x_pos, size_t y_pos,  std::vector<size_t>& current_set, size_t i) {
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

void game_logic::labyrinth_step(size_t x_pos, size_t y_pos, Side where_from, std::vector<size_t>& current_set) {
    this->isvisited[y_pos * width + x_pos] = true;
    if (this->tiles[y_pos][x_pos].inhabitant != nullptr) {
        bool flag = false;
        tile& cur = tiles[y_pos][x_pos];
        if (where_from == Center) {
            if (cur.inhabitant->side == Center) {
                flag = true;
            }
            else for (size_t i = 0; i < 4; ++i) {
                if (tiles[y_pos][x_pos].pathways[cur.inhabitant->side * 4 + i]){
                    flag = true;
                    break;
                }
            }
        }
        else if (cur.pathways[where_from * 4 + cur.inhabitant->side]) {
            flag = true;
        }
        else if (where_from == cur.inhabitant->side) {
            flag = true;
        }
        if (flag) {
            current_set.push_back(tiles[y_pos][x_pos].inhabitant->number);
            cur.inhabitant->isvisited = true;
        }
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

        if (!it->isvisited) {
            std::vector<size_t> curset;
            labyrinth_step(it->x_pos, it->y_pos, it->side, curset);
            for (size_t j = 0; j < curset.size(); ++j) {
                for (size_t k = 0; k < curset.size(); ++k) {
                    connection_matrix[curset[j] * chars.size() + curset[k]] = true;
                }
            }
            ++i;
        }
    }
}
