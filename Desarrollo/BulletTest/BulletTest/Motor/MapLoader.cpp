#include "MapLoader.h"
#include "../Entities\PhysicsEntity.h"
#include "../Entities\LifeObject.h"
#include "../Entities\WeaponDrops/AsaltoDrop.h"
#include "../Entities\WeaponDrops/PistolaDrop.h"
#include "../Entities/WeaponDrops/RocketLauncherDrop.h"
#include "../Entities/WeaponDrops/SniperDrop.h"
#include "GraphicEngine.h"
#include "../Entities/Button.h"
#include "../Otros/EnumParser.h"
#include <ClippingManager.h>







// for convenience
using json = nlohmann::json;

MapLoader::~MapLoader(){

}

Object* MapLoader::createObject(json& obj) {
	Object* o = new Object();
	
	o->pos = Vec3<float>(obj["posX"], obj["posY"], obj["posZ"]);
	o->rot = Vec3<float>(obj["rotX"], obj["rotY"], obj["rotZ"]);
	o->es = Vec3<float>(obj["sizeX"], obj["sizeY"], obj["sizeZ"]);
	o->centerCollider = Vec3<float>(obj["colliderX"], obj["colliderY"], obj["colliderZ"] * -1);
	o->sizeColllider = Vec3<float>(obj["colliderSizeX"], obj["colliderSizeY"], obj["colliderSizeZ"]);
	o->mass = obj["masa"];
	std::string nameMesh = obj["nombre"];

	//Modify vectors so OpenGL can understand them
	UnityCoordsToOpenGL(o->pos, o->rot, o->es);

	//We get the resource provider
	ResourceProvider& resourceProvider = Settings::i().GetResourceProvider();

	nameMesh = resourceProvider.getResourceGroupDirectory("props") + nameMesh + ".obj";
	o->nameMesh = nameMesh;
	o->mesh = nameMesh.c_str();

	std::string extraTags = obj["extraTags"];
	o->extraTags = extraTags;

	return o;
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


			Object* o=createObject(obj);


			if (obj["tag"] == "Zona") {
				
				ClippingZone* zone =ClippingManager::i().createClippingZone(o->centerCollider, o->sizeColllider, o->nameMesh);

				json jsonArray = obj["o_children"];
				for (json::iterator arrayIt = jsonArray.begin(); arrayIt != jsonArray.end(); ++arrayIt) {
					json objzone = *arrayIt;
					Object* o_child = createObject(objzone);
					if (objzone["tag"] == "PhysicEntity") {
						std::shared_ptr<StaticSceneNode> node = createPhysicEntity(o_child->pos, o_child->es, o_child->rot, o_child->centerCollider, o_child->sizeColllider, o_child->mesh, o_child->nameMesh, o_child->mass,zone);
					}
					delete o_child;
				}

			}

			if (obj["tag"] == "PhysicEntity") {
				//std::shared_ptr<BasicSceneNode> node = createPhysicEntity(o->pos, o->es, o->rot, o->centerCollider, o->sizeColllider, o->mesh, o->nameMesh, o->mass);

			}
					
			if (obj["tag"] == "Spawn") {
				
				spawnPoints.push_back(o->pos);
			}
			if (obj["tag"] == "TriggerButton") {
				EnumParser<EnumTriggerType> parser;
				EnumTriggerType type = parser.parseEnum(obj["nombre"]);
					
				createTriggerButton(o->pos, 5, type);
			}
			if (obj["tag"] == "PointLight") {
				Vec3<float> rgb = Vec3<float>(obj["color_r"], obj["color_g"], obj["color_b"]);
				GraphicEngine::i().createPointLight(o->pos, rgb);
					
			}
				
			if (obj["tag"] == "DirectionalLight") {
				Vec3<float> vecDir = Vec3<float>(obj["forwardX"], obj["forwardY"], obj["forwardZ"]);
				vecDir.setZ(vecDir.getZ()*-1.0f);
				Vec3<float> rgb = Vec3<float>(obj["color_r"], obj["color_g"], obj["color_b"]);
				o->rot.normalise();
				GraphicEngine::i().createDirectionalLight(o->pos, vecDir, rgb);
			}

			delete o;
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
std::shared_ptr<StaticSceneNode> MapLoader::createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, Vec3<float>centerCol, Vec3<float>sizeCol, const std::string & mesh, std::string &name, float mass, ClippingZone* zone)
{
	//Creates node
	std::shared_ptr<StaticSceneNode> sceneNode = GraphicEngine::i().createStaticNode(posicion, rotacion, escala, mesh);
	sceneNode->setTransformationMatriz(posicion, rotacion, escala);


	PhysicsEntity *physicent = new PhysicsEntity(sceneNode, name, posicion, rotacion, escala);

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
	//	physicent->setCollisionGroup(col::Collisions::Caja);
		//physicent->setCollisionMask(col::cajaCollidesWith);
		physicent->getRigidBody()->setDamping(btScalar(0.f), btScalar(0.85f));
		physicent->getRigidBody()->setFriction(btScalar(0.8f));
		physicent->getRigidBody()->setAngularFactor(btScalar(0.3f));
	}
	zone->addEntity(physicent);

	return sceneNode;
}


Entity* MapLoader::createLifeObject(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{
	LifeObject *vidaEnt = new LifeObject(nullptr, "LifeObject");
	vidaEnt->getRenderState()->setPosition(posicion);
	vidaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(vidaEnt, Vec3<float>(3.f, 3.f, 3.f)));

	return vidaEnt;
}

Entity* MapLoader::createAsaltoDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{

	//Creates node
	AsaltoDrop *AsaltoDropEnt = new AsaltoDrop(nullptr, "AsaltoDrop");
	AsaltoDropEnt->getRenderState()->setPosition(posicion);
	AsaltoDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(AsaltoDropEnt, Vec3<float>(3.f, 3.f, 3.f)));

	return AsaltoDropEnt;
}

Entity* MapLoader::createPistolaDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{

	//Creates node
	PistolaDrop *pistolaEnt = new PistolaDrop(nullptr, "PistolaDrop");
	pistolaEnt->getRenderState()->setPosition(posicion);
	pistolaEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(pistolaEnt, Vec3<float>(3.f, 3.f, 3.f)));

	return pistolaEnt;
}

Entity* MapLoader::createRocektLauncherDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{
	//Creates node
	RocketLauncherDrop *RocketLauncherDropEnt = new RocketLauncherDrop(nullptr, "RocketDrop");
	RocketLauncherDropEnt->getRenderState()->setPosition(posicion);
	RocketLauncherDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(RocketLauncherDropEnt, Vec3<float>(3.f, 3.f, 3.f)));


	return RocketLauncherDropEnt;
}

Entity* MapLoader::createSniperDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh = "")
{
	//Creates node
	//std::shared_ptr<BasicSceneNode> sniper = CreateNodeExceptionSafe(posicion, escala, "", mesh);
	SniperDrop *SniperDropEnt = new SniperDrop(nullptr, "SniperDrop");
	SniperDropEnt->getRenderState()->setPosition(posicion);
	SniperDropEnt->setGhostObject(PhysicsEngine::i().createBoxGhostObject(SniperDropEnt, Vec3<float>(3.f, 3.f, 3.f)));
	//SniperDropEnt->setPosition(posicion);

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
