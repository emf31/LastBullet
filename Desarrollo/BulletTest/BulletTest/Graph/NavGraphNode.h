#pragma once
#include "GraphNode.h"
#include <Vec2f.h>
#include <Entity.h>

/*enum ExtraInfo {
	T_NORMAL = 0,
	T_ROCKET = 1,
	T_PISTOLA = 2,
	T_ASALTO = 3,
	T_VIDA = 4
};*/

class NavGraphNode : public GraphNode {
protected:
	Vec2f m_position;//guardamos la posicion en el espacio del nodo en 2D

	Entity* m_extraInfo;//Aqui se puede añadir mas informacion en caso de que sea necesario

	float m_height;
public:

	NavGraphNode(int idx, Vec2f pos, float m_height) :
		GraphNode(idx),
		m_position(pos),
		m_height(m_height)
	{}

	Entity* extraInfo() const { return m_extraInfo; };

	void setExtraInfo(Entity* extra_inf) { m_extraInfo = extra_inf; }

	Vec2f getPosition() const { return m_position; }

	float getHeight() const { return m_height; }
};