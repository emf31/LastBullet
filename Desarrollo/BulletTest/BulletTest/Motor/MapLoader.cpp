#include "MapLoader.h"
#include "../json/json.hpp"
#include "../Entities\PhysicsEntity.h"
#include "../Entities\LifeObject.h"
#include "../Entities\WeaponDrops/AsaltoDrop.h"
#include "../Entities\WeaponDrops/PistolaDrop.h"
#include "../Entities/WeaponDrops/RocketLauncherDrop.h"
#include "../Entities/WeaponDrops/SniperDrop.h"
#include "GraphicEngine.h"
#include "../Entities/Button.h"
#include "../Otros/EnumParser.h"







// for convenience
using json = nlohmann::json;

MapLoader::~MapLoader(){

}


void MapLoader::readMap(const std::string & name)
{	
	std::ifstream i(name);
	if(i){
		json j = json::parse(i);
		int cont = 0;
		for (json::iterator it = j.begin(); it != j.end(); ++it) {
			
			json obj = *it;
			//std::cout << "Nombre " << obj["nombre"] << '\n';
			//if (obj["nombre"] = "cubo") {
				//std::cout << "Entro?" << '\n';
				cont++;
				Vec3<float> pos = Vec3<float>(obj["posX"]*-1, obj["posY"], obj["posZ"]);
				Vec3<float> rot = Vec3<float>(obj["rotX"], obj["rotY"], obj["rotZ"]);
				Vec3<float> es = Vec3<float>(obj["sizeX"], obj["sizeY"], obj["sizeZ"]);

				Vec3<float> centerCollider = Vec3<float>(obj["colliderX"], obj["colliderY"], obj["colliderZ"]);
				Vec3<float> sizeColllider = Vec3<float>(obj["colliderSizeX"], obj["colliderSizeY"], obj["colliderSizeZ"]);
				float mass = obj["masa"];
				std::string s = std::to_string(cont);
				std::string nombre = "cubo"+s;

				std::string nameMesh = obj["nombre"];

				nameMesh = "../media/Props/" +nameMesh+".obj";
				std::string mesh=nameMesh.c_str();


				std::string extraTags = obj["extraTags"];
				//std::cout << "ExtraTags: " << extraTags << std::endl;
				if (obj["tag"] == "PhysicEntity") {
					std::cout << "Soy " << nameMesh << " y mi rotacion Y =" << rot.getY() << std::endl;
					std::shared_ptr<BasicSceneNode> node = createPhysicEntity(pos, es, rot, centerCollider, sizeColllider, mesh, nombre, mass);
					if (extraTags == "life") {
						node->setTexture("../media/life.png",0);
					} else if (extraTags == "pistola") {
						node->setTexture("../media/pistola.jpg", 0);
					} else if (extraTags == "rocket") {
						node->setTexture("../media/lanzacohetes.jpg", 0);
					} else if (extraTags == "asalto") {
						node->setTexture("../media/asalto.jpg", 0);
					} else if (extraTags == "asalto") {
						node->setTexture("../media/sniper.png", 0);
					}

				}
					
				if (obj["tag"] == "LifeObject")
					createLifeObject(pos, es, nombre, mesh);
				if (obj["tag"] == "PistolaDrop")
					createPistolaDrop(pos, es, nombre, mesh);
				if (obj["tag"] == "AsaltoDrop")
					createAsaltoDrop(pos, es, nombre, mesh);
				if (obj["tag"] == "RocketLauncherDrop")
					createRocektLauncherDrop(pos, es, nombre, mesh);
				if (obj["tag"] == "SniperDrop")
					createSniperDrop(pos, es, nombre, mesh);
				if (obj["tag"] == "Grafo")
					std::cout << "Grafo en " << obj["posX"] << ',' << obj["posY"] << ',' << obj["posZ"] << '\n';
				if (obj["tag"] == "Spawn") {
				
					spawnPoints.push_back(pos);
				}
				if (obj["tag"] == "TriggerButton") {
					EnumParser<EnumTriggerType> parser;
					EnumTriggerType type = parser.parseEnum(obj["nombre"]);
					
					createTriggerButton(pos, 5, type);
				}

					
		}
	}

	//std::cout << j.dump() << std::endl;
}
std::shared_ptr<BasicSceneNode> MapLoader::createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, Vec3<float>centerCol, Vec3<float>sizeCol, const std::string & mesh, std::string &name, float mass)
{
	std::shared_ptr<BasicSceneNode> sceneNode;
	if (std::string(mesh.c_str()) != "../media/cubo.obj"){
		 sceneNode = GraphicEngine::i().createNode(posicion, escala, "../media/wall.jpg", mesh);
	}
	else{
		sceneNode = GraphicEngine::i().createNode(posicion, escala, "../media/wall.jpg", mesh);
	}
	//sceneNode->setRotationRightHand(rotacion);
	//Vec3<float> aux = escala;
	//Vec3<float> aux2 = Vec3<float>(rotacion.getX(), rotacion.getY()+180, rotacion.getZ()+180);
	////aux.setX(aux.getX()*-1);
	//aux.setZ(aux.getZ()*-1);
	//aux.setY(aux.getY()*-1);
	//sceneNode->setScale(aux);
	//sceneNode->setRotationXYZ(aux2);

	//Vec3<float> aux = escala;
	//aux.setZ(aux.getZ()*-1);
	//sceneNode->setScale(aux);
	
	PhysicsEntity *physicent = new PhysicsEntity(sceneNode, name);
	float mymass=0;
	if (mass < 0.001) {//si la masa es muy pequeña la consideraremos 0
		mymass = 0;
	}
	else {
		mymass = mass;
		//sizeCol = sizeCol*(escala / 2);
	}
	sizeCol = sizeCol*(escala / 2);

	physicent->centerCollision = centerCol;
	physicent->setRigidBody(PhysicsEngine::i().createBoxRigidBody(physicent, sizeCol, mymass,true, centerCol));
	physicent->rotate(Vec3<float>(float(rotacion.getX()* M_PI / 180.0), float(rotacion.getY() * M_PI / 180.0), float(rotacion.getZ()* M_PI / 180.0)));
	
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
	return sceneNode;
}

/*std::shared_ptr<BasicSceneNode> MapLoader::createConvexHullEntity(Vec3<float> posicion, Vec3<float> escala, Vec3<float> rotacion, const io::path & mesh, float mass)
{
	std::shared_ptr<BasicSceneNode> sceneNode;

	sceneNode = GraphicEngine::i().createNode(posicion, escala, "../media/wall.jpg", mesh);

	PhysicsEntity *physicent = new PhysicsEntity(sceneNode, "");
	float mymass = 0;
	if (mass < 0.001) {//si la masa es muy pequeña la consideraremos 0
		mymass = 0;
	}
	else {
		mymass = mass;
	}


	physicent->setRigidBody(PhysicsEngine::i().createConvexHullRigidBody(physicent, escala, mymass, mesh.c_str()));

	physicent->rotate(Vec3<float>(float(rotacion.getX()* PI / 180.0), float(rotacion.getY() * PI / 180.0), float(rotacion.getZ()* PI / 180.0)));

	if (mass == 0) {
		physicent->setCollisionGroup(col::Collisions::Static);
		physicent->setCollisionMask(col::staticCollidesWith);
		physicent->getRigidBody()->setFriction(0.7f);
	}



	return sceneNode;
}*/

Entity* MapLoader::createLifeObject(Vec3<float> posicion, Vec3<float> escala, const std::string &name, const std::string & mesh = "")
{
	std::shared_ptr<BasicSceneNode> vida = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/life.png", "../media/cubo.obj");
	LifeObject *vidaEnt = new LifeObject(vida, name);
	vidaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(vidaEnt, escala*2.f));
	vidaEnt->setPosition(posicion);

	return vidaEnt;
}

Entity* MapLoader::createAsaltoDrop(Vec3<float> posicion, Vec3<float> escala, const std::string &name, const std::string & mesh = "")
{
	std::shared_ptr<BasicSceneNode> asaltodrop = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/Asalto.jpg", "../media/cubo.obj");
	AsaltoDrop *AsaltoDropEnt = new AsaltoDrop(asaltodrop, name);
	AsaltoDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(AsaltoDropEnt, escala*2.f));
	AsaltoDropEnt->setPosition(posicion);

	return AsaltoDropEnt;
}

Entity* MapLoader::createPistolaDrop(Vec3<float> posicion, Vec3<float> escala, const std::string &name, const std::string & mesh = "")
{
	std::shared_ptr<BasicSceneNode> pistoladrop = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/pistola.jpg", "../media/cubo.obj");
	PistolaDrop *pistolaEnt = new PistolaDrop(pistoladrop, name);
	pistolaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(pistolaEnt, escala*2.f));
	pistolaEnt->setPosition(posicion);

	return pistolaEnt;
}

Entity* MapLoader::createRocektLauncherDrop(Vec3<float> posicion, Vec3<float> escala, const std::string &name, const std::string & mesh = "")
{
	std::shared_ptr<BasicSceneNode> lanzacohete = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/lanzacohetes.jpg", "../media/cubo.obj");
	RocketLauncherDrop *RocketLauncherDropEnt = new RocketLauncherDrop(lanzacohete,name);
	RocketLauncherDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(RocketLauncherDropEnt, escala*2.f));
	RocketLauncherDropEnt->setPosition(posicion);

	return RocketLauncherDropEnt;
}

Entity* MapLoader::createSniperDrop(Vec3<float> posicion, Vec3<float> escala, const std::string &name, const std::string & mesh = "")
{
	std::shared_ptr<BasicSceneNode> sniper = GraphicEngine::i().createNode(Vec3<float>(0, 0, 0), escala, "../media/sniper.png", "../media/cubo.obj");
	SniperDrop *SniperDropEnt = new SniperDrop(sniper, name);
	SniperDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(SniperDropEnt, escala*2.f));
	SniperDropEnt->setPosition(posicion);

	return SniperDropEnt;
}

void MapLoader::createTriggerButton(Vec3<float> posicion, float radio, EnumTriggerType type) {
	int id=-1;
	if (type == EnumTriggerType::Button_Spawn) {
		id = 65534;
	} else if(type == EnumTriggerType::Button_Trig_Ent) {
		id = 65535;
	} else if (type == EnumTriggerType::Button_Trig_Ent_Asalto) {
		id = 65536;
	} else if (type == EnumTriggerType::Button_Trig_Ent_Pistola) {
		id = 65537;
	} else if (type == EnumTriggerType::Button_Trig_Ent_Rocket) {
		id = 65538;
	}
	Button *btn = new Button(nullptr, "Boton", type, id);
	btn->setPosition(posicion);
}

