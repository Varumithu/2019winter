#ifndef FIELD_KEY_DOTH
#define FIELD_KEY_DOTH

#include "key_processor.h"

class field_key final: public key_processor{
public:
    field_key() = default;
    ~field_key() = default;

    int process_key(int key);
};


#endif
