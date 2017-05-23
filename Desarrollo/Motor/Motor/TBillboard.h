#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include "vec3.hpp"
#include "TTransform.h"
#include "Clock.hpp"


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

class TBillboard {

public:
	/*  Funciones   */
	// Constructor, espera una ruta al recurso (y opcionalmente un shader).
	TBillboard(TMeshGroup* meshGroup, Vec3<float> posicion);
	~TBillboard();
	void draw();
	bool isAlive();


private:


	glm::mat4 calcularMVP();
	void selectCurrentFrame();



	SceneManager &sm;

	/*  Model Data  */
	TMeshGroup* m_meshGroup;
	TTransform modelMatrix;
	glm::mat4 mvp;
	bool conVida;
	Time billBoardTimeFrame;
	Clock billboardCurrentTime;
	int frameBillboard;
	int numFrames;
};