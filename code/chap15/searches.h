// FILE: searches.h (part of namespace main_savitch_15)
// This file provides three template functions for searching graphs
// from the graph template class of graph.h
//
// template <class Process, class Item, class SizeType>
// void rec_dfs(Process f, graph<Item>& g, SizeType v, bool marked[])
//   Precondition: g is a labeled graph that is being traversed by a
//   depth-first search. For each vertex x, marked[x] is true if x has
//   already been visited by this search, otherwise marked[x] is false.
//   The vertex v is an unmakred vertex that the search has just arrived at.
//   Postcondition: the depth-first search of g has been continued
//   through vertex v and beyond to all the vertices that can be reached
//   from v via a path of unmarked vertices.  The function f has been
//   applied to the labe of each vertex visited by the search, and each
//   such vertex x has also been marked by setting marked[x] to true.
//
// template <class Process, class Item, class SizeType>
// void depth_first(Process f, graph<Item>& g, SizeType start)
//   Precondion: start is a vertex number of the labeled graph g.
//   Postcondition: A depth-first search of g has been executed,
//   starting at the start vertex.  The function f has been applied to the
//   label of each vertex visited by the search.
//
// template <class Process, class Item, class SizeType>
// void breadth_first(Process f, graph<Item>& g, SizeType start)
//   Precondition: start is a vertex number of the labeled graph g.
//   Postcondition: A breadth-first search of g has been executed,
//   starting at the start vertex. The function f has been applied to the
//   label of each vertex visited by the search.

#ifndef SEARCHES_H
#define SEARCHES_H
#include "graph.h"

namespace main_savitch_15
{
    template <class Process, class Item, class SizeType>
    void rec_dfs(Process f, graph<Item>& g, SizeType v, bool marked[]);
 
    template <class Process, class Item, class SizeType>
    void depth_first(Process f, graph<Item>& g, SizeType start);

    template <class Process, class Item, class SizeType>
    void breadth_first(Process f, graph<Item>& g, SizeType start);
}

#include "searches.template" // Include the implementation.
#endif
