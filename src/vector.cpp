#include "vector.h"

#include <malloc.h>

template <class T>
vector<T>::vector() {
    begin = (T*) malloc(memory_size * sizeof(T));
}

template <class T>
vector<T>::~vector() {
    free(begin);
}

template <class T>
uint64_t vector<T>::size() const {
    return current_size;
}

template <class T>
void vector<T>::push_back(const T& x) {
    if(current_size >= memory_size)
            realloc_size(memory_size * (uint64_t) 2);
        
    *(begin+current_size) = x;
    current_size++;
}

template <class T>
T vector<T>::pop_back() {
    if(--current_size < memory_size / (uint64_t) 2)
        realloc_size(memory_size / (uint64_t) 2);
}

template <class T>
void vector<T>::realloc_size(uint64_t new_size) {
    T* new_memory = (T*) malloc(new_size*sizeof(T));
    
    for(uint64_t i=0; i<min(memory_size, new_size); i++){
        *(new_memory+i) = *(begin+i);
    }

    free(begin);

    begin = new_memory;
    memory_size = new_size;
}

template <class T>
const T vector<T>::operator[](const int &i) const {
    return *(begin+i);
}

template <class T>
T& vector<T>::operator[](const int &i) {
    return *(begin+i);
}
