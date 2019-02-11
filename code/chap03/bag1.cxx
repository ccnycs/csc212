// FILE: bag1.cxx
// CLASS IMPLEMENTED: bag (see bag1.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "bag1.h"
using namespace std;

namespace main_savitch_3
{
    const bag::size_type bag::CAPACITY;
    
    bag::size_type bag::erase(const value_type& target)
    {
	size_type index = 0;
	size_type many_removed = 0;

	while (index < used)
	{
	    if (data[index] == target)
	    {
		--used;
		data[index] = data[used];
		++many_removed;
	    }
	    else
		++index;
	}

	return many_removed;
    }

    bool bag::erase_one(const value_type& target)
    {
	size_type index; // The location of target in the data array    

	// First, set index to the location of target in the data array,
	// which could be as small as 0 or as large as used-1. If target is not
	// in the array, then index will be set equal to used.
	index = 0; 
	while ((index < used) && (data[index] != target))
	    ++index;

	if (index == used)
	    return false; // target isn’t in the bag, so no work to do.

	// When execution reaches here, target is in the bag at data[index].
	// So, reduce used by 1 and copy the last item onto data[index].
	--used;
	data[index] = data[used];    
	return true;
    }

    void bag::insert(const value_type& entry)
    // Library facilities used: cassert
    {   
        assert(size( ) < CAPACITY);

        data[used] = entry;
	++used;
    }

    void bag::operator +=(const bag& addend)
    // Library facilities used: algorithm, cassert
    {
	assert(size( ) + addend.size( ) <= CAPACITY);
	
	copy(addend.data, addend.data + addend.used, data + used);
	used += addend.used;
    }

    bag::size_type bag::count(const value_type& target) const
    {
        size_type answer;
        size_type i;

        answer = 0;
        for (i = 0; i < used; ++i)
            if (target == data[i])
                ++answer;
        return answer;
    }

    bag operator +(const bag& b1, const bag& b2)
    // Library facilities used: cassert
    {
        bag answer;

        assert(b1.size( ) + b2.size( ) <= bag::CAPACITY);

        answer += b1; 
        answer += b2;
        return answer;
    }
}
