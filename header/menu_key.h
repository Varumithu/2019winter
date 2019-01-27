#ifndef MENU_KEY_DOTH
#define MENU_KEY_DOTH

#include "key_processor.h"

class menu_key final: public key_processor {
public:
    menu_key() = default;
    ~menu_key() = default;
    int process_key(int key);
};

#endif
