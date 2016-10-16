#pragma once
#include "../Otros/vec3.hpp"
#include "irrlicht.h"
#include <iostream>
#include <string>
#include <vector>



using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class Grafic3dEngine
{
public:
	Grafic3dEngine();
	~Grafic3dEngine();

	static Grafic3dEngine& i() {
		static Grafic3dEngine singleton;
		return singleton;
	}

	int createNode(const Vec3<float> &TPosition, const Vec3<float> &TScale);
	void setTexture(int ID,int num, const io::path& texture);
	void createCamera(Vec3<float> position, Vec3<float> target);
	void setCameraTarget(Vec3<float> target);
	void setCameraPosition(Vec3<float> position);
	void setNodePosition(int ID,Vec3<float> position);
	void renderAll();

private:
	IrrlichtDevice *irrDevice;
	IVideoDriver *irrDriver;
	ISceneManager *irrScene;
	IGUIEnvironment *irrGUI;

	ICameraSceneNode *Camera;

	std::vector<ISceneNode*> nodes;

};

