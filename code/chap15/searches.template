// FILE: searches.template
// TEMPLATE FUNCTIONS IMPLEMENTED: rec_dfs, depth_first, and breadth_first.
// Please see searches.h for documentation of these functions.
// This file is included at the bottom of searches.h, and should not be
// separately compiled.

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <set>
#include "graph.h"

namespace main_savitch_15
{
    template <class Process, class Item, class SizeType>
    void rec_dfs(Process f, graph<Item>& g, SizeType v, bool marked[])
    // Precondition: g is a labeled graph that is being traversed by a
    // depth-first search. For each vertex x, marked[x] is true if x has
    // already been visited by this search, otherwise marked[x] is false.
    // The vertex v is an unmakred vertex that the search has just arrived at.
    // Postcondition: the depth-first search of g has been continued
    // through vertex v and beyond to all the vertices that can be reached
    // from v via a path of unmarked vertices.  The function f has been
    // applied to the labe of each vertex visited by the search, and each
    // such vertex x has also been marked by setting marked[x] to true.
    // Library facilities used: cstdlib, graph.h, set
    {
	std::set<std::size_t> connections = g.neighbors(v);
	std::set<std::size_t>::iterator it;
   
	marked[v] = true;  // Mark vertex v
	f(g[v]);           // Process the label of vertex v with the function f
    
	// Traverse all the neighbors, looking for unmarked vertices:
	for (it = connections.begin( ); it != connections.end( ); ++it)
	{
	    if (!marked[*it])
		rec_dfs(f, g, *it, marked);
	}
    }
    
    template <class Process, class Item, class SizeType>
    void depth_first(Process f, graph<Item>& g, SizeType start)
    // Precondion: start is a vertex number of the labeled graph g.
    // Postcondition: A depth-first search of g has been executed,
    // starting at the start vertex.  The function f has been applied to the
    // label of each vertex visited by the search.
    // Library facilities used: algorithm, cassert, graph.h
    {
	bool marked[g.MAXIMUM];

	assert(start < g.size( ));
	std::fill_n(marked, g.size( ), false);
	rec_dfs(f, g, start, marked);
    }

    template <class Process, class Item, class SizeType>
    void breadth_first(Process f, graph<Item>& g, SizeType start)
    // Precondition: start is a vertex number of the labeled graph g.
    // Postcondition: A breadth-first search of g has been executed,
    // starting at the start vertex. The function f has been applied to the
    // label of each vertex visited by the search.
    // Library facilities used: algorithm, cassert, cstdlib, graph.h, queue
    {
	bool marked[g.MAXIMUM];
	std::set<std::size_t> connections;
	std::set<std::size_t>::iterator it;
	std::queue<std::size_t> vertex_queue;       
	assert(start < g.size( ));
	std::fill_n(marked, g.size( ), false);
	marked[start] = true;
	f(g[start]);
	vertex_queue.push(start);
	do
	{
	    connections = g.neighbors(vertex_queue.front( ));
	    vertex_queue.pop( );
	    // Mark and process the unmarked neighbors,
	    // and place them in the queue.
	    for (it = connections.begin( ); it != connections.end( ); ++it)
	    {
		if (!marked[*it])
		{
		    marked[*it] = true;
		    f(g[*it]);
		    vertex_queue.push(*it);
		}
	    }
	}   
	while (!vertex_queue.empty( ));
    }
}
