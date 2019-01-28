#ifndef KEY_PROCESSOR_DOTH
#define KEY_PROCESSOR_DOTH

#include "game_logic.h"

static const int remain = 1;
static const int exit_all = 0;
static const int switch_to_field = 2;
static const int switch_to_placement = 3;
static const int switch_to_menu = 4;
static const int switch_to_inspection = 5;
static const int switch_to_ruleset = 6;
static const int switch_to_resscreen = 7;


class key_processor {
public:
    game_logic* game;

    key_processor() = default;
    virtual ~key_processor() = default;

    virtual int process_key(int key) = 0;


};

#endif
