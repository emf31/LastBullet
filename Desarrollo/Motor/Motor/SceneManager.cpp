#include "SceneManager.h"



SceneManager::SceneManager() {
}


SceneManager::~SceneManager() {
}

TModel* SceneManager::getMesh(std::string path,Shader* shader) {
	if (path != "") {
		return ResourceManager::i().getMesh(path,shader);
	}
	return NULL;
}

TNode* SceneManager::addMesh(TModel * model) {

	TNode *node = new TNode();
	node->setEntity((TEntity*)model);
	scene.addChild(node);
	return node;

}

void SceneManager::draw() {
	//Update matrices
	/*glm::mat4 projection = glm::perspective(engine.camera.Zoom, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
	glm::mat4 view = engine.camera.GetViewMatrix();*/
	scene.draw();
}
