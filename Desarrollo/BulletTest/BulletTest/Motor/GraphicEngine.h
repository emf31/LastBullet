#pragma once
#include "../Otros/vec3.hpp"
#include "SceneNode.h"
#include "Camera.h"
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
	static GraphicEngine& i() {
		static GraphicEngine singleton;
		return singleton;
	}

	SceneNode* createNode(const Vec3<float> &TPosition, const Vec3<float> &TScale, const io::path& texture = "", const io::path& mesh = "");
	
	//Metodos de la camara
	void createCamera(Vec3<float> position, Vec3<float> target);
	void setCameraEntity(Entity* entity);
	void updateCamera();
	Camera* getActiveCamera();

	//No hace nada aun
	void setActiveCamera(int ID);

	
	void renderAll();
	void inicializar();
	bool isRuning();
	bool isWindowActive();
	bool apagar();

private:
	IrrlichtDevice *irrDevice;
	IVideoDriver *irrDriver;
	ISceneManager *irrScene;
	IGUIEnvironment *irrGUI;

	std::unordered_map<int, Camera*> cameras;
	int m_camera;
	Camera *active_camera;

	//std::unordered_map<int, SceneNode*> m_sceneNodes;
	GraphicEngine();
};

