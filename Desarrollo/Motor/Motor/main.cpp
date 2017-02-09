
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


	/*
	TNode* m = sm->addMesh(sm->getMesh("assets/contenedor.obj"));
	n->setPosition(Vec3<float>(0.0f, -1.75f, 0.0f));
	n->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));


	TNode* m = sm->addMesh(sm->getMesh("assets/cartel.obj"));
	m->setPosition(Vec3<float>(5.f, -1.75f, 0.0f));
	m->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));

	TNode* w = sm->addMesh(sm->getMesh("assets/nanosuit.obj"));
	w->setPosition(Vec3<float>(10.f, -1.75f, 0.0f));
	w->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	*/

	TModel* n = sm->crearNodoMalla(sm->getMesh("assets/contenedor.obj"));
	TModel* m = sm->crearNodoMalla(sm->getMesh("assets/cartel.obj"));
	TModel* w = sm->crearNodoMalla(sm->getMesh("assets/nanosuit.obj"));
	w->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));

	Vec3<float> rotacion = n->getRotation();
	std::cout << "La rotacion Antes es: " << rotacion.getX()<<","<< rotacion.getY() << "," << rotacion.getZ() << "," << std::endl;
	rotacion.setY(rotacion.getY() + 10);
	std::cout << "La rotacion despues es: " << rotacion.getX() << "," << rotacion.getY() << "," << rotacion.getZ() << "," << std::endl;
	n->setRotation(rotacion);

	Vec3<float> posicion = w->getPosition();
	Vec3<float> rotacion2 = w->getRotation();
	std::cout << "La posicion Antes es: " << posicion.getX() << "," << posicion.getY() << "," << posicion.getZ() << "," << std::endl;
	posicion = posicion + Vec3<float>(3.5f, 3.5f, 3.5f);
	std::cout << "La posicion despues es: " << posicion.getX() << "," << posicion.getY() << "," << posicion.getZ() << "," << std::endl;
	std::cout << "La rotacion Antes es: " << rotacion2.getX() << "," << rotacion2.getY() << "," << rotacion2.getZ() << "," << std::endl;
	rotacion2.setY(rotacion2.getY() + 5);
	std::cout << "La rotacion despues es: " << rotacion2.getX() << "," << rotacion2.getY() << "," << rotacion2.getZ() << "," << std::endl;
	w->setPosition(posicion);
	w->setRotation(rotacion2);
	
	long int cont = 0;
	while (!engine.shouldCloseWindw()){
		engine.updateCurrentFrame();

		// FPS
		int fps = engine.getFPS();
		std::ostringstream title;
		title << u8"Motor gráfico / Visor OpenGL - Last Bullet FPS: " << fps;
		engine.setWindowTitle(title.str());
		
		engine.doMovement();

		if (cont == 50) {
			//w->setRotation(Vec3<float>(0.0f,1.0f,0.0f));
		}
		if (cont == 100) {
			cont = 0;
			posicion = w->getPosition();
			std::cout << "La posicion es: " << posicion.getX() << "," << posicion.getY() << "," << posicion.getZ() << "," << std::endl;
			posicion.setX(posicion.getX() + 0.5);
			w->setPosition(posicion);
			
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
		
		sm->draw(engine.getWindow());
		
	}
	engine.end();
	return 0;
}




