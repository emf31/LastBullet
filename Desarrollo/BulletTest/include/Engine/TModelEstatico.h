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


class TModelEstatico : public TEntity {

public:

	TModelEstatico(TMeshGroup* meshGroup, Vec3<float> posicion , Vec3<float> rotacion, Vec3<float> escala);
	~TModelEstatico();

	void setTransformMatrix(Vec3<float> posicion, Vec3<float> rotacion, Vec3<float> escala);

	Vec3<float> getRotation();
	Vec3<float> getPosition();
	Vec3<float> getScale();
	glm::mat4 getMatrix();

	//Llamar a esto desencadena que todos los hijos de este TModel se borren
	virtual void removeEntity() override;


	void setModelColor(float r, float g, float b) {
		m_r = r;
		m_g = g;
		m_b = b;
	}




private:

	TTransform transformMatrix;
	void setPosition(Vec3<float> pos);
	void setRotationXYZ(Vec3<float> rot);
	void setScale(Vec3<float> esc);

	SceneManager &sm;

	virtual void beginDraw();
	virtual void beginDrawSombras();
	virtual void endDraw();

	
	TMeshGroup* m_meshGroup;

	float m_r;
	float m_g;
	float m_b;

	//necesitamos mantaner esto porque sino lo hacemos asi tendriamos que hacer los metodos setRotationMatrix, setTraslationMatrix... publicos y si lo hacemos publicos luego desde el juego 
	//el usuario podria llamarlos y eso es algo que no queremos, es decir, usamos la friendclass para poder hacer bien la interfaz y no darle el control total al usuario.
	friend class SceneManager;
};


