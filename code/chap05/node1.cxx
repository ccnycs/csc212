// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5{
    std::size_t list_length(const node* head_ptr){};
    void list_head_insert(node*& head_ptr, const node::value_type& entry){
	    node* another = new node();
            another->data = 12.1;
            another->next = head_ptr; 
            head_ptr = another;
    }
    void list_insert(node* previous_ptr, const node::value_type& entry){};  
    node* list_search(node* head_ptr, const node::value_type& target){};
    const node* list_search
	(const node* head_ptr, const node::value_type& target){};
    node* list_locate(node* head_ptr, std::size_t position){};
    const node* list_locate(const node* head_ptr, std::size_t position){};
    void list_head_remove(node*& head_ptr){};
    void list_remove(node* previous_ptr){};
    void list_clear(node*& head_ptr){};
    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr){};
}
