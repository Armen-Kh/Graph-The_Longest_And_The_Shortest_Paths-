#ifndef FORD_ALG_HPP
#define FORD_ALG_HPP


#include "graph.hpp"

#include <map>
#include <list>

using weightType = double;

//Graph search Ford's algorithm that solves the longest path problem
//for a DAG with real edge path costs.
void FordAlg (const Graph& g, const Vertex* source, const Vertex* target,
		  const std::map< Edge*, weightType, std::less<void> >& weight,
		  std::map< const Vertex*, Edge*, std::less<void> > & out_prev); 


#endif
