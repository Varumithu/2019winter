#ifndef FIELD_KEY_DOTH
#define FIELD_KEY_DOTH

#include "key_processor.h"

class field_key : public key_processor{ // will have a derived class placement key because moving cursor around is the same
public:
    field_key() = default;
    ~field_key() = default;
    bool move_around(int key);
    int process_key(int key);
};


#endif
