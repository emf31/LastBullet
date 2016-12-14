#include "MapLoader.h"
#include "../json/json.hpp"
#include "../Entities\PhysicsEntity.h"
#include "../Entities\LifeObject.h"
#include "../Entities\WeaponDrops/AsaltoDrop.h"
#include "../Entities\WeaponDrops/PistolaDrop.h"
#include "../Entities/WeaponDrops/RocketLauncherDrop.h"
#include "GraphicEngine.h"

// for convenience
using json = nlohmann::json;

MapLoader::~MapLoader()
{
}

void MapLoader::readMap(const std::string & name)
{	
	std::ifstream i("../media/map1.json");
	if(i){
		json j = json::parse(i);
		int cont = 0;
		for (json::iterator it = j.begin(); it != j.end(); ++it) {
			
			json obj = *it;
			//std::cout << "Nombre " << obj["nombre"] << '\n';
			//if (obj["nombre"] = "cubo") {
				//std::cout << "Entro?" << '\n';
				cont++;
				Vec3<float> pos = Vec3<float>(obj["posX"], obj["posY"], obj["posZ"]);
				Vec3<float> rot = Vec3<float>(obj["rotZ"], obj["rotY"], obj["rotX"]);
				Vec3<float> es = Vec3<float>(obj["sizeX"], obj["sizeY"], obj["sizeZ"]);

				Vec3<float> centerCollider = Vec3<float>(obj["colliderX"], obj["colliderY"], obj["colliderZ"]);
				Vec3<float> sizeColllider = Vec3<float>(obj["colliderSizeX"], obj["colliderSizeY"], obj["colliderSizeZ"]);
				float mass = obj["masa"];
				std::string s = std::to_string(cont);
				std::string nombre = "cubo"+s;

				std::string nameMesh = obj["nombre"];
				nameMesh = "../media/" +nameMesh+".obj";
				io::path mesh=nameMesh.c_str();

				if(obj["tag"]=="PhysicEntity")
					createPhysicEntity(pos, es, rot, centerCollider, sizeColllider, mesh, nombre, mass);
				if (obj["tag"] == "LifeObject")
					createLifeObject(pos, es, mesh, nombre);
				if (obj["tag"] == "PistolaDrop")
					createPistolaDrop(pos, es, mesh, nombre);
				if (obj["tag"] == "AsaltoDrop")
					createAsaltoDrop(pos, es, mesh, nombre);
				if (obj["tag"] == "RocketLauncherDrop")
					createRocektLauncherDrop(pos, es, mesh, nombre);
				if (obj["tag"] == "Grafo")
					std::cout << "Grafo en " << obj["posX"] << ',' << obj["posY"] << ',' << obj["posZ"] << '\n';
				if (obj["tag"] == "Spawn")
					spawnPoints.push_back(pos);
		}
	}

	//std::cout << j.dump() << std::endl;
}
void MapLoader::createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, Vec3<float>centerCol, Vec3<float>sizeCol, const io::path & mesh, std::string &name, float mass)
{
	std::shared_ptr<BasicSceneNode> sceneNode;
	if (mesh != "../media/cubo.obj"){
		 sceneNode = GraphicEngine::i().createNode(posicion, escala, "../media/ice0.jpg", mesh);
	}
	else{
		sceneNode = GraphicEngine::i().createNode(posicion, escala, "../media/wall.jpg", "");
	}
	
	
	PhysicsEntity *physicent = new PhysicsEntity(sceneNode, name);
	float mymass=0;
	if (mass < 0.001) {//si la masa es muy pequeña la consideraremos 0
		mymass = 0;
	}
	else {
		mymass = mass;
		sizeCol = sizeCol*(escala / 2);
	}

	physicent->centerCollision = centerCol;
	physicent->setRigidBody(PhysicsEngine::i().createBoxRigidBody(physicent, sizeCol, mymass,true, centerCol));
	physicent->rotate(Vec3<float>(float(rotacion.getX()* PI / 180.0), float(rotacion.getY() * PI / 180.0), float(rotacion.getZ()* PI / 180.0)));
	
	if(mass==0){
		physicent->setCollisionGroup(col::Collisions::Static);
		physicent->setCollisionMask(col::staticCollidesWith);
		physicent->getRigidBody()->setFriction(0.7f);
	}
	else{
		physicent->setCollisionGroup(col::Collisions::Caja);
		physicent->setCollisionMask(col::cajaCollidesWith);
		physicent->getRigidBody()->setDamping(btScalar(0.f), btScalar(0.85f));
		physicent->getRigidBody()->setFriction(btScalar(0.8f));
		physicent->getRigidBody()->setAngularFactor(btScalar(0.3f));
	}
	
	//std::cout << "WorldTransform: " << physicent->getRigidBody()->getWorldTransform().getOrigin().x() << "," << physicent->getRigidBody()->getWorldTransform().getOrigin().y() << "," << physicent->getRigidBody()->getWorldTransform().getOrigin().z() << '\n';
	//std::cout << sceneNode->getPosition().getX() << '\n';
}

void MapLoader::createLifeObject(Vec3<float> posicion, Vec3<float> escala, const io::path & mesh, std::string & name)
{
	std::shared_ptr<BasicSceneNode> vida = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/life.png", "");
	LifeObject *vidaEnt = new LifeObject(vida, name);
	vidaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(vidaEnt,escala));
	vidaEnt->setPosition(posicion);
}

void MapLoader::createAsaltoDrop(Vec3<float> posicion, Vec3<float> escala, const io::path & mesh, std::string & name)
{
	std::shared_ptr<BasicSceneNode> asaltodrop = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/Asalto.jpg", "");
	AsaltoDrop *AsaltoDropEnt = new AsaltoDrop(asaltodrop, name);
	AsaltoDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(AsaltoDropEnt, escala));
	AsaltoDropEnt->setPosition(posicion);
}

void MapLoader::createPistolaDrop(Vec3<float> posicion, Vec3<float> escala, const io::path & mesh, std::string & name)
{
	std::shared_ptr<BasicSceneNode> pistoladrop = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/pistola.jpg", "");
	PistolaDrop *pistolaEnt = new PistolaDrop(pistoladrop, name);
	pistolaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(pistolaEnt, escala));
	pistolaEnt->setPosition(posicion);
}

void MapLoader::createRocektLauncherDrop(Vec3<float> posicion, Vec3<float> escala, const io::path & mesh, std::string & name)
{
	std::shared_ptr<BasicSceneNode> lanzacohete = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/lanzacohetes.jpg", "");
	RocketLauncherDrop *RocketLauncherDropEnt = new RocketLauncherDrop(lanzacohete,name);
	RocketLauncherDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(RocketLauncherDropEnt, escala));
	RocketLauncherDropEnt->setPosition(posicion);
}

