#ifndef NODE_H
#define NODE_H
#pragma once
#include <cstdlib>   // Provides NULL and size_t
#include <iterator>  // Provides iterator and forward_iterator_tag

template <class Item>
class node
{
public:
    // TYPEDEF
    typedef Item value_type;
    // CONSTRUCTOR
    node(const Item& init_data=Item( ), node* init_link=NULL)
        { data_field = init_data; link_field = init_link; }
    // MODIFICATION MEMBER FUNCTIONS
    Item& data( ) { return data_field; }
    node* link( ) { return link_field; }
    void set_data(const Item& new_data) { data_field = new_data; }
    void set_link(node* new_link) { link_field = new_link; }
    // CONST MEMBER FUNCTIONS
    const Item& data( ) const { return data_field; }
    const node* link( ) const { return link_field; }
private:
    Item data_field;
    node *link_field;
};

// FUNCTIONS to manipulate a linked list:
template <class Item>
void list_clear(node<Item>*& head_ptr);

template <class Item>
void list_copy
    (const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);

template <class Item>
void list_head_insert(node<Item>*& head_ptr, const Item& entry); 

template <class Item>
void list_head_remove(node<Item>*& head_ptr);

template <class Item>
void list_insert(node<Item>* previous_ptr, const Item& entry);

template <class Item>
std::size_t list_length(const node<Item>* head_ptr);

template <class NodePtr, class SizeType>
NodePtr list_locate(NodePtr head_ptr, SizeType position);

template <class Item>
void list_remove(node<Item>* previous_ptr);

template <class NodePtr, class Item>
NodePtr list_search(NodePtr head_ptr, const Item& target);

// FORWARD ITERATORS to step through the nodes of a linked list
// A node_iterator of can change the underlying linked list through the
// * operator, so it may not be used with a const node. The
// node_const_iterator cannot change the underlying linked list
// through the * operator, so it may be used with a const node.
// WARNING:
// This classes use std::iterator as its base class;
// Older compilers that do not support the std::iterator class can
// delete everything after the word iterator in the second line:

template <class Item>
class node_iterator
: public std::iterator<std::forward_iterator_tag, Item>
{
public:
    node_iterator(node<Item>* initial = NULL)
    { current = initial; }
Item& operator *( ) const
    { return current->data( ); }
node_iterator& operator ++( ) // Prefix ++
    { 
    current = current->link( );
    return *this;
    }
node_iterator operator ++(int) // Postfix ++
    {
    node_iterator original(current);
    current = current->link( );
    return original;      	  
    }
bool operator ==(const node_iterator other) const
    { return current == other.current; }
bool operator !=(const node_iterator other) const
    { return current != other.current; }
private:
node<Item>* current;
};

template <class Item>
class const_node_iterator
: public std::iterator<std::forward_iterator_tag, const Item>
{
public:
    const_node_iterator(const node<Item>* initial = NULL)
    { current = initial; }
const Item& operator *( ) const
    { return current->data( ); }
const_node_iterator& operator ++( ) // Prefix ++
    {
    current = current->link( );
    return *this;
    }
const_node_iterator operator ++(int) // Postfix ++
    {
    const_node_iterator original(current);
    current = current->link( );
    return original;
    }
bool operator ==(const const_node_iterator other) const
    { return current == other.current; }
bool operator !=(const const_node_iterator other) const
    { return current != other.current; }
private:
const node<Item>* current;
};    template <class Item>
    void list_clear(node<Item>*& head_ptr)
    // Library facilities used: cstdlib
    {
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
    }

    template <class Item>
    void list_copy(
	const node<Item>* source_ptr,
	node<Item>*& head_ptr,
	node<Item>*& tail_ptr
	) 
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list
	if (source_ptr == NULL)
	    return;	

	// Make the head node for the newly created list, and put data in it
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr; 
	
	// Copy rest of the nodes one at a time, adding at the tail of new list
	source_ptr = source_ptr->link( ); 
        while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
    }
    
    template <class Item>
    void list_head_insert(node<Item>*& head_ptr, const Item& entry)
    {
	head_ptr = new node<Item>(entry, head_ptr);
    }

    template <class Item>
    void list_head_remove(node<Item>*& head_ptr)
    {
	node<Item> *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
    }

    template <class Item>
    void list_insert(node<Item>* previous_ptr, const Item& entry) 
    {
	node<Item> *insert_ptr;
    
	insert_ptr = new node<Item>(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
    }

    template <class Item>
    std::size_t list_length(const node<Item>* head_ptr)
    // Library facilities used: cstdlib
    {
	const node<Item> *cursor;
	std::size_t answer;
	
	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;
	
	return answer;
    }

    template <class NodePtr, class SizeType>
    NodePtr list_locate(NodePtr head_ptr, SizeType position) 
    // Library facilities used: cassert, cstdlib
    {
	NodePtr cursor;
	SizeType i;
    
	assert(0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); ++i)
	    cursor = cursor->link( );
	return cursor;
    }

    template <class Item>
    void list_remove(node<Item>* previous_ptr)
    {
	node<Item> *remove_ptr;

	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link(remove_ptr->link( ));
	delete remove_ptr;
    }

    template <class NodePtr, class Item>
    NodePtr list_search(NodePtr head_ptr, const Item& target) 
    // Library facilities used: cstdlib
    {
	NodePtr cursor;
	
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }
#endif