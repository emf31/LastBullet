
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
	
	
	//TModel* p = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	//sm.camaraActiva->addChild(p);
	TModel* p1 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	p1->setScale(Vec3<float>(0.1, 0.1, 0.1));
	/*
	TModel* p2 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p3= sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p4 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p5 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p6 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p7 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p8 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	TModel* p9 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	*/

	
	//contenedor
	TModel* n = sm.crearNodoMalla(sm.getMesh("assets/contenedor.obj"));
	n->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
	n->setPosition(Vec3<float>(3.0f, 2.0f, 3.0f));
	TModel* n2 = sm.crearNodoMalla(sm.getMesh("assets/contenedor.obj"));
	n2->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
	n2->setPosition(Vec3<float>(-3.0f, 0.0f, -3.0f));
	//n->setModelColor(0.33f, 0.42f, 0.18f);

	//cartel
	TModel* m = sm.crearNodoMalla(sm.getMesh("assets/cartel.obj"));
	m->setScale(Vec3<float>(0.2f, 0.2f, 0.2f));
	m->setPosition(Vec3<float>(0.f, 5.0f, 0.0f));
	//m->setPosition(Vec3<float>(0.f, 5.0f, 0.0f));
	//m->setModelColor(1.0f, 0.5f, 0.31f);


	//personaje
	TModel* origen = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	origen->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	origen->setPosition(Vec3<float>(4.0f, 0.0f, 0.0f));
	//w->setRotationY(0.0f);
	//origen->setModelColor(0.1f, 1.0f, 0.1f);
	//Vec3<float> aux = w->getRotation();

	//TModel* destino1 = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	//destino1->setScale(Vec3<float>(0.05f, 0.05f, 0.05f));
	//destino1->setPosition(Vec3<float>(0.0f, 0.0f, -1.0f));
	//w->setRotationY(0.0f);

	//TModel* destino2 = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	//destino2->setScale(Vec3<float>(0.05f, 0.05f, 0.05f));
	//destino2->setPosition(Vec3<float>(0.0f, 0.0f, 0.0f));
	//w->setRotationY(0.0f);

	Vec3<float> vecDir = Vec3<float>(0.0f, 0.0f, -1.0f);
	Vec3<float> newPos;


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
	//Vec3<float> posCam = sm.camaraActiva->getPosition();
	
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
	//sm.camaraActiva->setPosition(posCam);



	//NOTA PREGUNTAR PROFE: queremos que una malla en este caso la pistola sea hermana de la camara, es decir qeu dependa de sus transformaciones
	//para que asi si desplazamos o rotamos la camara tambien lo haga la pistola, hay 3 problemas:
	// 1- si ponemos la malla en exactamente la misma posicion que la camara esta no se ve, pero si desplazamos la malla un poco hacia delante para que se vea todo el rato
	//el desplazamiento lo hace bien pero a la hora de rotar como estas rotando un objeto que esta trasladado ya no lo hace bien
	//2-si escalamos la malla, por ejemplo la pistola el modelo es muy grande y hay que escalarlo a la hora de multiplicar la matriz actual que le llega con la posicion y rotacion 
	// de la camara por su matriz de escalado entonces si escalamos 0.3 esta reduciendo no solo el tamaño sino toda la matriz de la transformacion asi si la camara se ha desplazado
	//5 unidades por ejemplo el modelo pone que se habria desplazado 1.5 unidades que es el resultado de 0.3*5
	//3- habia un tercer problema que ahora mismo no me acuerdo que pasaba cuando hacias todo el rato el set position y set roation a mano directamente de la camara a la malla


	while (!engine.shouldCloseWindw()){
		engine.updateCurrentFrame();

		// FPS
		int fps = engine.getFPS();
		std::ostringstream title;
		title << u8"Motor gráfico / Visor OpenGL - Last Bullet FPS: " << fps;
		engine.setWindowTitle(title.str());
		
		engine.doMovement();

		vecDir = sm.camaraActiva->getVectorDireccion();
		newPos = vecDir *0.3;
		//p->setPosition(newPos);
		p1->setRotation(vecDir);
		p1->setPosition(sm.camaraActiva->getPosition());
		p1->updatePosition(newPos);
		
		//p->updatePosition(Vec3<float>(3.0f, 0.0f, 0.0f));
		//p->setPosition(Vec3<float>(0.0f, 0.0f, -10.0f));
		
		//newPos = vecDir * 2;
		//origen->setPosition(sm.camaraActiva->getPosition());
		//origen->setRotation(vecDir);
		//origen->updatePosition(newPos);
		//origen->updatePosition(Vec3<float>(0.0f, -5.0f, 0.0f));
		
		if (tiempoCamara == 300) {
			tiempoCamara = 0;
			if (contCam >= sm.vectorCamaras.size()) {
				contCam = 0;
			}
			//std::cout << "CAMBIO DE CAMARA!!!!" << std::endl;
			sm.setActiveCamera(sm.vectorCamaras[contCam]);
			contCam++;
		}

		cont++;
		tiempoCamara++;

		
		sm.draw(engine.getWindow());
		//std::cout << "siguiente iteracion" << std::endl;
		
		
		
	}
	engine.end();
	return 0;
}




