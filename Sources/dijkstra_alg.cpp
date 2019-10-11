#include "graph.hpp"
#include "algorithm_utility.hpp"

#include <algorithm>  //std::min_element
#include <iostream>
#include <cassert>
#include <cstddef>
#include <utility>
#include <limits>
#include <list>
#include <map>

using weightType = double;

//Dijkstra's graph search algorithm that solves the shortest path problem
//for a directed graph with non-negative edge path costs.
//out_prev describe previous vertex for shortest path
void DijkstraAlg (const Graph& g, const Vertex* source, const Vertex* target,
		  const std::map< Edge*, weightType, std::less<void> >& weight,
		  std::map< const Vertex*, Edge*, std::less<void> > & out_prev)
{
	//declaring and initializing map of potentials and out_prev containers
	std::map< const Vertex*, weightType, std::less<void> > potential;
	weightType inf = std::numeric_limits<weightType>::infinity();
	//assignment of initial potential vnd out_prev alues to graph vertices.
	potential.insert( std::make_pair(source, 0.0) );
	out_prev[source] = nullptr;
	for(std::size_t i = 1; i < g.getVertexCount(); ++i) {
		potential[ g.getVertex(i) ] = inf;
		out_prev[ g.getVertex(i) ] = nullptr;
	}
	while (!potential.empty()){
		const Vertex *v = (*std::min_element(potential.begin(), potential.end(), Compare)).first;
		if (v == target) {
			return;
		}
		for(auto e : (v -> getOutEdges())){
			assert(weight.at(e) >= 0 && "Weights should not be negative");
			if(potential[e->getTarget()] > potential[e->getSource()] + weight.at(e)) {
			       potential[e->getTarget()] = potential[e->getSource()] + weight.at(e);
       			       out_prev[e->getTarget()] = e; 
			}
		}
		potential.erase(v);
	}
	return;
}

