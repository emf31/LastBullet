#pragma once
class GraphNode {

protected:
	int m_index; //cada nodo tiene un indice siempre

public:

	GraphNode(int index) :m_index(index){};
	virtual ~GraphNode();
	int Index() const { return m_index; };
	void setIndex(int index) { m_index = index; };



};