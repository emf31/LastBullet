#pragma once

#include <iostream>
#include<fstream>
#include <vec3.hpp>
#include <vector>
#include <TriggerRecordStruct.h>
#include <memory>
#include "../Motor/BasicSceneNode.h"

class MapLoader
{
public:
	MapLoader() {
	}
	~MapLoader();
	void readMap(const std::string& name);
	std::shared_ptr<BasicSceneNode> createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, Vec3<float>centerCol, Vec3<float>sizeCol, const io::path & mesh, std::string &name, float mass);
	void createLifeObject(Vec3<float>posicion, Vec3<float>escala, const io::path & mesh, std::string &name);
	void createAsaltoDrop(Vec3<float>posicion, Vec3<float>escala, const io::path & mesh, std::string &name);
	void createPistolaDrop(Vec3<float>posicion, Vec3<float>escala, const io::path & mesh, std::string &name);
	void createRocektLauncherDrop(Vec3<float>posicion, Vec3<float>escala, const io::path & mesh, std::string &name);
	void createTriggerButton(Vec3<float> posicion, float radio, EnumTriggerType type);

	std::vector<Vec3<float>> getSpawnPoints() const { return spawnPoints; } 

	std::vector<Vec3<float>> spawnPoints;

};