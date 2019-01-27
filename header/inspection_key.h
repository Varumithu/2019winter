#include "key_processor.h"


class inspection_key final : public key_processor {
public:
    inspection_key() = default;
    ~inspection_key() = default;

    int process_key(int key);
};
