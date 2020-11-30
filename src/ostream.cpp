#include "ostream.h"

ostream& ostream::operator << (int8_t x) {
    if(x < 0)   x = -x, fputc('-', out);
    fputc(x, out);
    return *this;
}

ostream& ostream::operator << (int16_t x) {
    if(x < 0)   x = -x, fputc('-', out);
    int8_t buf[5], i = 5;
    do buf[--i] = (x % 10) + 48, x /= 10; while(x);
    do fputc(buf[i], out); while(++i < 5);
    return *this;
}

ostream& ostream::operator << (int32_t x) {
    if(x < 0)   x = -x, fputc('-', out);
    int8_t buf[10], i = 10;
    do buf[--i] = (x % 10) + 48, x /= 10; while(x);
    do fputc(buf[i], out); while(++i < 10);
    return *this;
}

ostream& ostream::operator << (int64_t x) {
    if(x < 0)   x = -x, fputc('-', out);
    int8_t buf[20], i = 20;
    do buf[--i] = (x % 10) + 48, x /= 10; while(x);
    do fputc(buf[i], out); while(++i < 20);
    return *this;
}

ostream& ostream::operator << (uint8_t x) {
    fputc(x, out);
    return *this;
}

ostream& ostream::operator << (uint16_t x) {
    int8_t buf[5], i = 5;
    do buf[--i] = (x % 10) + 48, x /= 10; while(x);
    do fputc(buf[i], out); while(++i < 5);
    return *this;
}

ostream& ostream::operator << (uint32_t x) {
    int8_t buf[10], i = 10;
    do buf[--i] = (x % 10) + 48, x /= 10; while(x);
    do fputc(buf[i], out); while(++i < 10);
    return *this;
}

ostream& ostream::operator << (uint64_t x) {
    int8_t buf[20], i = 20;
    do buf[--i] = (x % 10) + 48, x /= 10; while(x);
    do fputc(buf[i], out); while(++i < 20);
    return *this;
}

ostream& ostream::operator << (double x) {
    if(x < 0)   x = -x, fputc('-', out);
    return *this;
}

ostream& ostream::operator << (long double x) {
    if(x < 0)   x = -x, fputc('-', out);
    return *this;
}

void ostream::set_precision(int64_t new_precision) {
    
}
