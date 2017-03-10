#pragma once

#include <iostream>
#include<fstream>
#include <vec3.hpp>
#include <vector>
#include <TriggerRecordStruct.h>
#include <memory>
#include <BasicSceneNode.h>
#include <Entity.h>

class MapLoader
{
public:
	MapLoader() {
	}
	~MapLoader();
	void readMap(const std::string& name);
	std::shared_ptr<BasicSceneNode> createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, Vec3<float>centerCol, Vec3<float>sizeCol, const std::string & mesh, std::string &name, float mass);
	static Entity* createLifeObject(Vec3<float>posicion, Vec3<float>escala, const std::string &name, const std::string & mesh );
	static Entity* createAsaltoDrop(Vec3<float>posicion, Vec3<float>escala, const std::string &name, const std::string & mesh);
	static Entity* createPistolaDrop(Vec3<float>posicion, Vec3<float>escala, const std::string &name, const std::string & mesh);
	static Entity* createRocektLauncherDrop(Vec3<float>posicion, Vec3<float>escala, const std::string &name, const std::string & mesh);
	static Entity* createSniperDrop(Vec3<float>posicion, Vec3<float>escala, const std::string &name, const std::string & mesh);
	void createTriggerButton(Vec3<float> posicion, float radio, EnumTriggerType type);

	std::vector<Vec3<float>> getSpawnPoints() const { return spawnPoints; } 

private:

	std::vector<Vec3<float>> spawnPoints;

};