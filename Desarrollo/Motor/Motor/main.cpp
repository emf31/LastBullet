
#include <iostream>
using namespace std;


#include "EngineDevice.h"
#include "ResourceManager.h"

#include "Shader.h"
#include "TCamera.h"
#include "TModel.h"
#include "TSunLight.h"
#include "Billboard.h"

//#include <SPARK/SPARK.h>
//#include <SPARK/SPARK_GL.h>


GLuint screenWidth = 1280, screenHeight = 720;
EngineDevice engine;

void inicialize() {
	SceneManager::i().setActiveCamera(SceneManager::i().crearNodoCamara());
	//window
	TModelEstatico* window2 = SceneManager::i().crearNodoMallaEstatica(SceneManager::i().getMesh("assets/WindowTest.obj"));
	TModel* window = SceneManager::i().crearNodoMalla(SceneManager::i().getMesh("assets/WindowTest.obj"));

	window->setPosition(Vec3<float>(5, 0, 0));
	window->setRotationXYZ(Vec3<float>(0,0,0));
	window2->setTransformMatrix(Vec3<float>(25, 0, 0), Vec3<float>(0, 0, 0), Vec3<float>(1, 1, 1));


	SceneManager &sm = SceneManager::i();


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


	//personaje
	TModel* origen = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	origen->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	origen->setPosition(Vec3<float>(20.0f, 5.0f, 0.0f));
	origen->setModelColor(1.0f,0.2f,0.2f);
	//personaje
	TModel* l1 = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	l1->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	l1->setPosition(Vec3<float>(-7.0f, 4.0f, -3.0f));
	//l1->setRotationXYZ(Vec3<float>(90.0f, 0.0f, 0.0f));

	TModel* l2 = sm.crearNodoMalla(sm.getMesh("assets/nanosuit.obj"));
	l2->setScale(Vec3<float>(0.3f, 0.3f, 0.3f));
	l2->setPosition(Vec3<float>(-10.0f, 2.0f, 3.0f));

	//*******LUCES*******
	//sol
	TSunLight* sol = SceneManager::i().crearNodoSunLight(Vec3<float>(0.0f, 0.0f, 0.0f));
	sol->setIntensidadAmbiente(0.5);
	sol->setPosition(Vec3<float>(-20.0f, 5.0f, -5.0f));
	sol->setVectorDireccion(Vec3<float>(0.0f, 0.0f, 0.0f));
	SceneManager::i().setSunLight(sol);

	//linterna
	TFlashLight* flash = sm.crearNodoFlashLight(Vec3<float>(8.0f, 5.0f, 4.0f), Vec3<float>(90.0f, 45.0f, 0.0f));
	flash->setColor(0.0f, 1.0f, 0.0f);
	//linterna
	TFlashLight* flash1 = sm.crearNodoFlashLight(Vec3<float>(8.0f, 5.0f, 4.0f), Vec3<float>(0.0f, 90.0f, 0.0f));
	flash1->setColor(1.0f, 1.0f, 1.0f);
	//linterna
	TFlashLight* flash2 = sm.crearNodoFlashLight(Vec3<float>(8.0f, 5.0f, 4.0f), Vec3<float>(0.0f, 180.0f, 0.0f));
	flash2->setColor(0.0f, 0.0f, 1.0f);
	//linterna
	TFlashLight* flash3 = sm.crearNodoFlashLight(Vec3<float>(8.0f, 5.0f, 4.0f), Vec3<float>(-45.0f, 270.0f, 0.0f));
	flash3->setColor(1.0f, 1.0f, 1.0f);
	flash->setIntensidadAmbiente(0.8f);

	//bombilla

	TPointLight* luz = sm.crearNodoPointLight(Vec3<float>(0.0f, 3.0f, 2.0f));
	luz->setColor(1.0f, 0.5f, 1.f);
	TPointLight* luz2 = sm.crearNodoPointLight(Vec3<float>(5.0f, 4.0f, -4.0f), 100.0f, 150.0f);
	luz2->setColor(0.0f, 1.f, 0.5f);
	TPointLight* luz3 = sm.crearNodoPointLight(Vec3<float>(7.0f, 2.0f, 1.0f));
	luz3->setColor(1.0f, 0.3f, 0.3f);
	luz3->setIntensidadAmbiente(0.5f);

}

int main() {
	if (!engine.createEngineDevice(screenWidth, screenHeight, u8"Motor gráfico / Visor OpenGL - Last Bullet")) {
		return -1;
	}
	SceneManager &sm = SceneManager::i();


	sm.inicializarBuffers();
	std::cout << "Esperar mientras la pantalla esta en blanco (se estan cargando modelos, animaciones, texturas,etc)--" << std::endl;
	//*******MODELOS***********
	inicialize();
	
	//pistola
	TModel* p1 = sm.crearNodoMalla(sm.getMesh("assets/pistolaTexturizada.obj"));
	p1->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
	//animacion
	int velocidadAnim = 10;
	std::cout << "Cargando animaciones..." << std::endl;
	TAnimation* pruebaAnim = sm.crearNodoAnimacion(ResourceManager::i().getAnimationMesh("assets/personaje4", 192));
	pruebaAnim->setScale(Vec3<float>(0.02f, 0.02f, 0.02f));
	pruebaAnim->setPosition(Vec3<float>(-3.0f, 0.0f, 5.0f));
	pruebaAnim->setFrameTime(milliseconds(velocidadAnim));
	pruebaAnim->setAnimation("idle", 0, 34, true);
	pruebaAnim->setAnimation("saltar", 40, 109, true);
	pruebaAnim->setAnimation("correr", 110, 190, true);
	pruebaAnim->setCurrentAnimation("idle");


	Vec3<float> vecDir = Vec3<float>(0.0f, 0.0f, -1.0f);
	Vec3<float> newPos;


	Vec3<float> newPos2 = Vec3<float>(50.0f, 20.0f, 10.0f);
	newPos2.normalise();
	sm.setActiveCamera(sm.crearNodoCamara());
	

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "*****************Instrucciones :*****************************" << std::endl;
	std::cout << "Mover camara: WASD" << std::endl;
	std::cout << "Activar animacion Idle : X" << std::endl;
	std::cout << "Activar animacion Correr: C" << std::endl;
	std::cout << "Activar animacion Saltar: Z" << std::endl;
	std::cout << "Aumentar velocidad animaciones : R" << std::endl;
	std::cout << "Disminuir velocidad de animaciones : L" << std::endl;
	std::cout << "Activar modos de color : 1-8" << std::endl;
	std::cout << "Aumentar bias (para sombras): M" << std::endl;
	std::cout << "Disminuir bias (para sombras): N" << std::endl;
	std::cout << "Activar sombras dinamicas : H" << std::endl;
	std::cout << "Activar sombras estaticas : J" << std::endl;
	std::cout << "Desactivar todas las sombras : K" << std::endl;
	std::cout << "Crear Billboard animado en pos (0,0,10) : G" << std::endl;

	

	while (!engine.shouldCloseWindw()) {


		engine.updateCurrentFrame();

		// FPS
		int fps = engine.getFPS();
		std::ostringstream title;
		title << u8"Motor gráfico / Visor OpenGL - Last Bullet FPS: " << fps;
		engine.setWindowTitle(title.str());

		engine.doMovement();

		
		if (Input::i().keyReleased(GLFW_KEY_1)) {
			std::cout << "Modo de color : Color Final" << std::endl;
			sm.draw_mode = 1;
		}
		else if (Input::i().keyReleased(GLFW_KEY_2)) {
			std::cout << "Modo de color : Posicion" << std::endl;
			sm.draw_mode = 2;
		}
		else if (Input::i().keyReleased(GLFW_KEY_3)) {
			std::cout << "Modo de color : Normales" << std::endl;
			sm.draw_mode = 3;
		}
		else if (Input::i().keyReleased(GLFW_KEY_4)) {
			std::cout << "Modo de color : Difuso" << std::endl;
			sm.draw_mode = 4;
		}
		else if (Input::i().keyReleased(GLFW_KEY_5)) {
			std::cout << "Modo de color : Especular " << std::endl;
			sm.draw_mode = 5;
		}
		else if (Input::i().keyReleased(GLFW_KEY_6)) {
			std::cout << "Modo de color : Model Color" << std::endl;
			sm.draw_mode = 6;
		}
		else if (Input::i().keyReleased(GLFW_KEY_7)) {
			std::cout << "Modo de color : Emisivo" << std::endl;
			sm.draw_mode = 7;
		}
		else if (Input::i().keyReleased(GLFW_KEY_8)) {
			std::cout << "Modo de color : Bloom " << std::endl;
			sm.draw_mode = 8;
		}
		else if (Input::i().keyReleased(GLFW_KEY_9)) {
			std::cout << "Modo de color : Zbuffer luz " << std::endl;
			sm.draw_mode = 9;
		}

		else if (Input::i().keyReleased(GLFW_KEY_Z)) {
			pruebaAnim->setCurrentAnimation("saltar");
		}
		else if (Input::i().keyReleased(GLFW_KEY_C)) {
			pruebaAnim->setCurrentAnimation("correr");
		}
		else if (Input::i().keyReleased(GLFW_KEY_X)) {
			pruebaAnim->setCurrentAnimation("idle");
		}
		else if (Input::i().keyReleased(GLFW_KEY_R)) {
			std::cout << "Aumento velocidad animacion" << std::endl;
			velocidadAnim = (velocidadAnim - 5 > 0 ? velocidadAnim - 5 : 1);
			pruebaAnim->setFrameTime(milliseconds(velocidadAnim));

		}
		else if (Input::i().keyReleased(GLFW_KEY_L)) {
			std::cout << "Disminuyo velocidad animacion" << std::endl;
			velocidadAnim = (velocidadAnim + 5 < 1000 ? velocidadAnim + 5 : 1000);
			pruebaAnim->setFrameTime(milliseconds(velocidadAnim));
		}

		else if (Input::i().keyPressed(GLFW_KEY_P)) {
			engine.toggleWindowMode();
		}
		else if (Input::i().keyPressed(GLFW_KEY_N)) {
			sm.bias -= 0.0001f;
			std::cout << "disminuyo bias, bias = " << sm.bias << std::endl;

		}
		else if (Input::i().keyPressed(GLFW_KEY_M)) {
			sm.bias += 0.0001f;
			std::cout << "aumento bias, bias = " << sm.bias << std::endl;

		}
		else if (Input::i().keyReleased(GLFW_KEY_G)) {
			std::cout << "creo bildboard en: 0.0f, 0.0f, 10.0f " << std::endl;
			TBillboard* b = sm.crearBillBoard(Vec3<float>(0.0f, 0.0f, 10.0f));
			b->setScale(Vec3<float>(5.0f, 5.0f, 5.0f));
		}
		else if (Input::i().keyReleased(GLFW_KEY_H)) {
			std::cout << "Activo Sombras Dinamicas" << std::endl;
			sm.activeDynamicShadow(true);
			sm.activeStaticShadow(false);
		}
		else if (Input::i().keyPressed(GLFW_KEY_J)) {
			std::cout << "Activo Sombras Estaticas " << std::endl;
			sm.activeStaticShadow(true);
			sm.activeDynamicShadow(false);
		}else if (Input::i().keyPressed(GLFW_KEY_K)) {
			std::cout << "Desactivo Sombras " << std::endl;
			sm.activeDynamicShadow(false);
			sm.activeStaticShadow(false);
		}
		Input::i().endEventProcess();

		

		vecDir = sm.camaraActiva->getVectorDireccion();
		newPos = vecDir *0.3f;
		p1->setPosition(sm.camaraActiva->getPosition());
		p1->updatePosition(newPos);

		sm.draw();
		glfwSwapBuffers(engine.getWindow());

	}
	engine.end();
	engine.shutdown();

	return 0;
}