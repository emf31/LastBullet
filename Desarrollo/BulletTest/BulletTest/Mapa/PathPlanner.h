#include <Enemy_Bot.h>
#include <SparseGraph.h>
#include <vector>
#include <Vec2f.h>



#pragma once
class PathPlanner
{
public:
	PathPlanner(Enemy_Bot* bot);
	~PathPlanner();

	//encuentra el camino menos costoso hasta la posicion destino (haria una llamada
	//al metodo de buscar camino de Astar)
	bool CreatePathToPosition(Vec3<float> posObjetivo, std::list<Vec3<float>>& camino);
	//encuentra el camino menos costoso hasta un item (haria una llamada
	//al metodo de buscar camino de Astar)
	float CreatePathToItem(const std::string& tipo, std::list<Vec3<float>>& camino);

	//crea un camino de random con un truco sencillo elije un punto de spawn aleatorio que no este
	//a la vista
	bool CreateRandomPath(std::list<Vec3<float>>& camino);


private:
	Enemy_Bot* m_Bot;
	SparseGraph& m_grafo;
	Vec3<float> m_posDestino;

	//este metodo delvolvera el indice del nodo disponible mas cercano a mi posicion actual
	//que es a partir del cual empezara el algoritmo de busqueda

	//estos metodos lo que tienen que hacer es buscar cuales son los nodos que estan en una celda de espacio que se define al rededor del bot, los que esten dentro de esta celda
	//seran los nodos mas cercanos, y de estos nodos mas cercanos hay que calcular su distancia con la posicion del bot y quedarte con el que menos distancia tenga.
	int getNodoMasCercanoAPos(Vec3<float> pos) const;

	//este metodo lo que hara es intentar suavizar el camino, para ello mirara entre los siguientes nodos del camino
	//y si puede saltarse alguno porque no hay ningun obstaculo se lo saltara, es decir si el camino es 1-2-3,
	//pero del 1 al 3 se puede ir con una linea recta porque no hay obstaculos entonces elimina al 2 del camino.
	void SuavizarCamino(std::list<Vec3<float>>& listaCamino);

	
	


};

