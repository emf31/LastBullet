#pragma once
#include <Vec2f.h>
#include <SparseGraph.h>
class Heuristic_Euclid
{
public:

	Heuristic_Euclid() {}

	//linea recta de nd1 a nd2
	static float Calculate(SparseGraph& G, int nodo1, int nodo2)
	{
		return Vec2f(G.getNode(nodo1).getPosition() - G.getNode(nodo2).getPosition()).Magnitude();
	}
};