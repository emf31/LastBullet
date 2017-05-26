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



class TBillboard {

public:

	TBillboard(TMeshGroup* meshGroup, Vec3<float> posicion);
	~TBillboard();
	void draw();
	bool isAlive();

	void setFrameTime(Time time) { billBoardTimeFrame = time; }
	void setScale(const Vec3<float>& scale) { m_scale = scale; }


private:


	glm::mat4 calcularMVP();
	void selectCurrentFrame();

	Vec3<float> m_scale;

	SceneManager &sm;

	
	TMeshGroup* m_meshGroup;
	TTransform modelMatrix;
	glm::mat4 mvp;
	bool conVida;
	Time billBoardTimeFrame;
	Clock billboardCurrentTime;
	int frameBillboard;
	int numFrames;
};