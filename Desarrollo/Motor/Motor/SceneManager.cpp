#include "SceneManager.h"



SceneManager::SceneManager() {
	rm = new ResourceManager();
}


SceneManager::~SceneManager() {
}

TModel* SceneManager::getMesh(std::string path) {
	if (path != "") {
		return rm->getMesh(path);
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
	scene.draw();
}
