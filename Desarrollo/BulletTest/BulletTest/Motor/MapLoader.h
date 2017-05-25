#pragma once

#include <iostream>
#include<fstream>
#include <vec3.hpp>
#include <vector>
#include <TriggerRecordStruct.h>
#include <memory>
#include <BasicSceneNode.h>
#include <Entity.h>
#include "../json/json.hpp"

#include <StaticSceneNode.h>

class ClippingZone;

class Object
{
public:
	Object() { }
	~Object() {};
	Vec3<float> pos;
	Vec3<float> rot;
	Vec3<float> es;
	Vec3<float> centerCollider;
	Vec3<float> sizeColllider;
	float mass;
	std::string nameMesh;
	std::string mesh;

	std::string extraTags;
};



class MapLoader
{
public:
	MapLoader() { }
	~MapLoader();
	void readMap(const std::string& name);

	static Entity* createLifeObject(Vec3<float>posicion, Vec3<float>escala, const std::string & mesh);
	static Entity* createAsaltoDrop(Vec3<float>posicion, Vec3<float>escala, const std::string & mesh);
	static Entity* createPistolaDrop(Vec3<float>posicion, Vec3<float>escala, const std::string & mesh);
	static Entity* createRocektLauncherDrop(Vec3<float> posicion, Vec3<float> escala, const std::string & mesh);
	static Entity* createSniperDrop(Vec3<float>posicion, Vec3<float>escala, const std::string & mesh);
	

	std::vector<Vec3<float>> getSpawnPoints() const { return spawnPoints; } 

private:
	static std::shared_ptr<BasicSceneNode> CreateNodeExceptionSafe(const Vec3<float>& TPosition, const Vec3<float>& TScale, const std::string & texture, const std::string & mesh);

	std::shared_ptr<StaticSceneNode> createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, Vec3<float>centerCol, Vec3<float>sizeCol, const std::string & mesh, std::string &name, float mass, ClippingZone* zone);
	
	void createTriggerButton(Vec3<float> posicion, float radio, EnumTriggerType type);

	void UnityCoordsToOpenGL(Vec3<float>& pos, Vec3<float>& rot, Vec3<float>& scale);

	Object* createObject(nlohmann::json& obj);

	

	std::vector<Vec3<float>> spawnPoints;

};

