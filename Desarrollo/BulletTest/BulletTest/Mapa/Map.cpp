#include "Map.h"
#include <GraphEdge.h>
#include <EntityManager.h>
#include <Util.h>
#include <PhysicsEngine.h>
#include <EntActive.h>


void Map::addNodosToCells()
{
	
	for (std::vector<NavGraphNode>::iterator it = grafo->m_nodes.begin(); it != grafo->m_nodes.end(); ++it)
	{
		cellSpace->addNodoACelda(*it);
	}
}

Map::Map() : grafo(NULL), cellSpace(NULL)
{
}



void Map::inicializar(const std::string& mapa)
{


	//dimensiones del mapa 647x475
	//se crea la division del espacio en celdas
	cellSpace = new CellSpacePartition(100, 100, 5, 5);

	//Lee el mapa
	map.readMap(mapa);


	//GRAFO
	
	//True, grafo dirigido
	grafo = new SparseGraph(true);
	grafo->readGraph("../media/landing.json");


	//se meten los nodos a las celdas correspondientes
	
	std::cout << "AÑADIMOS LOS NODOS A LAS CELDAS" << std::endl;
	addNodosToCells();

#ifdef NAV_INFO
	cellSpace->mostrarContenido();
#endif // NAV_INFO

	




	//AStarSearch astar(grafo, 0 , 2);
	//std::list<int> camino = astar.GetPathToTarget();


}



void Map::borrarContenido() {
	delete grafo;
	delete cellSpace;
}
bool Map::isPathObstructed(Vec3<float> posIni, Vec3<float> posFinal, float radio)
{

	btScalar altura = 2;
	Vec3<float> aumento = posFinal - posIni;
	//****************************RayCast central***************************************
	btVector3 start = btVector3((btScalar)posIni.getX(), (btScalar)posIni.getY()+1, (btScalar)posIni.getZ());
	btVector3 target = btVector3((btScalar)posFinal.getX(), (btScalar)posFinal.getY()+1, (btScalar)posFinal.getZ());
	//btVector3 distancia = target - start;
	//distancia.length();	
	/*btVector3 direccion = target - start;
	direccion.normalize();

	//antes estaba esto pero como quiero que solo sea hasta el nodo le quito el size of world no se si funcionara
	//btVector3 end = start + (direccion*SIZE_OF_WORLD);
	btVector3 SIZE_OF_WORLD = btVector3(1500, 1500, 1500);
	btVector3 end = start + (direccion*SIZE_OF_WORLD);*/

	btCollisionWorld::ClosestRayResultCallback ray(start, target);

	PhysicsEngine::i().m_world->rayTest(start, target, ray);

	if (ray.hasHit())//si ray ha golpeado algo entro
	{
		//Veo la entity que colisiona
		Entity* ent = static_cast<Entity*>(ray.m_collisionObject->getUserPointer());
		if (ent->getClassName() == "PhysicsEntity")
		{
			//ha colisionado con una entity que no es el player
			//std::cout << " EL RAY CAST CENTRAL HA COLISIONADO CON UNA PARED" << std::endl;
			return true;
		}
	}
	//**********************************************************************************


	/*
	//****************************RayCast Izquierda***************************************
	Vec2f rayCastIzquierdaIni = posIni;
	rayCastIzquierdaIni.x -= aumento.x;
	rayCastIzquierdaIni.y += aumento.y;
	Vec2f rayCastIzquierdaFin = posFinal;
	rayCastIzquierdaFin.x -= aumento.x;
	rayCastIzquierdaFin.y += aumento.y;


	btVector3 start1 = btVector3(rayCastIzquierdaIni.x, altura, rayCastIzquierdaIni.y);
	btVector3 target1 = btVector3(rayCastIzquierdaFin.x, altura, rayCastIzquierdaFin.y);
	btVector3 direccion1 = target1 - start1;
	direccion1.normalize();

	//antes estaba esto pero como quiero que solo sea hasta el nodo le quito el size of world no se si funcionara
	//btVector3 end = start + (direccion*SIZE_OF_WORLD);
//	btVector3 end1 = start1 + (direccion1*SIZE_OF_WORLD);

	btCollisionWorld::ClosestRayResultCallback ray1(start1, target);

	PhysicsEngine::i().m_world->rayTest(start1, target, ray1);

	if (ray1.hasHit())//si ray ha golpeado algo entro
	{
		//Veo la entity que colisiona
		Entity* ent = static_cast<Entity*>(ray1.m_collisionObject->getUserPointer());
		if (ent != EntityManager::i().getEntity(PLAYER))
		{
			//ha colisionado con una entity que no es el player
			std::cout << "OOOOOOOOOOOOJOOOOOOOOOOOOOOOOOOOOOOOOO EL RAY CAST IZQUIERDA HA COLISIONADO CON UNA PARED" << std::endl;
			return true;
		}
	}

	//**********************************************************************************


	//****************************RayCast Derecha***************************************
	Vec2f rayCastDerechaIni = posIni;
	rayCastDerechaIni.x += aumento.x;
	rayCastDerechaIni.y -= aumento.y;
	Vec2f rayCastDerechaFin = posFinal;
	rayCastDerechaFin.x += aumento.x;
	rayCastDerechaFin.y -= aumento.y;


	btVector3 start2 = btVector3(rayCastDerechaIni.x, altura, rayCastDerechaIni.y);
	btVector3 target2 = btVector3(rayCastDerechaFin.x, altura, rayCastDerechaFin.y);
	btVector3 direccion2 = target2 - start2;
	direccion2.normalize();

	//antes estaba esto pero como quiero que solo sea hasta el nodo le quito el size of world no se si funcionara
	//btVector3 end = start + (direccion*SIZE_OF_WORLD);
	//btVector3 end2 = start2 + (direccion2*SIZE_OF_WORLD);

	btCollisionWorld::ClosestRayResultCallback ray2(start2, target);

	PhysicsEngine::i().m_world->rayTest(start2, target, ray2);

	if (ray2.hasHit())//si ray ha golpeado algo entro
	{
		//Veo la entity que colisiona
		Entity* ent = static_cast<Entity*>(ray2.m_collisionObject->getUserPointer());
		if (ent != EntityManager::i().getEntity(PLAYER))
		{
			//ha colisionado con una entity que no es el player
			std::cout << "OOOOOOOOOOOOJOOOOOOOOOOOOOOOOOOOOOOOOO EL RAY CAST DERECHA HA COLISIONADO CON UNA PARED" << std::endl;
			return true;
		}
	}

	//**********************************************************************************
	*/
	return false;

	
}

void Map::ConvertirNodosAPosiciones(std::list<int>& CaminoDeNodos, std::list<Vec3<float>>& camino)
{
	//Iteramos la lista de node index y obtenemos el nodo del grafo para meter la pos en el camino
	for (std::list<int>::const_iterator it = CaminoDeNodos.begin(); it != CaminoDeNodos.end(); ++it) {
		camino.push_back(Vec3<float>(grafo->getNode(*it).getPosition().x,grafo->getNode(*it).getHeight(), grafo->getNode(*it).getPosition().y));
		
	}
}

//Busca un punto de respawn seguro en el mapa
Vec3<float> Map::searchSpawnPoint()
{
	float radio = 30.f;
	float fDistance = 0;
	int spawn = 0;

	std::vector<Vec3<float>> m_spawns = map.getSpawnPoints();

	if (m_spawns.empty()) {
		return Vec3<float>(0,0,0);
	}

	if (m_spawns.size() == 1) {
		return m_spawns.at(0);
	}

	std::list<EntActive*> enemies = EntityManager::i().getEnemies();

	std::vector<Vec3<float>> auxSpawns;

	std::list<EntActive*>::iterator it;
	std::vector<Vec3<float>>::iterator it2;

	for (it2 = m_spawns.begin(); it2 != m_spawns.end(); ++it2) {
		bool valid = true;
		for (it = enemies.begin(); it != enemies.end(); ++it) {
			Vec3<float> vector = (*it)->getRenderState()->getPosition() - (*it2);
			fDistance = vector.Magnitude();

			if (fDistance < radio) {
				valid = false;
				break;
			}

		}
		if (valid) {
			auxSpawns.push_back(*it2);
		}

	}

	//Si hay mas de 1 elegimos uno aleatorio
	if (auxSpawns.size() > 1) {
		spawn = Randi(0, auxSpawns.size() - 1);
	}

	//Si no esta vacio es que hemos encontrado uno
	if (!auxSpawns.empty()) {
		//p_controller->reset(PhysicsEngine::i().m_world);
		//setPosition(auxSpawns.at(spawn));
		return auxSpawns.at(spawn);
	}
	else {
		//p_controller->reset(PhysicsEngine::i().m_world);
		//setPosition(m_spawns.at(Randi(0, m_spawns.size() - 1)));
		return m_spawns.at(Randi(0, m_spawns.size() - 1));
	}
}

void Map::CalcularNodosCercanos(Vec3<float>& pos, std::list<NavGraphNode*>& nodosCercanos, Vec3<float>& posBot)
{
	
	std::vector<int> celdasVecinas;
	int indCelda = cellSpace->PositionToIndex(pos.getX(),pos.getZ());
	//std::cout << "ESTOY EN LA CELDA NUMERO: " << indCelda << std::endl;
	cellSpace->CalculaNodoEnCelda(indCelda, nodosCercanos,celdasVecinas, pos);
	
	if (nodosCercanos.size() == 0) {
		cellSpace->CalculaNodosEnCeldasVecinas(indCelda, nodosCercanos, celdasVecinas, pos);
	}
	if(nodosCercanos.size() == 0) {
		//nos guardamos en celdasVecinas las celdas visitadas para luego calcular las celdas vecina de cada una de las visitadas, es decir,
		//la primera vez visitamos las 8 vecinas de indCelda, pero si no encontramos ningun nodo, la segunda vez tendriamos que visitar las
		//8 vecinas de cada una de las celdas que visitamos antes, para ello recorremos la lista
		int tam = celdasVecinas.size();
		for (int i = 0; i < tam; i++) {
			
			
			cellSpace->CalculaNodosEnCeldasVecinas(celdasVecinas[i], nodosCercanos, celdasVecinas,pos);
			
		}
		if (nodosCercanos.size() == 0) {
			int inicio = tam;
			/*for (inicio; inicio < tam2; inicio++) {
				try {
					cellSpace->CalculaNodosEnCeldasVecinas(celdasVecinas[inicio], nodosCercanos, celdasVecinas, pos);
				} catch (std::runtime_error e) {
					break;
				}
				

			}*/
			throw std::runtime_error("FOR DEL INFIERNO");
		}

		
		
	}

	
}
