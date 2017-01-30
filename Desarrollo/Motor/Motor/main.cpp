
#include <iostream>
using namespace std;
#include "EngineDevice.h"

#include "Shader.h"
#include "Camera.h"
#include "TModel.h"

#include <GUI.h>

#include "Billboard.h"

GLuint screenWidth = 1280, screenHeight = 720;
EngineDevice engine;

int main() {
	if (!engine.createEngineDevice(screenWidth, screenHeight, u8"Motor gráfico / Visor OpenGL - Last Bullet")) {
		return -1;
	}
	SceneManager *sm = engine.getSceneManager();
	
	/*Shader billboardShader("assets/billboard_shader.vs", "assets/model_loading.frag");
	TNode *billNode = sm->addMesh(sm->getMesh("assets/billboard.obj", &billboardShader));
	billNode->setPosition(Vec3<float>(0.0f, 3.0f, 0.0f));*/

	TNode* n = sm->addMesh(sm->getMesh("assets/contenedor.obj"));
	n->setPosition(Vec3<float>(0.0f, -1.75f, 0.0f));
	n->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));

	TNode* m = sm->addMesh(sm->getMesh("assets/cartel.obj"));
	m->setPosition(Vec3<float>(5.f, -1.75f, 0.0f));
	m->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));

	TNode* w = sm->addMesh(sm->getMesh("assets/nanosuit.obj"));
	w->setPosition(Vec3<float>(10.f, -1.75f, 0.0f));
	w->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	
	//Billboard billboard(billNode);

	while (!engine.shouldCloseWindw()){
		engine.updateCurrentFrame();

		// FPS
		int fps = engine.getFPS();
		std::ostringstream title;
		title << u8"Motor gráfico / Visor OpenGL - Last Bullet FPS: " << fps;
		engine.setWindowTitle(title.str());
		
		engine.doMovement();
		
		sm->draw(engine.getWindow());
		
	}
	engine.end();
	return 0;
}




