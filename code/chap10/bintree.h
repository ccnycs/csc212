// FILE: bintree.h (part of the namespace main_savitch_10)
// PROVIDES: A template class for a node in a binary tree and functions for 
// manipulating binary trees. The template parameter is the type of data in
// each node.
// 
// TYPEDEF for the binary_tree_node<Item> template class:
//   Each node of the tree contains a piece of data and pointers to its
//   children. The type of the data (binary_tree_node<Item>::value_type) is
//   the Item type from the template parameter. The type may be any of the C++
//   built-in types (int, char, etc.), or a class with a default constructor,
//   and an assignment operator.
//
// CONSTRUCTOR for the binary_tree_node<Item> class:
//   binary_tree_node(
//       const item& init_data = Item( ),
//       binary_tree_node<Item>* init_left = NULL,
//       binary_tree_node<Item>* init_right = NULL
//   )
//     Postcondition: The new node has its data equal to init_data,
//     and it's child pointers equal to init_left and init_right.
//
// MEMBER FUNCTIONS for the binary_tree_node<Item> class:
//   const item& data( ) const      <----- const version
//   and
//   Item& data( )                  <----- non-const version
//     Postcondition: The return value is a reference to the data from
//     this binary_tree_node.
//
//   const binary_tree_node* left( ) const  <----- const version
//   and
//   binary_tree_node* left( )              <----- non-const version
//   and
//   const binary_tree_node* right( ) const <----- const version
//   and
//   binary_tree_node* right( )             <----- non-const version
//     Postcondition: The return value is a pointer to the left or right child
//     (which will be NULL if there is no child).
//
//   void set_data(const Item& new_data)
//     Postcondition: The binary_tree_node now contains the specified new data.
//
//   void set_left(binary_tree_node* new_link)
//   and
//   void set_right(binary_tree_node* new_link)
//     Postcondition: The binary_tree_node now contains the specified new link
//     to a child.
//
//   bool is_leaf( )
//     Postcondition: The return value is true if the node is a leaf;
//     otherwise the return value is false.
//
// NON-MEMBER FUNCTIONS to maniplulate binary tree nodes:
//   tempate <class Process, class BTNode>
//   void inorder(Process f, BTNode* node_ptr)
//     Precondition: node_ptr is a pointer to a node in a binary tree (or
//     node_ptr may be NULL to indicate the empty tree).
//     Postcondition: If node_ptr is non-NULL, then the function f has been
//     applied to the contents of *node_ptr and all of its descendants, using
//     an in-order traversal.
//     Note: BTNode may be a binary_tree_node or a const binary tree node.
//     Process is the type of a function f that may be called with a single
//     Item argument (using the Item type from the node).
//
//   tempate <class Process, class BTNode>
//   void postorder(Process f, BTNode* node_ptr)
//      Same as the in-order function, except with a post-order traversal.
//
//   tempate <class Process, class BTNode>
//   void preorder(Process f, BTNode* node_ptr)
//      Same as the in-order function, except with a pre-order traversal.
//
//   template <class Item, class SizeType>
//   void print(const binary_tree_node<Item>* node_ptr, SizeType depth)
//     Precondition: node_ptr is a pointer to a node in a binary tree (or
//     node_ptr may be NULL to indicate the empty tree). If the pointer is
//     not NULL, then depth is the depth of the node pointed to by node_ptr.
//     Postcondition: If node_ptr is non-NULL, then the contents of *node_ptr
//     and all its descendants have been written to cout with the << operator,
//     using a backward in-order traversal. Each node is indented four times
//     its depth.
//
//   template <class Item>
//   void tree_clear(binary_tree_node<Item>*& root_ptr)
//     Precondition: root_ptr is the root pointer of a binary tree (which may
//     be NULL for the empty tree).
//     Postcondition: All nodes at the root or below have been returned to the
//     heap, and root_ptr has been set to NULL.
//
//   template <class Item>
//   binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr)
//     Precondition: root_ptr is the root pointer of a binary tree (which may
//     be NULL for the empty tree).
//     Postcondition: A copy of the binary tree has been made, and the return
//     value is a pointer to the root of this copy.
//
//   template <class Item>
//   size_t tree_size(const binary_tree_node<Item>* node_ptr)
//     Precondition: node_ptr is a pointer to a node in a binary tree (or
//     node_ptr may be NULL to indicate the empty tree).
//     Postcondition: The return value is the number of nodes in the tree.

#ifndef BINTREE_H
#define BINTREE_H
#include <cstdlib>  // Provides NULL and size_t

namespace main_savitch_10
{

    template <class Item>
    class binary_tree_node
    {
    public:
	// TYPEDEF
	typedef Item value_type;
	// CONSTRUCTOR
	binary_tree_node(
	    const Item& init_data = Item( ),
	    binary_tree_node* init_left = NULL,
	    binary_tree_node* init_right = NULL
	)
	{ 
      	    data_field = init_data; 
	    left_field = init_left; 
	    right_field = init_right;
	}
	// MODIFICATION MEMBER FUNCTIONS
	Item& data( ) { return data_field; }
	binary_tree_node* left( ) { return left_field; }
	binary_tree_node* right( ) { return right_field; }
	void set_data(const Item& new_data) { data_field = new_data; }
	void set_left(binary_tree_node* new_left) { left_field = new_left; }
	void set_right(binary_tree_node* new_right) { right_field = new_right; }
	// CONST MEMBER FUNCTIONS
	const Item& data( ) const { return data_field; }
	const binary_tree_node* left( ) const { return left_field; }
	const binary_tree_node* right( ) const { return right_field; }
	bool is_leaf( ) const 
	    { return (left_field == NULL) && (right_field == NULL); }
    private:
	Item data_field;
	binary_tree_node *left_field;
	binary_tree_node *right_field;
    };

        // NON-MEMBER FUNCTIONS for the binary_tree_node<Item>:
    template <class Process, class BTNode>
    void inorder(Process f, BTNode* node_ptr); 

    template <class Process, class BTNode>
    void preorder(Process f, BTNode* node_ptr);

    template <class Process, class BTNode>
    void postorder(Process f, BTNode* node_ptr); 

    template <class Item, class SizeType>
    void print(binary_tree_node<Item>* node_ptr, SizeType depth);

    template <class Item>
    void tree_clear(binary_tree_node<Item>*& root_ptr);

    template <class Item>
    binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr);

    template <class Item>
    std::size_t tree_size(const binary_tree_node<Item>* node_ptr);
}

#include "bintree.template"
#endif
