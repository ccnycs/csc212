// FILE: graph.h (part of the namespace main_savitch_15)
// TEMPLATE CLASS PROVIDED: graph<Item> (a class for labeled graphs)
//   The vertices of an n-vertex graph are numbered from zero to n-1. Each vertex
//   has a label of type Item. It may be any of the C++ built-in types (int,
//   char, etc.), or any class with a default constructor and an assignment
//   operator. The graph may not have multiple edges.
//
// MEMBER CONSTANTS for the graph<Item> template class:
//   static const size_t MAXIMUM = ______
//     graph::MAXIMUM is the maximum number of vertices that a graph can have.
//
// CONSTRUCTOR for the graph<Item> template class:
//   graph( )   
//     Postcondition: The graph has been initialized with no vertices and no edges.
//
// MODIFICATION MEMBER FUNCTIONS for the graph<Item> template class:
//   void add_vertex(const Item& label)
//     Precondition: size( ) < MAXIMUM.
//     Postcondition: The size of the graph has been increased by adding one new
//     vertex. This new vertex has the specified label and no edges.
//
//   void add_edge(size_t source, size_t target)
//     Precondition: (source < size( )) and (target < size( )).
//     Postcondition: The graph has all the edges that it originally had, and it
//     also has another edge from the specified source to the specified target.
//     (If this edge was already present, then the graph is unchanged.)
//
//   void remove_edge(size_t soure, size_t target) 
//     Precondition: (source < size( )) and (target < size( )).
//     Postcondition: The graph has all the edges that it originally had except
//     for the edge from the specified source to the specified target. (If this
//     edge was not originally present, then the graph is unchanged.)
//
//   Item& operator [ ] (size_t vertex)  
//     Precondition: vertex < size( ).
//     Postcondition: The return value is a reference to the label of the
//     specified vertex.
//
// CONSTANT MEMBER FUNCTIONS for the graph<Item> template class:
//   size_t size( ) const
//     Postcondition: The return value is the number of vertices in the graph.
//
//   bool is_edge(size_t source, size_t target) const
//     Precondition: (source < size( )) and (target < size( )).
//     Postcondition: The return value is true if the graph has an edge from
//     source to target. Otherwise the return value is false.
//
//   set<size_t> neighbors(size_t vertex) const
//     Precondition: (vertex < size( )).
//     Postcondition: The return value is a set that contains all the vertex
//     numbers of vertices that are the target of an edge whose source is at
//     the specified vertex.
//
//   Item operator [ ] (size_t vertex) const
//     Precondition: vertex < size( ).
//     Postcondition: The return value is a reference to the label of the
//     specified vertex.
//     NOTE: This function differs from the other operator [ ] because its
//     return value is simply a copy of the Item (rather than a reference of
//     type Item&). Since this function returns only a copy of the Item, it is
//     a const member function.
//
// VALUE SEMANTICS for the graph<Item> template class: 
//    Assignments and the copy constructor may be used with graph<Item> objects.

#ifndef MAIN_SAVITCH_GRAPH_H
#define MAIN_SAVITCH_GRAPH_H
#include <cstdlib>  // Provides size_t
#include <set>      // Provides set

namespace main_savitch_15
{
    template <class Item>
    class graph
    {
    public:
        // MEMBER CONSTANTS
        static const std::size_t MAXIMUM = 20;
        // CONSTRUCTOR
        graph( ) { many_vertices = 0; }
        // MODIFICATION MEMBER FUNCTIONS
        void add_vertex(const Item& label);
        void add_edge(std::size_t source, std::size_t target);
        void remove_edge(std::size_t source, std::size_t target);
        Item& operator [ ] (std::size_t vertex);
        // CONSTANT MEMBER FUNCTIONS
        std::size_t size( ) const { return many_vertices; }
        bool is_edge(std::size_t source, std::size_t target) const;
        std::set<std::size_t> neighbors(std::size_t vertex) const;
        Item operator[ ] (std::size_t vertex) const;
    private:
        bool edges[MAXIMUM][MAXIMUM];
        Item labels[MAXIMUM];
        std::size_t many_vertices;
    };
}

#include "graph.template" // Include the implementation.
#endif
