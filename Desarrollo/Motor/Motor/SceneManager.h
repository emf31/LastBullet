#pragma once

#include "TNode.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "TSunLight.h"
#include "TPointLight.h"
#include "TFlashLight.h"
#include "TCamera.h"
#include "TAnimation.h"
#include <deque>

#include <GLEW/glew.h>
//GLFW
#include <GLFW/glfw.h>

struct _LINE {
	glm::vec3 from;
	glm::vec3 to;

	_LINE(glm::vec3 f, glm::vec3 t) {
		from = f;
		to = t;
	}
};



class SceneManager {
public:

	static SceneManager& i() {
		static SceneManager singleton;
		return singleton;
	}


	//void getTexture(std::string path);
	TMeshGroup* getMesh(const std::string& path, Shader* shader=nullptr);
	void draw();
	void renderFrame(GLFWwindow* window);

	//inicializar buffers
	void inicializar();
	void inicializarBuffers();
	void inicializarBuffersSombras();
	void inicializarBuffersBlur();
	void inicializarBuffersLineas();

	//pasadas para un render
	void renderLuces();
	void renderBlur();
	void renderBloom();
	void renderSombras();

	//crear nodos
	bool removeNode(TNode* node);
	TModel* crearNodoMalla(TMeshGroup * mesh);
	TAnimation* crearNodoAnimacion(TAnimationGroupMesh * animGroup);
	TNode* crearNodoTransformacion(int entityID);
	TNode* crearNodoTraslacion(TNode* nodoPadre, int entityID);
	TNode* crearNodoRotacion(TNode* nodoPadre, int entityID);
	TNode* crearNodoEscalado(TNode* nodoPadre, int entityID);
	TSunLight* crearNodoSunLight(Vec3<float> direccion);
	TPointLight* crearNodoPointLight(Vec3<float> posicion, float radioIn = 6.3f, float radioEx = 10.3f);
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

	void setLineWidth(float width);

	void drawLine(glm::vec3 from, glm::vec3 to);

	void rellenaVertices();

	void drawAllLines();

	void clearLines();

	void ziZoom(float z);
	void zoomZout();

	void activeDynamicShadow(bool b);
	void activeStaticShadow(bool b);
	
	int *screenWidth, *screenHeight;
	
	std::vector<TPointLight*> vecPointLight;
	std::vector<TFlashLight*> vecFlashLight;
	std::vector<TCamera*> vectorCamaras;
	TCamera* camaraActiva;

	Shader* shaderGeometria;
	Shader* shaderLuces;
	Shader* shaderBombillas;
	Shader* shaderLineas;
	Shader* shaderBlur;
	Shader* shaderSombras;

	//Buffers
	GLuint gBuffer,gDeferred;
	GLuint gPosition, gNormal, gTextura,gTangent, gBitangent, gSpecular, gCoords, gEmisivo, gObjectColor;
	GLuint rboDepth;
	GLuint shadowMapDepthFBO, shadowMap;
	GLuint draw_mode=1;

	//Buffers Bloom
	GLuint bloomFBO[2];
	GLuint bloomBuffers[2];

	std::vector<GLfloat> vertices3;
	std::vector<GLuint> indices;
	GLuint LVAO,LVBO;
	int numLines;
	float bias = 0.00011;
	

private:

	TNode* scene;
	bool castShadow;
	bool castStaticShadow;
	

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

	GLuint SHADOW_WIDTH = 1280, SHADOW_HEIGHT = 720;
	GLuint SCREEN_WIDTH = 1280, SCREEN_HEIGHT = 720;
	friend class EngineDevice;


	

};
