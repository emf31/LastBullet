#include "SceneManager.h"


SceneManager::SceneManager() {
	gui.init("GUI");
	//gui.loadScheme("VanillaSkin.scheme");
	gui.loadScheme("AlfiskoSkin.scheme");

	gui.loadLayout("SimpleDebug.layout");
	//gui.setFont("DejaVuSans-10");
	vec4f perc;
	perc.x = 0.5f;
	perc.y = 0.5f;
	perc.z = 0.1f;
	perc.w = 0.0001f;

	vec4f perx;

	perx.x = 0.0f;
	perx.y = 0.0f;
	perx.z = 0.0f;
	perx.w = 0.0f;

	//gui.createWidget("AlfiskoSkin/Button", perc, perx, "Test");
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
	gui.draw();
	glfwSwapBuffers(window);
	
}
