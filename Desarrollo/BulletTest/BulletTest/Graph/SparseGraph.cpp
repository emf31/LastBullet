#include "SparseGraph.h"
#include "GraphEnumeration.h"
#include <fstream>

#include "../json/json.hpp"
#include <MapLoader.h>
#include <GraphicEngine.h>


NavGraphNode & SparseGraph::getNode(int idx) {
	if (idx < 0 || idx >= m_nodes.size()) {
		throw std::runtime_error("Error Nodo no encontrado");
	}
	return m_nodes.at(idx);
}

GraphEdge& SparseGraph::getEdge(int from, int to)
{


	std::list<GraphEdge> aux = m_Edges.at(from);
	for (auto i = aux.begin(); i != aux.end(); ++i) {
		if (i->To() == to)
			return *i;
	}

}

int SparseGraph::addNode(NavGraphNode node)
{
	if (node.Index() < (int)m_nodes.size()) {

		m_nodes.at(node.Index()) = node;
		return m_nextNodeIndex;
	}
	else {

		m_nodes.push_back(node);
		std::list<GraphEdge> edgelist;
		m_Edges.push_back(edgelist);

		return m_nextNodeIndex++;
	}

}

void SparseGraph::removeNode(int node)
{


	m_nodes[node].setIndex(invalid_node_index);//pones el nodo a index invalido


	if (!m_digraph)
	{
		for (std::list<GraphEdge>::iterator curEdge = m_Edges[node].begin(); curEdge != m_Edges[node].end(); ++curEdge) //recorre todos los nodos en el vector de edges
		{
			for (std::list<GraphEdge>::iterator curE = m_Edges[curEdge->To()].begin(); curE != m_Edges[curEdge->To()].end(); ++curE) //vas sacando los nodos de las listas de edges
			{
				if (curE->To() == node)
				{
					curE = m_Edges[curEdge->To()].erase(curE);

					break;
				}
			}
		}
		m_Edges[node].clear();//por ultimo eliminas la posicion del vector del nodo de edge
	}
	else {

		for (std::vector<std::list<GraphEdge>>::iterator curEdgeList = m_Edges.begin(); curEdgeList != m_Edges.end(); ++curEdgeList)
		{
			for (std::list<GraphEdge>::iterator curEdge = (*curEdgeList).begin(); curEdge != (*curEdgeList).end(); ++curEdge)
			{
				if (m_nodes[curEdge->To()].Index() == invalid_node_index ||
					m_nodes[curEdge->From()].Index() == invalid_node_index)
				{
					curEdge = (*curEdgeList).erase(curEdge);
				}
			}
		}
	}
}

//Anade una arista al grafo, asegurandose de que no sea una arista duplicada,
//ademas si el grafo es no dirigido hay que anadir una arista en el sentido opuesto.
void SparseGraph::addEdge(GraphEdge edge)
{

	if ((m_nodes[edge.To()].Index() != invalid_node_index) &&
		(m_nodes[edge.From()].Index() != invalid_node_index))
	{

		if (UniqueEdge(edge.From(), edge.To()))
		{
			m_Edges[edge.From()].push_back(edge);
		}


		if (!m_digraph)
		{

			if (UniqueEdge(edge.To(), edge.From()))
			{
				GraphEdge NewEdge = edge;

				NewEdge.setTo(edge.From());
				NewEdge.setFrom(edge.To());

				m_Edges[edge.To()].push_back(NewEdge);
			}
		}
	}
}

void SparseGraph::readGraph(const std::string & path) {
	using namespace nlohmann;
	std::ifstream stream(path);
	if (stream) {
		json j = json::parse(stream);
		for (json::iterator it = j.begin(); it != j.end(); ++it) {
			json obj = *it;
			if (obj["tag"] == "Grafo") {
				json jsonArray = obj["n_children"];
				for (json::iterator arrayIt = jsonArray.begin(); arrayIt != jsonArray.end(); ++arrayIt) {
					json nodoJson = *arrayIt;
					Entity* ent = NULL;
					std::string extra = nodoJson["extraInfo"];
					if (extra == "LifeObject") {
						float auxZ = nodoJson["posZ"];
						auxZ *= -1.f;
						ent = MapLoader::createLifeObject(Vec3<float>(nodoJson["posX"], nodoJson["posY"], auxZ), Vec3<float>(2.f, 2.f, 2.f), "");
						//std::cout << "Leemos nodo vida \n";
					}
					else if (extra == "AsaltoDrop") {
						float auxZ = nodoJson["posZ"];
						auxZ *= -1.f;
						ent = MapLoader::createAsaltoDrop(Vec3<float>(nodoJson["posX"], nodoJson["posY"], auxZ), Vec3<float>(2.f, 2.f, 2.f), "");
					}
					else if (extra == "PistolaDrop") {
						float auxZ = nodoJson["posZ"];
						auxZ *= -1.f;
						ent = MapLoader::createPistolaDrop(Vec3<float>(nodoJson["posX"], nodoJson["posY"], auxZ), Vec3<float>(2.f, 2.f, 2.f), "");
					}
					else if (extra == "RocketLauncherDrop") {
						float auxZ = nodoJson["posZ"];
						auxZ *= -1.f;
						ent = MapLoader::createRocektLauncherDrop(Vec3<float>(nodoJson["posX"], nodoJson["posY"], auxZ), Vec3<float>(2.f, 2.f, 2.f), "");
					}
					else if (extra == "SniperDrop") {
						//std::cout << "Leemos nodo RocketLauncherDrop \n";
						float auxZ = nodoJson["posZ"];
						auxZ *= -1.f;
						ent = MapLoader::createSniperDrop(Vec3<float>(nodoJson["posX"], nodoJson["posY"], auxZ), Vec3<float>(2.f, 2.f, 2.f), "");
					}

					float posZ = nodoJson["posZ"];
					posZ *= -1.f;
					NavGraphNode nodo(getNextFreeNodeIndex(), Vec2f(nodoJson["posX"], posZ), nodoJson["posY"]);
					nodo.setExtraInfo(ent);
					addNode(nodo);
				//	GraphicEngine::i().createNode(Vec3<float>(nodoJson["posX"], nodoJson["posY"],posZ), Vec3<float>(1.f, 1.f, 1.f), "", "../media/box.obj");
				}
				for (json::iterator arrayIterador1 = jsonArray.begin(); arrayIterador1 != jsonArray.end(); ++arrayIterador1) {
					json nodoJson = *arrayIterador1;
					json arrayConexiones = nodoJson["conexiones"];

					for (json::iterator arrayIterador2 = arrayConexiones.begin(); arrayIterador2 != arrayConexiones.end(); ++arrayIterador2) {
						int conexion = *arrayIterador2;
						std::string str = nodoJson["name"];
						int idx = std::stoi(str);

						NavGraphNode nodoConex = getNode(conexion);
						NavGraphNode nodoActual = getNode(idx);

						Vec2f componentes(nodoConex.getPosition() - nodoActual.getPosition());
						float coste = componentes.Magnitude();

						GraphEdge edge(idx, conexion, coste);
						addEdge(edge);
					}
				}
				break;
				//No necesitamos nada mas del fichero
			}
		}
	}
}

bool SparseGraph::UniqueEdge(int from, int to) const
{
	for (std::list<GraphEdge>::const_iterator curEdge = m_Edges[from].begin();
		curEdge != m_Edges[from].end();
		++curEdge)
	{
		if (curEdge->To() == to)
		{
			return false;
		}
	}

	return true;
}


int SparseGraph::numEdges()
{
	int tot = 0;

	for (std::vector<std::list<GraphEdge>>::iterator curEdge = m_Edges.begin();
		curEdge != m_Edges.end();
		++curEdge)
	{
		tot += curEdge->size();
	}

	return tot;
}

bool SparseGraph::isNodePresent(std::size_t node) const
{
	if ((m_nodes[node].Index() == invalid_node_index) || (node >= m_nodes.size()))
	{
		return false;
	}
	else return true;
}

bool SparseGraph::isEdgePresent(int from, int to)
{
	if (isNodePresent(from) && isNodePresent(from))
	{
		for (std::list<GraphEdge>::iterator curEdge = m_Edges[from].begin();
			curEdge != m_Edges[from].end();
			++curEdge)
		{
			if (curEdge->To() == to) return true;
		}

		return false;
	}
	else return false;
}

void SparseGraph::clear()
{
	m_nextNodeIndex = 0; m_nodes.clear(); m_Edges.clear();
}

