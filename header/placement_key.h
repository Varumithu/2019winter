#ifndef PLACEMENT_KEY_DOTH
#define PLACEMENT_KEY_DOTH

#include "key_processor.h"

class placement_key final : public key_processor {
public:
    placement_key() = default;
    ~placement_key() = default;
    int process_key(int key);
};

#endif
