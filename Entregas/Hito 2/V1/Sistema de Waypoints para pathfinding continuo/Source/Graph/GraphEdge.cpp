#include "GraphEdge.h"

GraphEdge::GraphEdge(int from, int to, double cost) : 
	m_from(from), m_to(to), m_cost(cost) 
{
}

GraphEdge::GraphEdge(int from, int to) : 
	m_from(from), m_to(to), m_cost(1.0) 
{
}

GraphEdge::GraphEdge() : 
	m_cost(1.0), m_from(invalid_node_index), m_to(invalid_node_index)
{}

GraphEdge::~GraphEdge()
{
}
