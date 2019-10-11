#ifndef ALGORITHM_UTILITY_HPP
#define ALGORITHM_UTILITY_HPP


#include "graph.hpp"

#include <map>
#include <list>
#include <vector>

using weightType = double;

//"potential"'s elements comparison function object for std::min_element (used for map: potential)
bool Compare ( const std::pair<const Vertex*, weightType>&,
	       const std::pair<const Vertex*, weightType>& );

//Edge-weight mapping
void EdgeWeightMapping (const std::vector<Edge*>& e, const std::vector<weightType>& w,
			std::map< Edge*, weightType, std::less<void> >& out_weigh);

//The function returns a pair, the first element of which is the total weight
//of the shortest path, and the second element is a sequence of vertices of the path.
std::pair< weightType, std::list<const Vertex*> > PathDecoder (
		const Vertex* source, const Vertex* target,
    		const std::map< Edge*, weightType, std::less<void> >& weight,
    		std::map< const Vertex*, Edge*, std::less<void> > & prev); 

void PrintPath(const std::pair< weightType, std::list<const Vertex*> >& p);


#endif
