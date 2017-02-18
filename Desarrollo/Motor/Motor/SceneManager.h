#pragma once

#include "TNode.h"
#include "ResourceManager.h"
#include "Shader.h"
//#include "Camera.h"
#include "enum.h"
#include "TSpotLight.h"
#include "TCamera.h"

#include "GUI.h"
#include <deque>

#include <GLEW/glew.h>
//GLFW
#include <GLFW/glfw3.h>

class SceneManager {
public:

	static SceneManager& i() {
		static SceneManager singleton;
		return singleton;
	}
	void inicializar();

	//void getTexture(std::string path);
	TModel* getMesh(std::string path, Shader* shader=nullptr);
	void draw(GLFWwindow* window);
	TModel* crearNodoMalla(TModel * model);
	TNode* crearNodoTransformacion(int entityID);
	TNode* crearNodoTraslacion(TNode* nodoPadre, int entityID);
	TNode* crearNodoRotacion(TNode* nodoPadre, int entityID);
	//NOTA : en mi cabeza tiene sentido que lo que devolvamos sea un TModel o un TSpotLight ya que luego desde el juego lo que manejariamos serian estas entities
	//lo cual a parte de ser mas claro para quien lo use asi no tendriamos acceso a los nodos del arbol desde fuera del motor grafico para que no se pueda corromper este.
	TNode* crearNodoEscalado(TNode* nodoPadre, int entityID);
	TSpotLight* crearNodoLuz();
	TCamera* crearNodoCamara();
	int getEntityCount() {
		return nodeEntityCount;
	}
	void aumentaEntityCount() {
		nodeEntityCount++;
	}

	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 m_matrizActual;
	//Camera *camera_ptr;
	Vec3<float> activeCameraPos;
	float *screenWidth, *screenHeight;
	std::deque<glm::mat4> pilaMatrices;
	std::vector<TSpotLight*> vectorLuces;
	std::vector<TCamera*> vectorCamara;
	TCamera* camaraActiva;
private:
	ResourceManager *rm;
	TNode* scene;
	int nodeEntityCount = 0;

	//Motor::GUI gui;
	
};
