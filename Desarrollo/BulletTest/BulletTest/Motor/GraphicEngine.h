#pragma once
#include <vec3.hpp>
#include <Color4f.h>
#include "BasicSceneNode.h"
#include "AnimatedSceneNode.h"
#include <BillboardSceneNode.h>
#include "Camera.h"

#include "irrlicht.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <Vec2f.h>

#include "DebugDraw.h"

#include <GUI.h>
using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


#define _IRR_WINDOWS_

#ifdef DEBUG
#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif
#else
#ifdef _IRR_WINDOWS_
//#pragma comment(lib, "IrrlichtStatic_RELEASE.lib")
//#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif
#endif



class GraphicEngine
{
public:
	bool iniciado = false;
	static GraphicEngine& i() {
		static GraphicEngine singleton;
		return singleton;
	}

	std::shared_ptr<BasicSceneNode> createNode(const Vec3<float> &TPosition, const Vec3<float> &TScale, const io::path& texture = "", const io::path& mesh = "");
	std::shared_ptr<AnimatedSceneNode> createAnimatedNode(const Vec3<float> &TPosition, const Vec3<float> &TScale, const io::path& mesh, const io::path& texture = "");

	std::shared_ptr<SceneNode> createBillboard(std::shared_ptr<SceneNode>, const Vec2f& vector2d, const Vec3<float>& relPosition, const Color4f& color);
	std::shared_ptr<SceneNode> createBillboardText(std::shared_ptr<SceneNode>, const std::string& text, const Vec2f& vector2d, const Vec3<float>& relPosition, const Color4f& color);

	const wchar_t * GetWC(const char *c);
	
	//Metodos de la camara
	void createCamera(Vec3<float> position, Vec3<float> target);
	void setCameraEntity(Entity* entity);
	void updateCamera();
	Camera* getActiveCamera();
	

	IGUIStaticText* vida;
	IGUIStaticText* ammo;
	IGUIStaticText* ammototal;
	IGUIStaticText* arma_actual;
	IGUIStaticText* balas;

	//No hace nada aun
	void setActiveCamera(int ID);

	
	void renderAll();
	void inicializar();
	bool isRuning();
	bool isWindowActive();
	bool apagar();

	void cargarTexturas();
	void removeNode(std::shared_ptr<SceneNode> nodo);
	void toggleDebug() {
		debug_draw_bullet = !debug_draw_bullet;
	}

	void toggleCamera() { debug_camera = !debug_camera; }

	void setDebugDraw();

	IrrlichtDevice* getDevice() { return irrDevice; }
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

	DebugDraw* debugDraw;

	GraphicEngine();

};

