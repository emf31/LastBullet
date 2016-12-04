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
			if (obj["nombre"] == "cubo") {
				//std::cout << "Entro?" << '\n';
				cont++;
				Vec3<float> pos = Vec3<float>(obj["posX"], obj["posY"], obj["posZ"]);
				Vec3<float> rot = Vec3<float>(obj["rotZ"], obj["rotY"], obj["rotX"]);
				Vec3<float> es = Vec3<float>(obj["sizeX"], obj["sizeY"], obj["sizeZ"]);
				float mass = obj["masa"];
				std::string s = std::to_string(cont);
				std::string nombre = "cubo"+s;
				io::path mesh="../media/cubo.obj";
				createPhysicEntity(pos, es, rot, mesh, nombre, mass);
				std::cout << "----------------------------" << '\n';
				std::cout << "Nombre " << nombre << '\n';
				std::cout << "Posicion " << obj["posX"] << ',' << obj["posY"] << ',' << obj["posZ"] << '\n';
				std::cout << "Rotacion " << obj["rotX"] << ',' << obj["rotY"] << ',' << obj["rotZ"] << '\n';
				std::cout << "Escalado " << obj["sizeX"] << ',' << obj["sizeY"] << ',' << obj["sizeZ"] << '\n';
			}
		}
	}

	//std::cout << j.dump() << std::endl;
}
void MapLoader::createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, const io::path & mesh, std::string &name, float mass)
{

	std::shared_ptr<BasicSceneNode> sceneNode = GraphicEngine::i().createNode(posicion, escala, "../media/wall.jpg", "../media/cubo.obj");
	PhysicsEntity *physicent = new PhysicsEntity(sceneNode, name);
	physicent->setRigidBody(PhysicsEngine::i().createBoxRigidBody(physicent, escala, 0));
	physicent->setPosition(posicion);
	//physicent->rotate(rotacion);
	physicent->rotate(Vec3<float>(float(rotacion.getX()* PI / 180.0), float(rotacion.getY() * PI / 180.0), float(rotacion.getZ()* PI / 180.0)));
	physicent->setCollisionGroup(col::Collisions::Static);
	physicent->setCollisionMask(col::staticCollidesWith);
	physicent->getRigidBody()->setFriction(0.7f);
	std::cout << sceneNode->getPosition().getX() << '\n';
}


