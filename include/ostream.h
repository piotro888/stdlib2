#ifndef OSTREAM_H
#define OSTREAM_H

#include <cstdio>

#include "types.h"

class ostream {
public:
    ostream(FILE *_out) : out(_out) { }

    ostream& operator << (int8_t);
    ostream& operator << (int16_t);
    ostream& operator << (int32_t);
    ostream& operator << (int64_t);

    ostream& operator << (uint8_t);
    ostream& operator << (uint16_t);
    ostream& operator << (uint32_t);
    ostream& operator << (uint64_t);

    ostream& operator << (double);
    ostream& operator << (long double);

    void set_precision(int64_t);

private:
    FILE *out;
    int64_t precision;
};

#endif // OSTREAM_H
