#ifndef VECTOR_H
#define VECTOR_H

#include "types.h"

namespace std2 {
    template <class T>
    class vector {
        public:
            vector();
            ~vector();

            uint64_t size() const;
            void push_back(const T& x);
            void pop_back();
            
            const T operator[](const int &i) const;
            T& operator[](const int &i);
            
        private:
            uint64_t memory_size = 1;
            uint64_t current_size = 0;
            T* begin;
            void realloc_size(uint64_t new_size);

            uint64_t min(uint64_t a, uint64_t b) const; //temporary, to be replaced with math.h
    };
}

#include "vector.tcc" // implementation

#endif