
#include <iostream>
using namespace std;


#include "EngineDevice.h"
#include "ResourceManager.h"

#include "Shader.h"
#include "TCamera.h"
#include "TModel.h"
#include "TSpotLight.h"

#include <GUI.h>
#include "Billboard.h"

#include <SPARK/SPARK.h>
#include <SPARK/SPARK_GL.h>



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

	//pistola

	/*Texture* tex = ResourceManager::i().getTexture("res/explosion.bmp", , "texture_diffuse");

	//vector<Texture> normalMaps = this->loadMaterialTextures(material, aiTextureType_NORMALS, "texture_normal");

	// Loads particle texture
	GLuint textureParticle;
	if (!loadTexture(textureParticle, "res/explosion.bmp", GL_LUMINANCE, GL_CLAMP, true))
	{
	}//	return 1;*/
	
	
	TModel* p = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	/*
	TModel* p1 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p2 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p3= sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p4 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p5 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p6 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p7 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p8 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p9 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	*/

	
	//n->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
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
		//w->setRotation(rot);
		//std::cout << "roto al personaje en X con angulo: " << sm.camaraActiva->rotX << std::endl;
		//std::cout << "roto al personaje en Y con angulo: " << sm.camaraActiva->rotY << std::endl;
		//w->setRotationY(sm.camaraActiva->rotY);
		//w->setRotationY(sm.camaraActiva->rotX);
		//aux = w->getRotation();
		//std::cout << "La rotacion es: " << aux.getX() << "," << aux.getY() << "," << aux.getZ() << "," << std::endl;
		
		//w->setRotationY(sm.camaraActiva->aumentoenX);
		if (tiempoCamara == 300) {
			tiempoCamara = 0;
			if (contCam >= sm.vectorCamaras.size()) {
				contCam = 0;
			}
			//std::cout << "CAMBIO DE CAMARA!!!!" << std::endl;
			sm.setActiveCamera(sm.vectorCamaras[contCam]);
			contCam++;
		}
		if (cont == 100) {
			cont = 0;
			aux = w->getPosition();
			//std::cout << "La posicion es: " << aux.getX() << "," << aux.getY() << "," << aux.getZ() << "," << std::endl;
			//w->updatePosition(Vec3<float>(1.5f, 0.0f, 0.0f));
			
		}
		cont++;
		tiempoCamara++;
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
		//std::cout << "siguiente iteracion" << std::endl;
		
		
		
	}
	engine.end();
	return 0;
}




