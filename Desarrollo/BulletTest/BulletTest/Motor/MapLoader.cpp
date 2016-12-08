#include "MapLoader.h"
#include "../json/json.hpp"
#include "../Entities\PhysicsEntity.h"
#include "GraphicEngine.h"

// for convenience
using json = nlohmann::json;

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
				std::cout << "----------------------------" << '\n';
				std::cout << "Nombre " << obj["nombre"] << '\n';
				std::cout << "Posicion " << obj["posX"] << ',' << obj["posY"] << ',' << obj["posZ"] << '\n';
				std::cout << "Rotacion " << obj["rotX"] << ',' << obj["rotY"] << ',' << obj["rotZ"] << '\n';
				std::cout << "Escalado " << obj["sizeX"] << ',' << obj["sizeY"] << ',' << obj["sizeZ"] << '\n';
				std::cout << "Collider " << obj["colliderSizeX"] << ',' << obj["colliderSizeX"] << ',' << obj["colliderSizeX"] << '\n';
				std::cout << "Masa " << obj["masa"] << '\n';
				createPhysicEntity(pos, es, rot, centerCollider, sizeColllider, mesh, nombre, mass);
		//	}
		}
	}

	//std::cout << j.dump() << std::endl;
}
void MapLoader::createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, Vec3<float>centerCol, Vec3<float>sizeCol, const io::path & mesh, std::string &name, float mass)
{

	std::shared_ptr<BasicSceneNode> sceneNode = GraphicEngine::i().createNode(posicion, escala, "../media/juliyotexture.jpg", mesh);
	PhysicsEntity *physicent = new PhysicsEntity(sceneNode, name);
	float mymass=0;
	if (mass < 0.001) {
		mymass = 0;
	}
	else {
		mymass = mass;
	}

	if (mass != 0)
		sizeCol = sizeCol*(escala / 2);


	physicent->centerCollision = centerCol;
	physicent->setRigidBody(PhysicsEngine::i().createBoxRigidBody(physicent, sizeCol, mymass,true, centerCol));
	//physicent->getRigidBody
	//std::cout<<"WorldTransform: "<<physicent->getRigidBody()->getWorldTransform().getOrigin().x()<<","<< physicent->getRigidBody()->getWorldTransform().getOrigin().y()<<","<< physicent->getRigidBody()->getWorldTransform().getOrigin().z()<<'\n';
	//physicent->setPosition(posicion);
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
		//cajaEnt->getRigidBody()->setRollingFriction(btScalar(0.8f));
		physicent->getRigidBody()->setFriction(btScalar(0.8f));
		physicent->getRigidBody()->setAngularFactor(btScalar(0.3f));
	}
	
	//std::cout << "WorldTransform: " << physicent->getRigidBody()->getWorldTransform().getOrigin().x() << "," << physicent->getRigidBody()->getWorldTransform().getOrigin().y() << "," << physicent->getRigidBody()->getWorldTransform().getOrigin().z() << '\n';
	//std::cout << sceneNode->getPosition().getX() << '\n';
}


