#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cstddef>
#include <vector>
#include <list>


class Edge;

class Vertex
{
	private:
		std::size_t m_id;
		std::list<Edge*> m_incEdges;
		std::list<Edge*> m_outEdges;
	public:
		Vertex();
		Vertex(std::size_t);
		Vertex(std::size_t,
		       const std::list<Edge*>&,
		       const std::list<Edge*>&);
		void addIncEdge(Edge*);
		void addOutEdge(Edge*);
		std::list<Edge*>& getIncEdges();		
		const std::list<Edge*>& getIncEdges() const;
		std::list<Edge*>& getOutEdges();
		const std::list<Edge*>& getOutEdges() const;
		std::size_t getId() const;
		void setId(const std::size_t);
};

class Edge
{
	private:
		Vertex *m_source;
 		Vertex *m_target;
	public:
		Edge();
		Edge(Vertex*, Vertex*);
		Vertex* getSource() const;	
		Vertex* getTarget() const;
		void setSource(Vertex*);
		void setTarget(Vertex*);
		//bool operator< (const Edge&) const;
};

class Graph
{
	private:
		std::size_t m_n;
		std::vector<Vertex*> m_adjList;
	public:
		Graph();
		std::size_t getVertexCount() const;
		std::size_t addVertex(Vertex*);
		//getVertex mem-fun returns a m_adjList element whose index is entered as an argument 
		Vertex* getVertex(std::size_t);
		const Vertex* getVertex(std::size_t) const;
		//addEdge(size_t, size_t) mem-fun takes m_adjList element's inidex as arguments 
		void addEdge(std::size_t, std::size_t);
		void addEdge(Vertex*, Vertex*);
		Edge* getEdge(Vertex*, Vertex*);
		const Edge* getEdge(Vertex*, Vertex*) const;
		Edge* getEdge(std::size_t, std::size_t);
		const Edge* getEdge(std::size_t, std::size_t) const;
		friend std::vector<Edge*> getEdgeVector(const Graph&);
};


#endif
