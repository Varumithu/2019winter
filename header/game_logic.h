#ifndef GAME_LOGIC_DOTH_
#define GAME_LOGIC_DOTH_

class board final {

};

/*
Tile has a 2d array (2*2) of booleans which says which exits are connected to which
Tile also has a pointer to character, NULL if empty

I actually see the point of inheritance, every character is a derived class with draw method overload

board has a 2d array of pointers to tiles

game_logic constructor takes arguments: std::vector<std::pair<std::pair<size_t, size_t>, std::string>> - correlation between
board positions and character names;
std::vector<std::set<std::string>>
*/
class tile final {
    tile();
};

class character final {

};

class game_logic final {
public:
    game_logic();
    void place_character();
    board board;
};


#endif
