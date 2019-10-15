# GRAPH LONGEST AND SHORTEST PATHS	

		folder: Headers/graph.hpp Source/graph.cpp
## Graph class(used SPARSE adjacency list graph presentation): 
		
		folder: Source/ford_alg.cpp
## Graph search Ford's algorithm that solves the longest path problem for a directed acyclic
## graph with real edge path costs. Breadth First search(BFS) is used here.

		folder: Source/dijkstra_alg.cpp
## Dijkstra's graph search algorithm that solves the shortest path problem for a directed acyclic
## graph with non-negative edge path costs.

		folder: Sources/algorith_utility.cpp
## Some auxiliary functions for algorithms
	Compare(...): "potential"'s elements comparison function object for std::min_element (used for map: potential)
	EdgeWeightMapping(...): Edge-weight mapping
	PathDecoder (...): The function returns a pair, the first element of which is the total weight of the shortest path,
	and the second element is a sequence of vertices of the path.

## Tests
		folder: Sources/test_graph.cpp
1. Test_Graph_Maker(...): Making graph by Graph class's member functions.
		folder: Source/test_Dijkstra_SP.cpp
2. Test_Dijkstra_SP_Alg(...): Testing DijkstraAlg(..), that searches the shortest path.
		folder: Source/test_Ford_LP.cpp 
3. Test_Ford_LP_Alg(...): Testing FordAlg(...), that searches the longest path.

## makefile
###      command make:
		Run make file for generate dependency(*.dep) and objects(*.o) units, and as a final result execution 
		file(main.out), which represent tests results.
###      command make debug:
		Make compilation and linking with "-g" flag.
###      command make profile:
		Make compilation and linking with "-pg" flag, which give as an oportunity to see proper time analysis
		for each project unit.
###      command make gcov:
		Make compilation and linking with "--coverage" flag, which give as an oportunity to see covearge analysis
		for each source unit. LCOV options are also demonstrated.



