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
	//node->sceneManager_ptr = this;
	node->setModel(model);
	scene.addChild(node);
	return node;

}

void SceneManager::draw(GLFWwindow* window) {
	//Clear
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Update matrices
	projection = glm::perspective(camera_ptr->Zoom, (float)*screenWidth / (float)*screenHeight, 0.1f, 100.0f);
	view = camera_ptr->GetViewMatrix();
	//Desencadena el dibujado de la escena
	scene.beginDraw(projection, view);

	glfwSwapBuffers(window);
}
