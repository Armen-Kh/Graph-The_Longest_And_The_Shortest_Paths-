#ifndef DIJKSTRA_ALG_HPP
#define DIJKSTRA_ALG_HPP


#include "graph.hpp"

#include <map>
#include <list>

using weightType = double;

//Dijkstra's graph search algorithm that solves the shortest path problem
//for a graph with non-negative edge path costs.
void DijkstraAlg (const Graph& g, const Vertex* source, const Vertex* target,
		  const std::map< Edge*, weightType, std::less<void> >& weight,
		  std::map< const Vertex*, Edge*, std::less<void> > & out_prev); 


#endif
