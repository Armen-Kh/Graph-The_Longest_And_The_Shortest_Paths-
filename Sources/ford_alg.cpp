#include "graph.hpp"
#include "algorithm_utility.hpp"

#include <algorithm>  //std::min_element
#include <iostream>
#include <cassert>
#include <cstddef>
#include <utility>
#include <limits>
#include <queue>
#include <list>
#include <map>

using weightType = double;

//Graph search Ford's algorithm that solves the longest path problem
//for a directed acyclic graph with real edge path costs.
//Breadth First search(BFS) is used here.
//out_prev describe previous vertex for shortest path
void FordAlg (const Graph& g, const Vertex* source, const Vertex* target,
		  const std::map< Edge*, weightType, std::less<void> >& weight,
		  std::map< const Vertex*, Edge*, std::less<void> > & out_prev) 
{
	//declaring and initializing map of potentials and out_prev containers
	std::map< const Vertex*, weightType, std::less<void> > potential;
	weightType lv = std::numeric_limits<weightType>::lowest();
	//assignment of initial potential vnd out_prev alues to graph vertices.
	potential.insert( std::make_pair(source, 0.0) );
	out_prev[source] = nullptr;
	for(std::size_t i = 1; i < g.getVertexCount(); ++i) {
		potential[ g.getVertex(i) ] = lv;
		out_prev[ g.getVertex(i) ] = nullptr;
	}
	std::queue<const Vertex*> q;
	q.push(source);
	while( !q.empty() ) {
		for( auto e : q.front()->getOutEdges() ){
			if( potential[e->getTarget()] < potential[q.front()] + weight.at(e) ) {
				potential[e->getTarget()] = potential[q.front()] + weight.at(e);
				out_prev[e->getTarget()] = e;
				q.push( e->getTarget() );
			}	
		}
		q.pop();	
	}

	//****************************************************
	for(auto e : out_prev)


	//**************************************************
	return;
}

