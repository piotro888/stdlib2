#ifndef ISTREAM_H
#define ISTREAM_H

#include <cstdio>

#include "types.h"

class istream {
public:
    istream(FILE *_in) : in(_in) { }

    inline char get_char();
    istream& operator >> (int8_t &x);
    istream& operator >> (int16_t &x);
    istream& operator >> (int32_t &x);
    istream& operator >> (int64_t &x);

    istream& operator >> (uint8_t &x);
    istream& operator >> (uint16_t &x);
    istream& operator >> (uint32_t &x);
    istream& operator >> (uint64_t &x);
private:
    static const int S = 65536;
    int8_t buf[S];
    int32_t pos = 0, len = 0;
    bool eof = false;
    FILE *in;
};

#endif // ISTREAM_H
