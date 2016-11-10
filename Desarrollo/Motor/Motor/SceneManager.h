#pragma once
#include "TNode.h"
#include "ResourceManager.h"
#include "Shader.h"
class SceneManager {
public:
	SceneManager();
	~SceneManager();

	void getTexture(std::string path);
	TModel* getMesh(std::string path, std::string shader="");
	TNode* addMesh(TModel* model);

	void draw();
private:
	ResourceManager *rm;
	TNode scene;
};

