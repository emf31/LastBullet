#pragma once
#include <Vec2f.h>
#include <SparseGraph.h>
class Heuristic_Euclid
{
public:

	Heuristic_Euclid() {}

	//calculate the straight line distance from node nd1 to node nd2
	static float Calculate(SparseGraph& G, int nd1, int nd2)
	{
		return Vec2f(G.getNode(nd1).getPosition() - G.getNode(nd2).getPosition()).Magnitude();
	}
};