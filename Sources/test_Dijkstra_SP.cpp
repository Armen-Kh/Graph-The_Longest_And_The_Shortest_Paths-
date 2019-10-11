#include "graph.hpp"
#include "dijkstra_alg.hpp"
#include "algorithm_utility.hpp"

#include <iostream>
#include <utility>
#include <list>
#include <map>

bool Test_Dijkstra_SP_Alg(const Graph& g)
{
	std::vector<Edge*> e = getEdgeVector(g);
	std::vector<weightType> w {1.5, 4, 1, 4.5, 0.5, 0.5, 2, 3.5, 6, 2.5, 7, 3};
	std::map< Edge*, weightType, std::less<void> > weight;
	EdgeWeightMapping(e, w, weight);

	std::map< const Vertex*, Edge*, std::less<void> > prev;
	std::pair< weightType, std::list<const Vertex*> > result;

	DijkstraAlg(g, g.getVertex(0), g.getVertex(6), weight, prev);
	result = PathDecoder(g.getVertex(0), g.getVertex(6), weight, prev);
	PrintPath(result);
	bool b1 = (result.first == 7.5);
	
	prev.clear();
	DijkstraAlg(g, g.getVertex(0), g.getVertex(4), weight, prev);
	result = PathDecoder(g.getVertex(0), g.getVertex(4), weight, prev);
	PrintPath(result);
	bool b2 = (result.first == 2);

	prev.clear();
	DijkstraAlg(g, g.getVertex(0), g.getVertex(3), weight, prev);
	result = PathDecoder(g.getVertex(0), g.getVertex(3), weight, prev);
	PrintPath(result);
	bool b3 = (result.first == 6);

	return b1 && b2 && b3;
}

