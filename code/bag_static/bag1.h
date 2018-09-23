// FILE: bag1.h
// CLASS PROVIDED: bag (part of the namespace main_savitch_3)
#ifndef BAG_H
#define BAG_H
#pragma once

#include <cstdlib>  // Provides size_t

class bag
{ 
public:
    // TYPEDEFS and MEMBER CONSTANTS
    typedef int value_type;
    typedef std::size_t size_type;
    static const size_type CAPACITY = 30;
    // CONSTRUCTOR
    bag( ) { used = 0; } 
    // MODIFICATION MEMBER FUNCTIONS
    size_type erase(const value_type& target);
    bool erase_one(const value_type& target);
    void insert(const value_type& entry);
    void operator +=(const bag& addend);
    // CONSTANT MEMBER FUNCTIONS
    size_type size( ) const { return used; }
    size_type count(const value_type& target) const;
private:
    value_type data[CAPACITY];  // The array to store items
    size_type used;             // How much of array is used
};

// NONMEMBER FUNCTIONS for the bag class
bag operator +(const bag& b1, const bag& b2);

#endif
