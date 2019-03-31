// FILE: node1.cxx
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
std::size_t list_length(const node* head_ptr)
{
    size_t cnt = 0;
    for(const node* cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
    {
        cnt++;
    }
    return cnt;
};

void list_head_insert(node*& head_ptr, const node::value_type& entry)
{
    node* temp = new node;
    temp->set_data(entry);
    temp->set_link(head_ptr);
    head_ptr = temp;
};

void list_insert(node* previous_ptr, const node::value_type& entry)
{
    node* temp = new node;
    temp->set_data(entry);
    temp->set_link(previous_ptr->link());
    previous_ptr->set_link(temp);
};

node* list_search(node* head_ptr, const node::value_type& target)
{
    node* cursor = new node;
    cursor = head_ptr;

    while(cursor!=NULL)
    {
        if(cursor->data() == target)
        {
            return cursor;
        }
        cursor = cursor->link();
    }
    return NULL;
};

const node* list_search
(const node* head_ptr, const node::value_type& target)
{

    const node* cursor = new node;
    cursor = head_ptr;

    while(cursor!=NULL)
    {
        if(cursor->data() == target)
        {
            return cursor;
        }
        cursor = cursor->link();
    }
    return NULL;
};


node* list_locate(node* head_ptr, std::size_t position)
{
    node* temp = new node;
    temp = head_ptr;
    size_t index = 1;

    while(index!=position && temp!=NULL)
    {
        temp = temp->link();
        index++;
    }

    return temp;
};

const node* list_locate(const node* head_ptr, std::size_t position)
{
    const node* temp = new node;
    temp = head_ptr;
    size_t index = 1;

    while(index!=position)
    {
        temp = temp->link();
        index++;
    }

    return temp;
};

void list_head_remove(node*& head_ptr)
{
    node* temp = head_ptr;
    head_ptr->set_link(head_ptr->link());
    delete temp;

};

void list_remove(node* previous_ptr)
{
    node* temp = previous_ptr->link();
    previous_ptr->set_link(temp->link());
    delete temp;
};

void list_clear(node*& head_ptr)
{
    while(head_ptr != NULL)
    {
        list_head_remove(head_ptr);
    }
};

void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
{
    head_ptr = NULL;
    tail_ptr = NULL;
    if(source_ptr == NULL)
    {
        return;
    }

    list_head_insert(head_ptr, source_ptr->data());
    tail_ptr = head_ptr;

    source_ptr = source_ptr->link();
    while(source_ptr != NULL)
    {
        list_insert(tail_ptr, source_ptr->data());
        source_ptr = source_ptr->link();
        tail_ptr = tail_ptr->link();
    }
};
}
