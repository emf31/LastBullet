#pragma once

#include "TNode.h"
#include "ResourceManager.h"
#include "Shader.h"
//#include "Camera.h"
#include "enum.h"
#include "TSunLight.h"
#include "TPointLight.h"
#include "TFlashLight.h"
#include "TCamera.h"
#include <deque>

#include <GLEW/glew.h>
//GLFW
#include <GLFW/glfw.h>

class SceneManager {
public:

	static SceneManager& i() {
		static SceneManager singleton;
		return singleton;
	}
	void inicializar();

	//void getTexture(std::string path);
	TModel* getMesh(const std::string& path, Shader* shader=nullptr);
	void draw();
	void renderFrame(GLFWwindow* window);
	void inicializarBuffers();
	void renderLuces();

	bool removeNode(TNode* node);
	TModel* crearNodoMalla(TModel * model);
	TNode* crearNodoTransformacion(int entityID);
	TNode* crearNodoTraslacion(TNode* nodoPadre, int entityID);
	TNode* crearNodoRotacion(TNode* nodoPadre, int entityID);
	//NOTA : en mi cabeza tiene sentido que lo que devolvamos sea un TModel o un TSpotLight ya que luego desde el juego lo que manejariamos serian estas entities
	//lo cual a parte de ser mas claro para quien lo use asi no tendriamos acceso a los nodos del arbol desde fuera del motor grafico para que no se pueda corromper este.
	TNode* crearNodoEscalado(TNode* nodoPadre, int entityID);
	TSunLight* crearNodoSunLight(Vec3<float> direccion);
	TPointLight* crearNodoPointLight(Vec3<float> posicion);
	TFlashLight* crearNodoFlashLight(Vec3<float> posicion, Vec3<float> direccion, float radioIn = 13.0f, float radioEx = 18.0f);
	TCamera* crearNodoCamara();

	void setActiveCamera(TCamera* cam) { camaraActiva = cam; }

	void setSunLight(TSunLight* sun) { sunlight = sun; }

	int getEntityCount() { return nodeEntityCount; }

	void aumentaEntityCount() { nodeEntityCount++; }

	const Vec3<float>& getActiveCameraPos() { return activeCameraPos; }

	const glm::mat4& getProjectionMatrix() { return projection; }

	const glm::mat4& getViewMatrix() { return view; }

	glm::mat4& getMatrizActual() { return m_matrizActual; }

	void setMatrizActual(const glm::mat4& mat) { m_matrizActual = mat; }

	std::deque<glm::mat4>& getPilaMatrices() { return pilaMatrices; }

	TSunLight* getSunLight() { return sunlight; }
	
	int *screenWidth, *screenHeight;
	
	std::vector<TPointLight*> vecPointLight;
	std::vector<TFlashLight*> vecFlashLight;
	std::vector<TCamera*> vectorCamaras;
	TCamera* camaraActiva;

	Shader* shaderGeometria;
	Shader* shaderLuces;
	Shader* shaderBombillas;

	//Buffers
	GLuint gBuffer;
	GLuint gPosition, gNormal, gTextura, gSpecular, gCoords;
	GLuint rboDepth;
	GLuint draw_mode=1;

private:
	TNode* scene;

	int nodeEntityCount = 0;

	glm::mat4 projection;
	glm::mat4 view;
	glm::mat4 m_matrizActual;

	std::deque<glm::mat4> pilaMatrices;

	Vec3<float> activeCameraPos;

	TSunLight* sunlight;

	//Motor::GUI gui;

	void shutdown();

	GLuint quadVAO;

	GLuint quadVBO;

	void RenderQuad();


	friend class EngineDevice;
	
};
