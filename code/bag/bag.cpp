#include "bag.h"

//let's add to our bag
void bag::insert(const value_type& entry){
    if (size()>=CAPACITY){
        throw std::runtime_error(std::string("Bag is full"));
    }
    data[used] = entry;
    ++used;
}