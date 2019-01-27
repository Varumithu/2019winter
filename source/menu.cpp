#include "menu.h"

#include <vector>
#include <string>

menu::menu(std::vector<std::string>& available_tiles) : available_tiles_names(available_tiles){
    for (size_t i = 0; i < available_tiles.size(); ++i) {
        if (available_tiles[i] == "block") {
            available_tiles_pathways.push_back(block);
        }
        else if (available_tiles[i] == "cross") {
            available_tiles_pathways.push_back(cross);
        }
        else if (available_tiles[i] == "west to north") {
            available_tiles_pathways.push_back(west_to_north);
        }
        else if (available_tiles[i] == "north to south") {
            available_tiles_pathways.push_back(north_to_south);
        }
        else if (available_tiles[i] == "west to east") {
            available_tiles_pathways.push_back(west_to_east);
        }
        else if (available_tiles[i] == "north to east") {
            available_tiles_pathways.push_back(north_to_east);
        }
        else if (available_tiles[i] == "west to south") {
            available_tiles_pathways.push_back(west_to_south);
        }
        else {
            available_tiles_names.erase(available_tiles_names.begin() + static_cast<long>(i));
        }
    }
}

void menu::shift_selection(int shift) {
    long signed_sel = static_cast<long>(selected);
    signed_sel += shift;
    while(signed_sel < 0) {
        signed_sel += available_tiles_names.size();
    }
    while (static_cast<size_t>(signed_sel) >= available_tiles_names.size()) {
        signed_sel -= available_tiles_names.size();
    }
    selected = static_cast<size_t>(signed_sel);
    this->draw();
}


void menu::draw() {
    graphical.draw(available_tiles_names, selected);

}
