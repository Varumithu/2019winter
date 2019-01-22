#ifndef GAME_LOGIC_DOTH_
#define GAME_LOGIC_DOTH_

#include <vector>
#include <set>
#include <map>

/*
Tile has a 2d array (2*2) of booleans which says which exits are connected to which
Tile also has a pointer to character, NULL if empty

I actually see the point of inheritance, every character is a derived class with draw method overload

board has a 2d array of pointers to tiles

game_logic constructor takes arguments: std::vector<std::pair<std::pair<size_t, size_t>, std::string>> - correlation between
board positions and character names;
std::vector<std::set<std::string>>
*/




class character{
public:
	virtual ~character();
	virtual void draw();
    size_t x_pos, y_pos;
    size_t side; // on which side of tile the character lives, 0 is up, 1 is right, 2 is down, 3 is left
};

class tile final {
public:
    tile();
    void draw();

    bool pathways[16]; // from north clockwise 0 1 2 3
    character* inhabitant = nullptr;
};

class board final {
public:
    size_t width, height;
    std::vector <std::vector<tile>> tiles;
    std::vector<std::pair<character, std::pair<size_t, size_t>>> chars;
};


class game_logic final {
public:
    std::map<character*, size_t> connected_chars_sets;// first is pointer to character, second is the number of connected set it is a part of
    void labyrinth_step(size_t x_pos, size_t y_pos, size_t where_from);
    std::vector<bool> isvisited; // don't forget to put isvisited = std::vector<bool>(false, width * height)
    game_logic();
    void place_character();
    board this_board;
	void check_connections();
};


#endif
