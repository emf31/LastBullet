
#include <iostream>
using namespace std;
#include "EngineDevice.h"

#include "Shader.h"
#include "TCamera.h"
#include "TModel.h"
#include "TSpotLight.h"

#include <GUI.h>

#include "Billboard.h"

GLuint screenWidth = 1280, screenHeight = 720;
EngineDevice engine;

int main() {
	if (!engine.createEngineDevice(screenWidth, screenHeight, u8"Motor gráfico / Visor OpenGL - Last Bullet")) {
		return -1;
	}
	SceneManager &sm = SceneManager::i();
	/*Shader billboardShader("assets/billboard_shader.vs", "assets/model_loading.frag");
	TNode *billNode = sm->addMesh(sm->getMesh("assets/billboard.obj", &billboardShader));
	billNode->setPosition(Vec3<float>(0.0f, 3.0f, 0.0f));*/

	//contenedor
	TModel* n = sm.crearNodoMalla(sm.getMesh("assets/contenedor.obj"));
	n->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
	//n->setModelColor(0.33f, 0.42f, 0.18f);

	//cartel
	TModel* m = sm.crearNodoMalla(sm.getMesh("assets/cartel.obj"));
	m->setScale(Vec3<float>(0.2f, 0.2f, 0.2f));
	m->setPosition(Vec3<float>(0.f, 5.0f, 0.0f));
	m->setPosition(Vec3<float>(0.f, 5.0f, 0.0f));
	//m->setModelColor(1.0f, 0.5f, 0.31f);


	//personaje
	TModel* w = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	w->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	w->setPosition(Vec3<float>(0.0f, 3.0f, 0.0f));
	//w->setRotationY(0.0f);
	//w->setModelColor(0.8f, 0.0f, 0.61f);
	Vec3<float> aux = w->getRotation();
	


	//luces
	//TSpotLight* luz = sm.crearNodoLuz();
	//luz->setPosition(Vec3<float>(3.0f, 5.0f, 2.0f));

	TSpotLight* luz2 = sm.crearNodoLuz();
	luz2->setPosition(Vec3<float>(8.0f, 4.0f, 2.0f));
	//luz->setColor(1.0f, 0.9f, 0.9f);
	
	//poner luz como hijo del personaje
	//w->addChild(luz);

	//camaras
	//TCamera* cam1 = sm.crearNodoCamara();
	//TCamera* cam2 = sm.crearNodoCamara();
	Vec3<float> posCam = sm.camaraActiva->getPosition();
	sm.camaraActiva->addChild(w);
	//posCam.setX(posCam.getX() + 1);
	//posCam.setY(posCam.getY() + 4);

	//cam2->setPosition(posCam);
	//pongo la camara 2 como hijo del modelo
	//w->addChild(cam2);
	//sm.setActiveCamera(cam2);
	
	long int cont = 0;
	long int tiempoCamara = 0;
	int contCam = 0;
	Vec3<float> rot;
	sm.camaraActiva->setPosition(posCam);
	while (!engine.shouldCloseWindw()){
		engine.updateCurrentFrame();

		// FPS
		int fps = engine.getFPS();
		std::ostringstream title;
		title << u8"Motor gráfico / Visor OpenGL - Last Bullet FPS: " << fps;
		engine.setWindowTitle(title.str());
		
		engine.doMovement();
		rot=sm.camaraActiva->vecFrontCam();
		w->setRotation(rot);

		if (tiempoCamara == 300) {
			tiempoCamara = 0;
			if (contCam >= sm.vectorCamaras.size()) {
				contCam = 0;
			}

			sm.setActiveCamera(sm.vectorCamaras[contCam]);
			contCam++;
		}
		if (cont == 100) {
			cont = 0;
			aux = w->getPosition();

			
		}
		cont++;
		tiempoCamara++;
		
		sm.draw(engine.getWindow());
		
	}
	engine.end();
	return 0;
}




