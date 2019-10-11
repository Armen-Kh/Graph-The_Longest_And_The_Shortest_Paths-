#include "graph.hpp"

#include <cassert>
#include <cstddef>
#include <vector>
#include <list>


//***************class Vertex
Vertex::Vertex()
{
}

Vertex::Vertex(std::size_t id) : m_id(id)
{
}

Vertex::Vertex(std::size_t id, const std::list<Edge*>& incEdges,
			       const std::list<Edge*>& outEdges)
	: m_id(id)
        , m_incEdges(incEdges)	
        , m_outEdges(outEdges)	
{
}

void Vertex::addIncEdge(Edge* e)
{
	assert((e -> getTarget()) -> getId() == m_id && "Not compatible!");
	m_incEdges.push_back(e);
}

void Vertex::addOutEdge(Edge* e)
{
	assert((e -> getSource()) -> getId() == m_id && "Not compatible!");
	m_outEdges.push_back(e);
}

std::list<Edge*>& Vertex::getIncEdges()
{
	return m_incEdges;
}

const std::list<Edge*>& Vertex::getIncEdges() const
{
	return m_incEdges;
}

std::list<Edge*>& Vertex::getOutEdges()
{
	return m_outEdges;
}

const std::list<Edge*>& Vertex::getOutEdges() const
{
	return m_outEdges;
}

std::size_t Vertex::getId() const
{
	return m_id;
}

void Vertex::setId(const std::size_t id)
{
	m_id = id;
}


//***************class Edge 
Edge::Edge()
	: m_source(nullptr)
	, m_target(nullptr)
{
}

Edge::Edge(Vertex *source, Vertex *target)
	: m_source(source)
	, m_target(target)
{
}

Vertex* Edge::getSource() const
{	
	return m_source;
}

Vertex* Edge::getTarget() const
{	
	return m_target;
}
		
void Edge::setSource(Vertex *v)
{	
	m_source = v;
}
		
void Edge::setTarget(Vertex *v)
{	
	m_target = v;
}

//bool Edge::operator< (const Edge& e) const
//{	
//	return (*this).getSource()->getId() < e.getSource()->getId();
//}


//***************class Graph 
Graph::Graph() : m_n(0)
{
}

std::size_t Graph::getVertexCount() const
{
	return m_n;
}

std::size_t Graph::addVertex(Vertex* v)
{
	m_adjList.push_back(v);
	++m_n;
	return v->getId();
}

void Graph::addEdge(std::size_t source_id, std::size_t target_id)
{
	Edge* edge = new Edge(Edge(m_adjList[source_id], m_adjList[target_id]));
	m_adjList[source_id] -> addOutEdge(edge);
	m_adjList[target_id] -> addIncEdge(edge);
}

void Graph::addEdge(Vertex* source, Vertex* target)
{
	Edge* edge = new Edge(Edge(source, target));
	source -> addOutEdge(edge);
	target -> addIncEdge(edge);
}

//returns a vector element whoseindex is entered as an argument 
Vertex* Graph::getVertex(std::size_t index)
{
	return m_adjList[index];
}

const Vertex* Graph::getVertex(std::size_t index) const
{
	return m_adjList[index];
}

Edge* Graph::getEdge(Vertex* v1, Vertex* v2)
{
	for(auto ed : (v1 -> getOutEdges()) ) {
		if( ed -> getTarget() == v2) {
			return ed;
		}
	}
}

const Edge* Graph::getEdge(Vertex* v1, Vertex* v2) const
{
	for(auto &ed : (v1 -> getOutEdges()) ) {
		if( ed -> getTarget() == v2) {
			return ed;
		}
	}
}

Edge* Graph::getEdge(std::size_t i1, std::size_t i2)
{
	for(auto ed : (getVertex(i1) -> getOutEdges()) ) {
		if( ed -> getTarget() == getVertex(i2)) {
			return ed;
		}
	}
}

const Edge* Graph::getEdge(std::size_t i1, std::size_t i2) const
{
	for(auto ed : (getVertex(i1) -> getOutEdges()) ) {
		if( ed -> getTarget() == getVertex(i2)) {
			return ed;
		}
	}
}

std::vector<Edge*> getEdgeVector(const Graph& g)
{
	std::vector<Edge*> ev;
	for(auto v : g.m_adjList) {
		for( auto l : (v->getOutEdges()) ) {
			ev.push_back(l);
		}	
	}
	return ev;
}
