#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include "vec3.hpp"
#include "TTransform.h"


// GL Includes
#include <GLEW/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SOIL/SOIL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "TMeshGroup.h"

//class TNode;

class TModel : public TEntity {
	
public:
	/*  Funciones   */
	// Constructor, espera una ruta al recurso (y opcionalmente un shader).
	TModel(TMeshGroup* meshGroup);
	~TModel();


	



	void setPosition(Vec3<float> pos);
	void updatePosition(Vec3<float> pos);

	void setOrientation(Vec3<float> rot);
	void setRotationXYZ(Vec3<float> rot);
	void setRotation(Vec3<float> rot);
	void setRotationRadians(Vec3<float> rot);

	void setScale(Vec3<float> esc);
	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getScale();

	glm::mat4 getRotationMatrix();
	glm::mat4 getPositionMatrix();
	glm::mat4 getScaleMatrix();



	void setVisible(bool b) { visible = b; }
	bool isVisible() const { return visible; }


	void setModelColor(float r, float g, float b) {
		m_r = r;
		m_g = g;
		m_b = b;
	}

	

private:

	SceneManager &sm;


	void setTransformacionRotacion(TTransform* rot);
	void setTransformacionEscalado(TTransform* esc);
	void setTransformacionTraslacion(TTransform* tras);

	bool visible;

	virtual void beginDraw();

	virtual void endDraw();


	/*  Model Data  */
	TMeshGroup* m_meshGroup;

	TTransform* transRotacion;
	TTransform* transEscalado;
	TTransform* transTraslacion;
	
	float m_r;
	float m_g;
	float m_b;
	
	friend class SceneManager;
};


