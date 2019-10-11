#include "graph.hpp"
#include "test_graph.hpp"
#include "test_Dijkstra_SP.hpp"
#include "test_Ford_LP.hpp"

#include <iostream>

int main()
{
	Graph g;
	if(Test_Graph_Maker(g)) {
		std::cout << "_________________________________Test for Graph class PASSED SUCCEESSFULLY!\n" << std::endl;
	} else {
		std::cout << "_______________________________________________Test for Graph class FAILED!\n" << std::endl;
	}

	if(Test_Dijkstra_SP_Alg(g)) {
		std::cout << "_______________________Test for Dijkstra SP algorithm PASSED SUCCEESSFULLY!\n" << std::endl;
	} else {
		std::cout << "_____________________________________Test for Dijkstra SP algorithm FAILED!\n" << std::endl;
	}

	if(Test_Ford_LP_Alg(g)) {
		std::cout << "__________________________Test for Ford LP algorithm PASSEED SUCCEESSFULLY!\n" << std::endl;
	} else {
		std::cout << "_________________________________________Test for Ford LP algorithm FAILED!\n" << std::endl;
	}

	return 0;
}
