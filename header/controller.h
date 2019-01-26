#ifndef CONTROLLER_DOTH
#define CONTROLLER_DOTH

#include "game_logic.h"
#include "key_processor.h"
#include "menu.h"

class controller final {
public:
    game_logic* game;
    menu* game_menu;
    key_processor* kprc;
    void stateswitch(int flag);
    controller(game_logic* game);
    ~controller();
    void control_loop();
};







#endif
