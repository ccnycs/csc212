// FILE: bag2.cxx
// CLASS implemented: bag (see bag2.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. The actual items of the bag are stored in a partially filled array.
//      The array is a dynamic array, pointed to by the member variable data;
//   3. The size of the dynamic array is in the member variable capacity.

#include <algorithm>    // Provides copy function
#include <cassert>       // Provides assert function
#include "bag2.h"

// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, reserve, insert, operator += ,
//   operator +, and the assignment operator.

const bag::size_type bag::DEFAULT_CAPACITY;

bag::bag(size_type initial_capacity){
 //     Postcondition: The bag is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
}

bag::bag(const bag& source){
    
}

bag::~bag( ){
}

void bag::reserve(size_type new_capacity){
//     Postcondition: The bag's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bag). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
}

bag::size_type bag::erase(const value_type& target){
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
}

bool bag::erase_one(const value_type& target){
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
}

void bag::insert(const value_type& entry){   
//     Postcondition: A new copy of entry has been inserted into the bag.
}

void bag::operator +=(const bag& addend){
//     Postcondition: Each item in addend has been added to this bag. 
}

void bag::operator =(const bag& source){

}

bag::size_type bag::count(const value_type& target) const{
//     Postcondition: Return value is number of times target is in the bag
}

bag operator +(const bag& b1, const bag& b2){
//   bag operator +(const bag& b1, const bag& b2)
//   Postcondition: The bag returned is the union of b1 and b2.

}


