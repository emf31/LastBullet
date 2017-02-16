
#include <iostream>
using namespace std;
#include "EngineDevice.h"

#include "Shader.h"
#include "Camera.h"
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

	TModel* n = sm.crearNodoMalla(sm.getMesh("assets/contenedor.obj"));
	n->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
	n->setModelColor(0.33f, 0.42f, 0.18f);



	TModel* m = sm.crearNodoMalla(sm.getMesh("assets/cartel.obj"));
	m->setScale(Vec3<float>(0.2f, 0.2f, 0.2f));
	m->setPosition(Vec3<float>(0.f, 5.0f, 0.0f));
	m->setPosition(Vec3<float>(0.f, 5.0f, 0.0f));
	m->setModelColor(1.0f, 0.5f, 0.31f);



	TModel* w = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	w->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	w->setPosition(Vec3<float>(3.5f, 3.5f, 3.5f));
	w->setRotationY(90.f);
	w->setModelColor(0.8f, 0.0f, 0.61f);
	Vec3<float> aux = w->getRotation();

	TSpotLight* luz = sm.crearNodoLuz();
	luz->setPosition(Vec3<float>(3.0f, 5.0f, 2.0f));
	
	
	long int cont = 0;
	while (!engine.shouldCloseWindw()){
		engine.updateCurrentFrame();

		// FPS
		int fps = engine.getFPS();
		std::ostringstream title;
		title << u8"Motor gráfico / Visor OpenGL - Last Bullet FPS: " << fps;
		engine.setWindowTitle(title.str());
		
		engine.doMovement();

		if (cont == 100) {
			cont = 0;
			aux = w->getPosition();
			std::cout << "La posicion es: " << aux.getX() << "," << aux.getY() << "," << aux.getZ() << "," << std::endl;
			w->setPosition(Vec3<float>(1.5f, 0.0f, 0.0f));
			
		}
		cont++;
		/*
				if (cont == 100) {
			cont = 0;
			std::cout << "reseteo: "<< std::endl;
			rotacion = n->getRotation();
			rotacion.setY(rotacion.getY() + 0.01);
			n->setRotation(rotacion);
		}
		std::cout << cont << std::endl;
		cont++;

		if (engine.m_rotarDerecha) {
			rotacion = n->getRotation();
			rotacion.setY(rotacion.getY() + 0.1);
			n->setRotation(rotacion);
			std::cout << "La rotacion en el if es: " << rotacion.getX() << "," << rotacion.getY() << "," << rotacion.getZ() << "," << std::endl;
		}
		else {
			n->setRotation(Vec3<float>(1.f,1.f,1.f));
			std::cout << "La rotacion el else es: " << rotacion.getX() << "," << rotacion.getY() << "," << rotacion.getZ() << "," << std::endl;
		}
		
		if (engine.m_rotarIzquierda) {
			rotacion = n->getRotation();
			rotacion.setY(rotacion.getY() - 0.1);
			n->setRotation(rotacion);
		}
		else {
			n->setRotation(Vec3<float>(1.f, 1.f, 1.f));
		}
		*/
		
		sm.draw(engine.getWindow());
		std::cout << "siguiente iteracion" << std::endl;
		
		
	}
	engine.end();
	return 0;
}




