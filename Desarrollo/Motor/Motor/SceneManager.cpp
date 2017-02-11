#include "SceneManager.h"
#include "TTransform.h"


SceneManager::SceneManager() {
	//gui.init("GUI");
	//gui.loadScheme("VanillaSkin.scheme");
	//gui.loadScheme("AlfiskoSkin.scheme");

	//gui.loadLayout("SimpleDebug.layout");
	//gui.setFont("DejaVuSans-10");
	/*vec4f perc;
	perc.x = 0.5f;
	perc.y = 0.5f;
	perc.z = 0.1f;
	perc.w = 0.0001f;

	vec4f perx;

	perx.x = 0.0f;
	perx.y = 0.0f;
	perx.z = 0.0f;
	perx.w = 0.0f;*/

	//gui.createWidget("AlfiskoSkin/Button", perc, perx, "Test");
	scene = new TNode();
	scene->setType(T_RAIZ);
}


SceneManager::~SceneManager() {
}

TModel* SceneManager::getMesh(std::string path,Shader* shader) {
	if (path != "") {
		return ResourceManager::i().getMesh(path,shader);
	}
	return NULL;
}

void SceneManager::draw(GLFWwindow* window) {
	// Clear
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Update matrices
	projection = glm::perspective(camera_ptr->Zoom, (float)*screenWidth / (float)*screenHeight, 0.1f, 100.0f); // Cambiar el plano cercano (así la interfaz no se corta?)
	view = camera_ptr->GetViewMatrix();

	// Desencadena el dibujado de la escena
	scene->draw(projection, view, m_matrizActual);
	//gui.draw();
	glfwSwapBuffers(window);
	
}

TModel * SceneManager::crearNodoMalla(TModel * model)
{
	TNode * nuevoNodoMalla;
	TNode * nuevoNodoRotacion;
	TNode * nuevoNodoEscalado;
	TNode * nuevoNodoTraslacion;

	//creamos los nodos malla y los nodos transformaciones necesaria para esta

	
	//rotacion antes de traslacion
	nuevoNodoRotacion = crearNodoRotacion(scene);
	nuevoNodoEscalado = crearNodoEscalado(nuevoNodoRotacion);
	nuevoNodoTraslacion = crearNodoTraslacion(nuevoNodoEscalado);
	nuevoNodoMalla = new TNode(nuevoNodoTraslacion);
	
	//asignamos los hijos
	
	//rotacion antes de traslacion
	scene->addChild(nuevoNodoRotacion);
	nuevoNodoRotacion->addChild(nuevoNodoEscalado);
	nuevoNodoEscalado->addChild(nuevoNodoTraslacion);
	nuevoNodoTraslacion->addChild(nuevoNodoMalla);
	
	


	//asignamos matrices de transformacion
	model->setTransformacionRotacion(static_cast<TTransform*> (nuevoNodoRotacion->getEntity()));
	model->setTransformacionEscalado(static_cast<TTransform*> (nuevoNodoEscalado->getEntity()));
	model->setTransformacionTraslacion(static_cast<TTransform*> (nuevoNodoTraslacion->getEntity()));

	//TODOOO aqui no tendriamos qeu setearle el modelo al TModel?
	nuevoNodoMalla->setEntity(model);
	nuevoNodoMalla->setType(T_MALLA);
	//nuevoNodoMalla->setModel(model);
	//nuevoNodoMalla->getEntity()->setModel();

	return model;
}

TNode * SceneManager::crearNodoTransformacion()
{
	//DUDA aqui tendriamos que tener tambien algun identificador en el nodo no? porque yo estoy creando 3 nodos de transformacion pero no se cual es cual.
	TNode* transNode = new TNode(scene);
	TTransform* trans = new TTransform();
	transNode->setType(T_TRANSFORM);
	transNode->setEntity(trans);

	return transNode;
}

TNode * SceneManager::crearNodoTraslacion(TNode * nodoPadre)
{
	TNode* transNode = new TNode(nodoPadre);
	transNode->setType(T_TRASLACION);
	TTransform* trans = new TTransform();
	trans->setPosition(Vec3<float>(0.0f, -1.75f, 0.0f));
	transNode->setEntity(trans);
	return transNode;
}

TNode * SceneManager::crearNodoRotacion(TNode * nodoPadre)
{
	TNode* transNode = new TNode(nodoPadre);
	transNode->setType(T_ROTACION);
	TTransform* trans = new TTransform();
	transNode->setEntity(trans);
	return transNode;
}

TNode * SceneManager::crearNodoEscalado(TNode * nodoPadre)
{
	TNode* transNode = new TNode(nodoPadre);
	transNode->setType(T_ESCALADO);
	TTransform* trans = new TTransform();
	trans->setScale(Vec3<float>(0.1f, 0.1f, 0.1f));
	transNode->setEntity(trans);
	
	return transNode;
}

TNode * SceneManager::crearNodoLuz()
{
	TNode* luzNode = new TNode(scene);
	luzNode->setType(T_LUZ);
	return luzNode;
}

TNode * SceneManager::crearNodoCamara()
{
	return nullptr;
}

