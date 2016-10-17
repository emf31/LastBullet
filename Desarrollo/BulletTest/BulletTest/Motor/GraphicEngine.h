#pragma once
#include "../Otros/vec3.hpp"
#include "SceneNode.h"
#include "irrlicht.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>



using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class GraphicEngine
{
public:
	
	~GraphicEngine();

	static GraphicEngine& i() {
		static GraphicEngine singleton;
		return singleton;
	}

	SceneNode* createNode(const Vec3<float> &TPosition, const Vec3<float> &TScale, const io::path& texture = "");


	
	void createCamera(Vec3<float> position, Vec3<float> target);
	void setCameraTarget(Vec3<float> target);
	void setCameraPosition(Vec3<float> position);
	
	void renderAll();

	void inicializar();

private:
	IrrlichtDevice *irrDevice;
	IVideoDriver *irrDriver;
	ISceneManager *irrScene;
	IGUIEnvironment *irrGUI;

	ICameraSceneNode *Camera;

	//std::unordered_map<int, SceneNode*> m_sceneNodes;
	GraphicEngine();
};

