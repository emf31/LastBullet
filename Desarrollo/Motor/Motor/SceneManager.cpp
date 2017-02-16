#include "SceneManager.h"
#include "TTransform.h"



void SceneManager::inicializar() {
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
	scene = new TNode(-1);
	scene->setType(T_RAIZ);
	m_matrizActual = glm::mat4();
	std::cout << "matriz actual reseteada" << std::endl;
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
	scene->draw();
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
	int id = model->getID();
	
	//rotacion antes de traslacion
	nuevoNodoRotacion = crearNodoRotacion(scene, id);
	nuevoNodoEscalado = crearNodoEscalado(nuevoNodoRotacion, id);
	nuevoNodoTraslacion = crearNodoTraslacion(nuevoNodoEscalado, id);
	nuevoNodoMalla = new TNode(id, nuevoNodoTraslacion);
	
	//asignamos los hijos
	scene->addChild(nuevoNodoRotacion);
	nuevoNodoRotacion->addChild(nuevoNodoEscalado);
	nuevoNodoEscalado->addChild(nuevoNodoTraslacion);
	nuevoNodoTraslacion->addChild(nuevoNodoMalla);
	
	


	//asignamos matrices de transformacion
	model->setTransformacionRotacion(static_cast<TTransform*> (nuevoNodoRotacion->getEntity()));
	model->setTransformacionEscalado(static_cast<TTransform*> (nuevoNodoEscalado->getEntity()));
	model->setTransformacionTraslacion(static_cast<TTransform*> (nuevoNodoTraslacion->getEntity()));
	model->setMiNodo(nuevoNodoMalla);

	//TODOOO aqui no tendriamos qeu setearle el modelo al TModel?
	nuevoNodoMalla->setEntity(model);
	nuevoNodoMalla->setType(T_MALLA);
	//nuevoNodoMalla->setModel(model);
	//nuevoNodoMalla->getEntity()->setModel();

	return model;
}

TNode * SceneManager::crearNodoTransformacion(int entityID)
{
	//DUDA aqui tendriamos que tener tambien algun identificador en el nodo no? porque yo estoy creando 3 nodos de transformacion pero no se cual es cual.
	TNode* transNode = new TNode(entityID, scene);
	TTransform* trans = new TTransform();
	transNode->setType(T_TRANSFORM);
	transNode->setEntity(trans);

	return transNode;
}

TNode * SceneManager::crearNodoTraslacion(TNode * nodoPadre, int entityID)
{
	TNode* transNode = new TNode(entityID, nodoPadre);
	transNode->setType(T_TRASLACION);
	TTransform* trans = new TTransform();
	trans->setPosition(Vec3<float>(0.0f, 0.0f, 0.0f));
	transNode->setEntity(trans);
	return transNode;
}

TNode * SceneManager::crearNodoRotacion(TNode * nodoPadre, int entityID)
{
	TNode* transNode = new TNode(entityID, nodoPadre);
	transNode->setType(T_ROTACION);
	TTransform* trans = new TTransform();
	transNode->setEntity(trans);
	return transNode;
}

TNode * SceneManager::crearNodoEscalado(TNode * nodoPadre, int entityID)
{
	TNode* transNode = new TNode(entityID, nodoPadre);
	transNode->setType(T_ESCALADO);
	TTransform* trans = new TTransform();
	transNode->setEntity(trans);
	
	return transNode;
}

TSpotLight * SceneManager::crearNodoLuz()
{

	TNode* luzNode;
	TNode * nuevoNodoRotacion;
	TNode * nuevoNodoEscalado;
	TNode * nuevoNodoTraslacion;

	//importante crear primero la entity y luego su nodo ya que tenemos que pasarle el id de la entity
	TSpotLight* luz = new TSpotLight();
	int id = luz->getID();

	//rotacion antes de traslacion
	nuevoNodoRotacion = crearNodoRotacion(scene, id);
	nuevoNodoEscalado = crearNodoEscalado(nuevoNodoRotacion, id);
	nuevoNodoTraslacion = crearNodoTraslacion(nuevoNodoEscalado, id);
	luzNode = new TNode(id, nuevoNodoTraslacion);

	//asignamos los hijos
	scene->addChild(nuevoNodoRotacion);
	nuevoNodoRotacion->addChild(nuevoNodoEscalado);
	nuevoNodoEscalado->addChild(nuevoNodoTraslacion);
	nuevoNodoTraslacion->addChild(luzNode);




	//asignamos matrices de transformacion
	luz->setTransformacionRotacion(static_cast<TTransform*> (nuevoNodoRotacion->getEntity()));
	luz->setTransformacionEscalado(static_cast<TTransform*> (nuevoNodoEscalado->getEntity()));
	luz->setTransformacionTraslacion(static_cast<TTransform*> (nuevoNodoTraslacion->getEntity()));
	luz->setMiNodo(luzNode);

	//seteamos la entity
	luzNode->setEntity(luz);
	luzNode->setType(T_LUZ);


	return luz;

}



TNode * SceneManager::crearNodoCamara()
{
	return nullptr;
}

