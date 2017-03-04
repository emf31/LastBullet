
#include <iostream>
using namespace std;


#include "EngineDevice.h"
#include "ResourceManager.h"

#include "Shader.h"
#include "TCamera.h"
#include "TModel.h"
#include "TSunLight.h"

#include <GUI.h>
#include "Billboard.h"

//#include <SPARK/SPARK.h>
//#include <SPARK/SPARK_GL.h>



GLuint screenWidth = 1280, screenHeight = 720;
EngineDevice engine;

int main() {
	if (!engine.createEngineDevice(screenWidth, screenHeight, u8"Motor gráfico / Visor OpenGL - Last Bullet")) {
		return -1;
	}
	SceneManager &sm = SceneManager::i();	
	
	//*******MODELOS***********

	//window
	TModel* window = sm.crearNodoMalla(sm.getMesh("assets/WindowTest.obj"));
	//p1->setScale(Vec3<float>(0.1, 0.1, 0.1));


	//pistola
	TModel* p1 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	p1->setScale(Vec3<float>(0.1, 0.1, 0.1));
	//sm.camaraActiva->addChild(p1);
	//p1->setPosition(Vec3<float>(0.0f, 0.0f, -10.0f));
	
	//contenedor
	TModel* n = sm.crearNodoMalla(sm.getMesh("assets/contenedor.obj"));
	n->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
	n->setPosition(Vec3<float>(3.0f, 2.0f, 3.0f));

	TModel* n2 = sm.crearNodoMalla(sm.getMesh("assets/contenedor.obj"));
	n2->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
	n2->setPosition(Vec3<float>(-3.0f, 0.0f, -3.0f));
	

	//cartel
	TModel* m = sm.crearNodoMalla(sm.getMesh("assets/cartel.obj"));
	m->setScale(Vec3<float>(0.2f, 0.2f, 0.2f));
	m->setPosition(Vec3<float>(0.f, 5.0f, 0.0f));
	//m->setModelColor(1.0f, 0.5f, 0.31f);


	//personaje
	TModel* origen = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	origen->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	origen->setPosition(Vec3<float>(4.0f, 0.0f, 0.0f));
	




	//*******LUCES*******

	//sol
	TSunLight* sol = sm.crearNodoSunLight(Vec3<float>(-0.8f, -3.0f, -0.8f));
	//sol->setIntensidadAmbiente(1.0f);
	//bombilla
	TPointLight* luz = sm.crearNodoPointLight(Vec3<float>(8.0f, 4.0f, 2.0f));
	TPointLight* luz2 = sm.crearNodoPointLight(Vec3<float>(10.0f, 4.0f, 2.0f));
	TPointLight* luz3 = sm.crearNodoPointLight(Vec3<float>(12.0f, 6.0f, 4.0f));
	//linterna
	TFlashLight* flash = sm.crearNodoFlashLight(Vec3<float>(-3.0f, 0.0f, 3.0f), Vec3<float>(0.0f, 0.0f, -1.0f));



	//*******CAMARAS*******
	//TCamera* cam2 = sm.crearNodoCamara();
	//sm.setActiveCamera(cam2);
	
	long int cont = 0;
	long int tiempoCamara = 0;
	int contCam = 0;
	Vec3<float> rot;
	Vec3<float> vecDir = Vec3<float>(0.0f, 0.0f, -1.0f);
	Vec3<float> newPos;



	sm.inicializarBuffers();

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



//NOTA PREGUNTAR PROFE: queremos que una malla en este caso la pistola sea hermana de la camara, es decir qeu dependa de sus transformaciones
//para que asi si desplazamos o rotamos la camara tambien lo haga la pistola, hay 3 problemas:
// 1- si ponemos la malla en exactamente la misma posicion que la camara esta no se ve, pero si desplazamos la malla un poco hacia delante para que se vea todo el rato
//el desplazamiento lo hace bien pero a la hora de rotar como estas rotando un objeto que esta trasladado ya no lo hace bien
//2-si escalamos la malla, por ejemplo la pistola el modelo es muy grande y hay que escalarlo a la hora de multiplicar la matriz actual que le llega con la posicion y rotacion 
// de la camara por su matriz de escalado entonces si escalamos 0.3 esta reduciendo no solo el tamaño sino toda la matriz de la transformacion asi si la camara se ha desplazado
//5 unidades por ejemplo el modelo pone que se habria desplazado 1.5 unidades que es el resultado de 0.3*5
//3- tendriamos que poder hacer las transformadas de la pistola antes que la camara pork asi la desplazamos en z para alejarla y dejarla en su posicion buena y luego cuando pongamos 
//la rotacion de la camra esta rotara un objeto trasladado quedando esta siempre en la buena posicion de la camara

//POSIBLE SOLUCION: hacer una nueva variable que sea posRealativa que sea una posicion relativa al padre que este en TModel, por defecto esta es 0, lo que haria esta posicion es en cada
//draw hacer un update position de este valor multiplicado por el vec dir de la camara y asi esta posicion se la pondriamos una vez solo al crear el objeto y ya el en el draw se encargaria
//de desplazarse relativo al padre segun la posicion que tu has dicho.


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