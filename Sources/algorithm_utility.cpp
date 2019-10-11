#include "graph.hpp"

#include <algorithm>  //std::min_element
#include <iostream>
#include <cassert>
#include <cstddef>
#include <utility>
#include <vector>
#include <limits>
#include <list>
#include <map>

using weightType = double;

//"potential"'s elements comparison function object for std::min_element (used for map: potential)
bool Compare ( const std::pair<const Vertex*, weightType>& p1,
	       const std::pair<const Vertex*, weightType>& p2 )
{
	return p1.second < p2.second;
}


//Edge-weight mapping
void EdgeWeightMapping (const std::vector<Edge*>& e, const std::vector<weightType>& w,
			std::map< Edge*, weightType, std::less<void> >& out_weight)
{
	assert(e.size() == w.size() && "size incompatibility");
	for(std::size_t i = 0; i < e.size(); ++i) {
		out_weight[e[i]] = w[i];
	}
}


//The function returns a pair, the first element of which is the total weight
//of the shortest path, and the second element is a sequence of vertices of the path.
std::pair< weightType, std::list<const Vertex*> > PathDecoder (
		const Vertex* source, const Vertex* target,
    		const std::map< Edge*, weightType, std::less<void> >& weight,
    		std::map< const Vertex*, Edge*, std::less<void> > & prev) 
{
	std::list<const Vertex*> shortestPath;
	weightType pathSumWeight = 0;

	const Vertex *t = target;
	while (t != source)
	{
		if(prev[t] -> getSource() == nullptr) {
			std::cout << "There is no any path!" << std::endl;
			return std::make_pair(pathSumWeight, shortestPath);
		}
		shortestPath.push_front(t);
		pathSumWeight += weight.at(prev[t]);
		t = prev[t] -> getSource();
	}
	shortestPath.push_front(source);
	return std::make_pair(pathSumWeight, shortestPath);
}


void PrintPath(const std::pair< weightType, std::list<const Vertex*> >& p)
{
	if( p.second.empty() ) {
		std::cout << "There is no path!" << std::endl;
		return;
	}
	std::cout << "From " << (*(p.second.begin())) -> getId() << " to " << (*(--p.second.end())) -> getId();
	std::cout << " path weight(distance) = " << p.first << ", Sequence of vertices: ";
	for(auto e : p.second) {
		if(e == *(--p.second.end())) {  //just for prevent printing of an extra "->"
			std::cout << e -> getId() << std::endl;
		}else {
			std::cout << e -> getId() << "->";
		}
	}
}
