#pragma once
#include <GraphEnumeration.h>
class GraphEdge {
protected:
	int m_from;
	int m_to;

	double m_cost;
public:
	GraphEdge(int from, int to, double cost):m_from(from),m_to(to),m_cost(cost) {}
	GraphEdge(int from, int to) :m_from(from), m_to(to), m_cost(1.0) {}
	GraphEdge() : m_cost(1.0),
		m_from(invalid_node_index),
		m_to(invalid_node_index)
	{}

	~GraphEdge();

	int From()const { return m_from; };
	void setFrom(int from) { m_from = from; };
	int To()const { return m_to; };
	void setTo(int to) { m_to = to; };

	double Cost()const { return m_cost; };
	void setCost(double cost) { m_cost = cost; };

	//these two operators are required
	bool operator==(const GraphEdge& rhs)
	{
		return rhs.m_from == this->m_from &&
			rhs.m_to == this->m_to   &&
			rhs.m_cost == this->m_cost;
	}

	bool operator!=(const GraphEdge& rhs)
	{
		return !(*this == rhs);
	}
	bool operator==(GraphEdge& rhs)
	{
		return rhs.m_from == this->m_from &&
			rhs.m_to == this->m_to   &&
			rhs.m_cost == this->m_cost;
	}

	bool operator!=(GraphEdge& rhs)
	{
		return !(*this == rhs);
	}
};