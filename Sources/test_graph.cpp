#include "graph.hpp"

#include <iostream>

bool Test_Graph_Maker(Graph& g)
{
	bool b1 = g.getVertexCount() == 0;
	for(std::size_t i = 0; i < 7 ; ++i) {
		g.addVertex(new Vertex(Vertex(i)));
	}
	bool b2 = g.getVertexCount() == 7;
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(0, 5);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(g.getVertex(2), g.getVertex(6));
	g.addEdge(g.getVertex(4), g.getVertex(2));
	g.addEdge(g.getVertex(4), g.getVertex(6));
	g.addEdge(g.getVertex(5), g.getVertex(4));
	g.addEdge(g.getVertex(5), g.getVertex(6));
	g.addEdge(g.getVertex(6), g.getVertex(3));
	bool b3 = (g.getVertex(0) -> getOutEdges()).size() == 3;
	bool b4 = (g.getVertex(0) -> getIncEdges()).size() == 0;
	bool b5 = (g.getVertex(3) -> getIncEdges()).size() == 2;
	bool b6 = (g.getEdge(2, 3) -> getSource()) -> getId() == 2;
	bool b7 = (g.getEdge(2, 3) -> getTarget()) -> getId() == 3;
	bool b8 = ( (g.getEdge(g.getVertex(6), g.getVertex(3)))-> getSource() ) -> getId() == 6;
	return b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8;
}

