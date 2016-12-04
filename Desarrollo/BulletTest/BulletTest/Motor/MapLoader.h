#pragma once

#include <iostream>
#include<fstream>
#include "../Otros/vec3.hpp"



class MapLoader
{
public:
	MapLoader() {
	}
	~MapLoader();
	void readMap(const std::string& name);
	void createPhysicEntity(Vec3<float>posicion, Vec3<float>escala, Vec3<float>rotacion, const io::path & mesh, std::string &name, float mass);



};