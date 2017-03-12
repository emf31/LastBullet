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

	void setNearPlane(float near);

	void setFarPlane(float far);
	
	int *screenWidth, *screenHeight;
	
	std::vector<TPointLight*> vecPointLight;
	std::vector<TFlashLight*> vecFlashLight;
	std::vector<TCamera*> vectorCamaras;
	TCamera* camaraActiva;

	Shader* shaderGeometria;
	Shader* shaderLuces;
	Shader* shaderBombillas;
	Shader* shaderLineas;

	//Buffers
	GLuint gBuffer;
	GLuint gPosition, gNormal, gTextura, gSpecular, gCoords;
	GLuint rboDepth;
	GLuint draw_mode=1;

	std::vector<_LINE> LINES;
	std::vector<GLfloat> vertices3;
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;
	GLuint linesvao, linesvbo, linesebo;
	GLuint LVAO,LVBO;
	int indexI = 0;

	void inicializarBuffersLineas() {
		glGenVertexArrays(1, &LVAO);
		glGenBuffers(1, &LVBO);
		// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	}

	void drawLine(glm::vec3 from, glm::vec3 to) {
		LINES.push_back(_LINE(from, to));
		vertices3.push_back(from.x);
		vertices3.push_back(from.y);
		vertices3.push_back(from.z);
		indexI++;
		vertices3.push_back(to.x);
		vertices3.push_back(to.y);
		vertices3.push_back(to.z);
		indexI++;
		
	}

	void rellenaVertices() {
		//glDisable(GL_CULL_FACE);
		
		

		

		//for (std::vector<_LINE>::iterator it = LINES.begin(); it != LINES.end(); it++)
		//{
		//	_LINE l = *it;

		//	vertices3.push_back(l.from.x);
		//	vertices3.push_back(l.from.y);
		//	vertices3.push_back(l.from.z);

		//	vertices3.push_back(l.to.x);
		//	vertices3.push_back(l.to.y);
		//	vertices3.push_back(l.to.z);

		//	indices.push_back(indexI);
		//	indices.push_back(indexI + 1);
		//	indexI += 2;
		//}

		GLfloat vertices2[] = {
			0.0f, 0.0f, 0.0f, // Inicio  
			0.0f, 50.f, 0.0f, // Fin 

		};

		glBindVertexArray(LVAO);

		glBindBuffer(GL_ARRAY_BUFFER, LVBO);
		glBufferData(GL_ARRAY_BUFFER, vertices3.size(), &vertices3[0], GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

		glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

		///////

		//glBindVertexArray(linesvao);
		//// Cargamos datos en el VAO
		//glBindBuffer(GL_ARRAY_BUFFER, linesvbo);

		//glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &this->vertices[0], GL_STATIC_DRAW);

		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, linesebo);
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &this->indices[0], GL_STATIC_DRAW);
		//glBindVertexArray(0);
		/////

		/*
		glEnableVertexAttribArray(linesvao);
		//glVertexAttribPointer(linesvao, 3, GL_FLOAT, GL_FALSE, 0, (void*)&(vertices.at(0)));

		glm::mat4 mView = camaraActiva->GetViewMatrix();
		glm::mat4 modelView = mView * glm::mat4(1.0);
		glm::mat4 mProjection = getProjectionMatrix();
		glm::mat4 mvp = mProjection * modelView;
		glUniformMatrix4fv(glGetUniformLocation(shaderLineas->Program, "mvp"), 1, GL_FALSE, glm::value_ptr(mvp));

		glBindVertexArray(linesvao);
		glDrawArrays(GL_LINES, 0, indices[0]);

		LINES.clear();
		*/

	}

	void drawAllLines() {
		rellenaVertices();
		shaderLineas->Use();
		glLineWidth(5.f);
		const glm::mat4& view = getViewMatrix();
		const glm::mat4& projection = getProjectionMatrix();
		glm::mat4& model = glm::mat4();

		glm::mat4 modelview = projection * view * model;
		glUniformMatrix4fv(glGetUniformLocation(shaderLineas->Program, "mvp"), 1, GL_FALSE, glm::value_ptr(modelview));
		glBindVertexArray(LVAO);

		glDrawArrays(GL_LINES, 0, indexI);
		glBindVertexArray(0);

		
	}

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

	float nearPlane = 0.1f, farPlane = 100.0f;

	friend class EngineDevice;
	

};
