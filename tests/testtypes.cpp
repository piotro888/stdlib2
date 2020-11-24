#include <assert.h>

#include "types.h"

int main(){ //example test, may be deleted
    assert(sizeof(uint64_t) == 8);
    assert(sizeof(uint32_t) == 4);
    assert(sizeof(uint16_t) == 2);
    assert(sizeof(uint8_t) == 1);

    assert(sizeof(int64_t) == 8);
    assert(sizeof(int32_t) == 4);
    assert(sizeof(int16_t) == 2);
    assert(sizeof(int8_t) == 1);
}