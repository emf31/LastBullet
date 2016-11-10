#include "SceneManager.h"



SceneManager::SceneManager() {
}


SceneManager::~SceneManager() {
}

TModel* SceneManager::getMesh(std::string path,std::string shader) {
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
	scene.draw();
}
