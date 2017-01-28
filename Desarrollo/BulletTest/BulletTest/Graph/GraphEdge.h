#pragma once
#include <GraphEnumeration.h>



class GraphEdge {
protected:
	int m_from;
	int m_to;

	double m_cost;
public:
	GraphEdge(int from, int to, double cost);
	GraphEdge(int from, int to);
	GraphEdge();

	~GraphEdge();

	int From()const { return m_from; };
	void setFrom(int from) { m_from = from; };
	int To()const { return m_to; };
	void setTo(int to) { m_to = to; };

	double Cost()const { return m_cost; };
	void setCost(double cost) { m_cost = cost; };

	//operadores de comparacion de aristas
	bool operator==(const GraphEdge& rhs) const
	{
		return rhs.m_from == this->m_from &&
			rhs.m_to == this->m_to   &&
			rhs.m_cost == this->m_cost;
	}

	bool operator!=(const GraphEdge& rhs) const
	{
		return !(*this == rhs);
	}

};