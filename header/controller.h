#ifndef CONTROLLER_DOTH
#define CONTROLLER_DOTH

#include "game_logic.h"
#include "key_processor.h"

class controller final {
public:
    game_logic* game;

    key_processor* kprc;
    void stateswitch(int flag);
    controller(game_logic* game);
    ~controller();
    void control_loop();
};







#endif
