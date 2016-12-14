
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

	Motor::GUI gui;
	gui.init("GUI");
	gui.loadScheme("TaharezLook.scheme");
	gui.setFont("DejaVuSans-10");
	vec4f perc;
	perc.x = 0.5f;
	perc.y = 0.5f;
	perc.z = 0.1f;
	perc.w = 0.05f;

	vec4f perx;

	perx.x = 0.0f;
	perx.y = 0.0f;
	perx.z = 0.0f;
	perx.w = 0.0f;

	gui.createWidget("TaharezLook/Button",perc, perx, "Test");

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




