#pragma once
#include "TEntity.h"
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp>
class TSpotLight : public TEntity {
public:
	TSpotLight();
	~TSpotLight();
	void setColor(int r, int g, int b, int a);
	void setColor(int r, int g, int b);
	void setLight();
	void setLightPosition(glm::vec3 pos) {
		lightPos=pos;
	}
	void pruebaColores() {

	}

	void beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual);
	void endDraw(glm::mat4& matrizActual);
	int m_r, m_g, m_b, m_a;

private:
	glm::vec3 lightPos;
	glm::mat4 m_matrix;
	Shader* shaderLuz;
	GLuint lightVAO;
	GLuint lightVBO;
	
	
};

