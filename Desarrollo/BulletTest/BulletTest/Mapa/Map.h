#pragma once

#include <SparseGraph.h>
#include <vec3.hpp>
#include <MapLoader.h>

class Map
{
public:
	static Map& i() {
		static Map singleton;
		return singleton;
	}


	void inicializar();
	//TODO hacer un borrar contenido
	void borrarContenido();

	SparseGraph& getGrafo() {
		return *grafo;
	}

	//este metodo se encarga de comprobar si hay algun obstaculo entre las dos posiciones (un raycast por ejemplo), si no hay ningun obstaculo se sigue un camino recto, sino hay que calcular el camino.
	bool isPathObstructed(Vec2f posIni, Vec2f posFinal, float radio);
	void ConvertirNodosAPosiciones(std::list<int> CaminoDeNodos, std::list<Vec2f> camino);

	//Busca en la lista de puntos de spawn alguno que no intersecte con ningún enemigo de radio x,
	//luego con la lista que queda se coge un punto aleatorio
	Vec3<float> searchSpawnPoint();

	std::vector<Vec3<float>> getSpawnPoints() { return map.getSpawnPoints(); };

private:
	//True, grafo dirigido
	SparseGraph* grafo;

	//Cargador del mapa
	MapLoader map;
	

	Map();
	
};

