#ifndef BAG5_H
#define BAG5_H
#include <cstdlib>   // Provides NULL and size_t and NULL
#include "node2.h"   // Provides node class


    template <class Item>
    class bag
    {
    public:
        // TYPEDEFS
	typedef std::size_t size_type;
        typedef Item value_type;
	typedef node_iterator<Item> iterator;
	typedef const_node_iterator<Item> const_iterator;
	
        // CONSTRUCTORS and DESTRUCTOR
        bag( );
        bag(const bag& source);
        ~bag( );
	
        // MODIFICATION MEMBER FUNCTIONS
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator +=(const bag& addend);
        void operator =(const bag& source);
	
        // CONST MEMBER FUNCTIONS
        size_type count(const Item& target) const;
        Item grab( ) const;
        size_type size( ) const { return many_nodes; }
	
	// FUNCTIONS TO PROVIDE ITERATORS
	iterator begin( )
	    { return iterator(head_ptr); }
	const_iterator begin( ) const
	    { return const_iterator(head_ptr); }
	iterator end( )
	    { return iterator( ); } // Uses default constructor 
	const_iterator end( ) const
	    { return const_iterator( ); } // Uses default constructor 

    private:
        node<Item> *head_ptr;        // Head pointer for the list of items
        size_type many_nodes;        // Number of nodes on the list
    };

    // NONMEMBER functions for the bag
    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2);
}

// The implementation of a template class must be included in its header file:
#include "bag5.template"
#endif

