#pragma once
#include "GraphNode.h"
#include "../Otros/Vec2f.h"

class NavGraphNode : public GraphNode {
protected:
	Vec2f m_position;//guardamos la posicion en el espacio del nodo en 2D

	void* m_extraInfo;//Aqui se puede añadir mas informacion en caso de que sea necesario
public:
	//NavGraphNode() :m_extraInfo(extraInfo()) {};

	NavGraphNode(int      idx,
		Vec2f pos) :GraphNode(idx),
		m_position(pos),
		m_extraInfo(extraInfo())
	{}
	void* extraInfo()const { return m_extraInfo; };

	void setExtraInfo(void* extra_inf) { m_extraInfo = extra_inf; }

	Vec2f getPosition() const { return m_position; }
};