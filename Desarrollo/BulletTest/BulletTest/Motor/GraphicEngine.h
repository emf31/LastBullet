#pragma once
#include "../Otros/vec3.hpp"
#include "SceneNode.h"
#include "Camera.h"
#include "irrlicht.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "../DebugDraw.h"


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class GraphicEngine
{
public:
	bool iniciado = false;
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

	void cargarTexturas();
	void removeNode(SceneNode* nodo);
	void toggleDebug() {
		debug_draw_bullet = !debug_draw_bullet;
	}

	void toggleCamera() {
		debug_camera = !debug_camera;
	}

private:
	IrrlichtDevice *irrDevice;
	IVideoDriver *irrDriver;
	ISceneManager *irrScene;
	IGUIEnvironment *irrGUI;

	video::ITexture* images;

	int lastFPS;

	std::unordered_map<int, Camera*> cameras;
	int m_camera;
	Camera *active_camera;

	bool debug_draw_bullet;
	bool debug_camera;

	irr::video::SMaterial debugMat;

	DebugDraw *debugDraw;

	//std::unordered_map<int, SceneNode*> m_sceneNodes;
	GraphicEngine();
};

