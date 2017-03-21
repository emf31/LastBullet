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

void MapLoader::UnityCoordsToOpenGL(Vec3<float>& pos,
	Vec3<float>& rot,
	Vec3<float>& scale)
{
	//LeftHand to RightHand
	pos.setZ(pos.getZ() * -1.f);

	if (rot.getX() != 0) {
		rot.setX(-rot.getX());
	}

	if (rot.getY() != 0) {
		rot.setY(-rot.getY());
	}
}


void MapLoader::readMap(const std::string & name)
{	
	std::ifstream i(name);
	if(i){
		json j = json::parse(i);
		
		for (json::iterator it = j.begin(); it != j.end(); ++it) {
			
			json obj = *it;

			Vec3<float> pos =					Vec3<float>(obj["posX"], obj["posY"], obj["posZ"]);
			Vec3<float> rot =					Vec3<float>(obj["rotX"], obj["rotY"], obj["rotZ"]);
			Vec3<float> es =					Vec3<float>(obj["sizeX"], obj["sizeY"], obj["sizeZ"]);
			Vec3<float> centerCollider =		Vec3<float>(obj["colliderX"], obj["colliderY"], obj["colliderZ"]*-1);
			Vec3<float> sizeColllider =			Vec3<float>(obj["colliderSizeX"], obj["colliderSizeY"], obj["colliderSizeZ"]);
			float mass =						obj["masa"];
			std::string nameMesh =				obj["nombre"];

			//Modify vectors so OpenGL can understand them
			UnityCoordsToOpenGL(pos, rot, es);

			nameMesh = "../media/Props/" + nameMesh+ ".obj";
			std::string mesh = nameMesh.c_str();



			std::string extraTags = obj["extraTags"];

			if (obj["tag"] == "PhysicEntity") {

				std::shared_ptr<BasicSceneNode> node = createPhysicEntity(pos, es, rot, centerCollider, sizeColllider, mesh, nameMesh, mass);

				/*if (extraTags == "life") {
					node->setTexture("../media/life.png",0);
				} else if (extraTags == "pistola") {
					node->setTexture("../media/pistola.jpg", 0);
				} else if (extraTags == "rocket") {
					node->setTexture("../media/lanzacohetes.jpg", 0);
				} else if (extraTags == "asalto") {
					node->setTexture("../media/asalto.jpg", 0);
				} else if (extraTags == "asalto") {
					node->setTexture("../media/sniper.png", 0);
				}*/

			}
					
			if (obj["tag"] == "LifeObject")
				createLifeObject(pos, es, mesh);
			if (obj["tag"] == "PistolaDrop")
				createPistolaDrop(pos, es, mesh);
			if (obj["tag"] == "AsaltoDrop")
				createAsaltoDrop(pos, es, mesh);
			if (obj["tag"] == "RocketLauncherDrop")
				createRocektLauncherDrop(pos, es, mesh);
			if (obj["tag"] == "SniperDrop")
				createSniperDrop(pos, es, mesh);
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
			if (obj["tag"] == "PointLight") {
				Vec3<float> rgb = Vec3<float>(obj["color_r"], obj["color_g"], obj["color_b"]);
				GraphicEngine::i().createPointLight(pos, rgb);
					
			}
				
			if (obj["tag"] == "DirectionalLight") {
				Vec3<float> rgb = Vec3<float>(obj["color_r"], obj["color_g"], obj["color_b"]);
				rot.normalise();
				GraphicEngine::i().createDirectionalLight(pos,rot, rgb);
			}
					
		}
	}

	//std::cout << j.dump() << std::endl;
}


std::shared_ptr<BasicSceneNode> MapLoader::CreateNodeExceptionSafe(const Vec3<float>& TPosition, const Vec3<float>& TScale, const std::string & texture, const std::string & mesh) {

	std::shared_ptr<BasicSceneNode> sceneNode;
	try {
		sceneNode = GraphicEngine::i().createNode(TPosition, TScale, texture, mesh);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return sceneNode;
}
std::shared_ptr<BasicSceneNode> MapLoader::createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, Vec3<float>centerCol, Vec3<float>sizeCol, const std::string & mesh, std::string &name, float mass)
{
	//Creates node
	std::shared_ptr<BasicSceneNode> sceneNode = CreateNodeExceptionSafe(posicion, escala, "", mesh);

	PhysicsEntity *physicent = new PhysicsEntity(sceneNode, name);

	float mymass=0;
	//si la masa es muy pequeña la consideraremos 0
	if (mass < 0.001) { mymass = 0; }
	else { mymass = mass; }

	//Keep physics right if has some scale
	sizeCol = sizeCol * (escala / 2);

	physicent->centerCollision = centerCol;
	physicent->setRigidBody(PhysicsEngine::i().createBoxRigidBody(physicent, sizeCol, mymass,true, centerCol));
	physicent->rotate(Vec3<float>(float(rotacion.getX()* M_PI / 180.0), float(rotacion.getY() * M_PI / 180.0), float(rotacion.getZ()* M_PI / 180.0)));
	physicent->update(Time::Zero);
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
	

	return sceneNode;
}


Entity* MapLoader::createLifeObject(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{
	//Creates node
	std::shared_ptr<BasicSceneNode> vida = CreateNodeExceptionSafe(posicion, escala, "", mesh);
	LifeObject *vidaEnt = new LifeObject(vida, "LifeObject");
	vidaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(vidaEnt, escala*2.f));
	vidaEnt->setPosition(posicion);

	return vidaEnt;
}

Entity* MapLoader::createAsaltoDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{
	//Creates node
	std::shared_ptr<BasicSceneNode> asaltodrop = CreateNodeExceptionSafe(posicion, escala, "", mesh);
	AsaltoDrop *AsaltoDropEnt = new AsaltoDrop(asaltodrop, "AsaltoDrop");
	AsaltoDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(AsaltoDropEnt, escala*2.f));
	AsaltoDropEnt->setPosition(posicion);

	return AsaltoDropEnt;
}

Entity* MapLoader::createPistolaDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{
	//Creates node
	std::shared_ptr<BasicSceneNode> pistoladrop = CreateNodeExceptionSafe(posicion, escala, "", mesh);
	PistolaDrop *pistolaEnt = new PistolaDrop(pistoladrop, "PistolaDrop");
	pistolaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(pistolaEnt, escala*2.f));
	pistolaEnt->setPosition(posicion);

	return pistolaEnt;
}

Entity* MapLoader::createRocektLauncherDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{
	//Creates node
	std::shared_ptr<BasicSceneNode> lanzacohete = CreateNodeExceptionSafe(posicion, escala, "", mesh);
	RocketLauncherDrop *RocketLauncherDropEnt = new RocketLauncherDrop(lanzacohete,"RocketDrop");
	RocketLauncherDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(RocketLauncherDropEnt, escala*2.f));
	RocketLauncherDropEnt->setPosition(posicion);

	return RocketLauncherDropEnt;
}

Entity* MapLoader::createSniperDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{
	//Creates node
	std::shared_ptr<BasicSceneNode> sniper = CreateNodeExceptionSafe(posicion, escala, "", mesh);
	SniperDrop *SniperDropEnt = new SniperDrop(sniper, "SniperDrop");
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

