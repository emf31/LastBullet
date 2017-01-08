
#include <iostream>
using namespace std;
#include "EngineDevice.h"

#include "Shader.h"
#include "Camera.h"
#include "TModel.h"

#include "GUI.h"

GLuint screenWidth = 1280, screenHeight = 720;
EngineDevice engine;

int main() {
	if (!engine.createEngineDevice(screenWidth, screenHeight, u8"Motor gráfico / Visor OpenGL - Last Bullet")) {
		return -1;
	}
	SceneManager *sm = engine.getSceneManager();
	

	TNode* n = sm->addMesh(sm->getMesh("assets/nanosuit.obj"));
	n->setPosition(Vec3<float>(0.0f, -1.75f, 0.0f));
	n->setScale(Vec3<float>(0.2f, 0.2f, 0.2f));

	/*TNode* bike = sm->addMesh(sm->getMesh("assets/bike.FBX"));
	bike->setPosition(Vec3<float>(0.0f, -1.75f, 0.0f));
	bike->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));*/

	while (!engine.shouldCloseWindw()){
		engine.updateCurrentFrame();
		//FPS
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




