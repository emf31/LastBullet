#pragma once

#include <SparseGraph.h>
#include "Celda.h"
#include <vec3.hpp>
#include <MapLoader.h>


class Map
{
public:
	static Map& i() {
		static Map singleton;
		return singleton;
	}


	void inicializar(const std::string& mapa);

	
	void borrarContenido();

	SparseGraph& getGrafo() {
		return *grafo;
	}

	//este metodo se encarga de comprobar si hay algun obstaculo entre las dos posiciones (un raycast por ejemplo), si no hay ningun obstaculo se sigue un camino recto, sino hay que calcular el camino.
	bool isPathObstructed(Vec3<float> posIni, Vec3<float> posFinal, float radio);
	void ConvertirNodosAPosiciones(std::list<int>& CaminoDeNodos, std::list<Vec3<float>>& camino);
	void addNodosToCells();


	//Busca en la lista de puntos de spawn alguno que no intersecte con ningún enemigo de radio x,
	//luego con la lista que queda se coge un punto aleatorio
	Vec3<float> searchSpawnPoint();

	std::vector<Vec3<float>> getSpawnPoints() { return map.getSpawnPoints(); };

	void CalcularNodosCercanos(Vec3<float>& pos, std::list<NavGraphNode*>& nodosCercanos, Vec3<float>& posBot);


	

private:
	//True, grafo dirigido
	SparseGraph* grafo;
	CellSpacePartition* cellSpace;


	//Cargador del mapa
	MapLoader map;
	


	Map();
	
};

