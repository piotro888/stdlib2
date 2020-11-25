#include <assert.h>

#include "vector.h"

using namespace std2;

int main(){
    vector <int> v;

    v.push_back(1);
    
    assert(v.size() == 1);
    assert(v[0] == 1);
    
    v[0] = 2;
    
    assert(v[0] == 2);

    v.pop_back();
    assert(v.size() == 0);

    for(int i=0; i<100; i++){
        v.push_back(i);
    }
    
    for(int i=0; i<100; i++){
        assert(v[i] == i);
    }
}