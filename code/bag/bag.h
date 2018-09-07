#ifndef BAG_H
#define BAG_H

#include <cstdlib> //provides size_t
#include <stdexcept> //provides runtime errors
#include <string>

class bag{
        public:
        //typedefs and member constants
        typedef int value_type;
        typedef size_t size_type;
        static const size_type CAPACITY = 30;
        //constructor
        bag(){used=0;}
        //modifying methods (changes the bag)
        size_type erase(const value_type& target); //return count erased targets
        bool erase_one(const value_type& target); //return true if target in bag
        void insert(const value_type& target);
        void operator +=(const value_type& entry);
        //const methods (doesn't change the bag)
        size_type size() const {return used; }
        size_type count(const value_type& target) const;
    private:
        value_type data[CAPACITY];
        size_type used;
    };
// acts on bags but doesn't need access to private attributes
bag operator +(const bag& b1, const bag& b2);
#endif
