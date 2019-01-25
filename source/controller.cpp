#include "controller.h"
#include "field_key.h"
#include "menu_key.h"
#include "placement_key.h"


#include "console.h"



controller::controller(){
    kprc = new field_key();
}

controller::~controller() {
    delete kprc;
}

void controller::stateswitch(int flag) {
    switch(flag) {
        case exit_all:
            delete kprc;
            kprc = nullptr;
            return;
        case switch_to_menu:
            delete kprc;
            kprc = new menu_key();
            break;
        case switch_to_field:
            delete kprc;
            kprc = new field_key();
            break;
        case switch_to_placement:
            delete kprc;
            kprc = new placement_key();
            break;
        default:
            return;
    }
}


void controller::control_loop() {
    int stateflag = 1;
    while(stateflag != 0) {
        if (kprc == nullptr) {
            break;
        }
        if (con_keyPressed()) {
            stateflag = kprc->process_key(con_getKey());
            stateswitch(stateflag);

        }
    }
}
