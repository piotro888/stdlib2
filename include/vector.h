#ifndef VECTOR_H
#define VECTOR_H

#include "types.h"

template <class T>
class vector {
    public:
        vector();
        ~vector();

        uint64_t size() const;
        void push_back(const T& x);
        T pop_back();
        
        const T operator[](const int &i) const;
        T& operator[](const int &i);
        
    private:
        T memory_size = 1;
        T current_size = 0;
        T* begin;
        void realloc_size(uint64_t new_size);
};

#endif