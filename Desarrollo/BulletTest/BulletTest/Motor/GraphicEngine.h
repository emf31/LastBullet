#pragma once
#include <vec3.hpp>
#include <Color4f.h>
#include "BasicSceneNode.h"
#include "AnimatedSceneNode.h"
#include <StaticSceneNode.h>
#include "Camera.h"


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <Vec2f.h>

#include "DebugDraw.h"

#include <GUI.h>
#include <windows.h>
#include <Engine/EngineDevice.h>

#include <AssetsReader.h>




class GraphicEngine
{
public:

	static GraphicEngine& i() {
		static GraphicEngine singleton;
		return singleton;
	}

	std::shared_ptr<BasicSceneNode> createNode(const Vec3<float> &TPosition, const Vec3<float> &TScale, const std::string& texture = "", const std::string& mesh = "");
	std::shared_ptr<AnimatedSceneNode> createAnimatedNode(const std::string& directory, int numFrames);
	std::shared_ptr<StaticSceneNode> createStaticNode(const Vec3<float> &TPosition, const Vec3<float>& TRotation, const Vec3<float> &TScale, const std::string& mesh = "");
	//std::shared_ptr<SceneNode> createBillboard(std::shared_ptr<SceneNode>, const Vec2f& vector2d, const Vec3<float>& relPosition, const Color4f& color);
	//std::shared_ptr<SceneNode> createBillboardText(std::shared_ptr<SceneNode>, const std::string& text, const Vec2f& vector2d, const Vec3<float>& relPosition, const Color4f& color);

	const wchar_t * GetWC(const char *c);
	
	//Metodos de la camara
	Camera* createCamera(const std::string &name, Vec3<float> position, Vec3<float> target);
	void updateCamera();
	Camera* getActiveCamera();
	
	//Metodos de las luces
	bool createPointLight(Vec3<float> pos, Vec3<float> color);
	bool createDirectionalLight(Vec3<float> pos, Vec3<float> direccion, Vec3<float> color);

	//No hace nada aun
	void setActiveCamera(const std::string &nameCamera);
	void setTargetActiveCamera(const Vec3<float> target);

	
	void renderAll();
	void inicializar();
	bool isWindowActive();
	bool apagar();

	void cargarTexturas();
	void removeNode(std::shared_ptr<SceneNode> nodo);
	void toggleDebug() { debug_draw_bullet = !debug_draw_bullet; }

	void toggleCamera() { debug_camera = !debug_camera; }


	void enableMouse(bool enable) { engine.enableMouse(enable); }

	void setDebugDraw();

	void apuntar();
	void restablecerMirilla();

	void updateClippingPlanes();

	void updateDeathCamera();

	void cleanScreen();


	float planes[6][4] = {
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
	};

	EngineDevice& getDevice() { return engine; }

	bool exit;
private:

	int screenWidth, screenHeight;

	EngineDevice engine;
	SceneManager& sm;

	int lastFPS;

	std::string camaraActual = "";

	std::unordered_map<std::string, Camera*> cameras;

	Camera *active_camera;

	bool debug_draw_bullet;
	bool debug_camera;
	bool handleInput;


	DebugDraw* debugDraw;

	GraphicEngine();

	AssetsReader reader;
	

	

};

