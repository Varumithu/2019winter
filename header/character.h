#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>

enum Side { North = 0, East = 1, South = 2, West = 3, Center = 4 };

std::string SideToString(Side side);

class character{
public:
    virtual ~character() = default;
    character();
    character(const character& that);
    std::string name;
    virtual void draw();
    size_t x_pos, y_pos;
    Side side; // on which side of tile the character lives
};

#endif // CHARACTER_H
