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
	camaraActiva = crearNodoCamara();
	sunlight = nullptr;
	//shaderGeometria = ResourceManager::i().getShader("assets/model_loading.vs", "assets/model_loading.frag");
	shaderGeometria = ResourceManager::i().getShader("assets/geometria.vs", "assets/geometria.frag");
	shaderLuces = ResourceManager::i().getShader("assets/luces.vs", "assets/luces.frag");
	shaderBombillas = ResourceManager::i().getShader("assets/luz_loading.vs", "assets/luz_loading.frag");
	// Set samplers
	shaderLuces->Use();
	glUniform1i(glGetUniformLocation(shaderLuces->Program, "gPosition"), 0);
	glUniform1i(glGetUniformLocation(shaderLuces->Program, "gNormal"), 1);
	glUniform1i(glGetUniformLocation(shaderLuces->Program, "gAlbedoSpec"), 2);
}




TModel* SceneManager::getMesh(const std::string& path,Shader* shader) {
	if (path != "") {
		return ResourceManager::i().getMesh(path,shader);
	}
	return NULL;
}

void SceneManager::draw(GLFWwindow* window) {
	// Clear
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//enlazamos el buffer sobre el que queremos escribir
	glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
	// Update matrices
	projection = glm::perspective(camaraActiva->zoom, (float)*screenWidth / (float)*screenHeight, 0.1f, 100.0f); // Cambiar el plano cercano (as� la interfaz no se corta?)
	view = camaraActiva->GetViewMatrix();
	//activeCameraPos = Vec3<float>(camaraActiva->getPosition().x, camaraActiva->getPosition().y, camaraActiva->getPosition().z) ;
	activeCameraPos = camaraActiva->getPosition();
	// Desencadena el dibujado de la escena
	scene->draw();
	//gui.draw();
	glfwSwapBuffers(window);
	
}

void SceneManager::inicializarBuffers()
{
	GLuint screenWidth = 1280, screenHeight = 720;
	// Set up G-Buffer
	// 3 textures:
	// 1. Positions (RGB)
	// 2. Color (RGB) + Specular (A)
	// 3. Normals (RGB) 
	
	glGenFramebuffers(1, &gBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
	
	// - Position color buffer
	glGenTextures(1, &gPosition);
	glBindTexture(GL_TEXTURE_2D, gPosition);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, screenWidth, screenHeight, 0, GL_RGB, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gPosition, 0);
	// - Normal color buffer
	glGenTextures(1, &gNormal);
	glBindTexture(GL_TEXTURE_2D, gNormal);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, screenWidth, screenHeight, 0, GL_RGB, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, gNormal, 0);
	// - Color + Specular color buffer
	glGenTextures(1, &gTextura);
	glBindTexture(GL_TEXTURE_2D, gTextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, screenWidth, screenHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT2, GL_TEXTURE_2D, gTextura, 0);
	// tenemos que juntar los 3 color buffers en el framebuffer que tenemos activo para ello los juntamos en el array
	// pero como ahora tenemos 3 render targets en el fragment shader vamos a tener que definir 3 capas (layout)
	GLuint attachments[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
	glDrawBuffers(3, attachments);

	// - Create and attach depth buffer (renderbuffer)
	glGenRenderbuffers(1, &rboDepth);
	glBindRenderbuffer(GL_RENDERBUFFER, rboDepth);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, screenWidth, screenHeight);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth);
	// - Finally check if framebuffer is complete
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cout << "Framebuffer not complete!" << std::endl;
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
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

TSunLight * SceneManager::crearNodoSunLight(Vec3<float> direccion)
{
	TNode* luzNode;
	TNode * nuevoNodoRotacion;
	TNode * nuevoNodoTraslacion;

	//importante crear primero la entity y luego su nodo ya que tenemos que pasarle el id de la entity
	TSunLight* luz = new TSunLight(direccion);
	int id = luz->getID();

	//rotacion antes de traslacion
	nuevoNodoRotacion = crearNodoRotacion(scene, id);
	nuevoNodoTraslacion = crearNodoTraslacion(nuevoNodoRotacion, id);
	luzNode = new TNode(id, nuevoNodoTraslacion);

	//asignamos los hijos
	scene->addChild(nuevoNodoRotacion);
	nuevoNodoRotacion->addChild(nuevoNodoTraslacion);
	nuevoNodoTraslacion->addChild(luzNode);




	//asignamos matrices de transformacion
	luz->setTransformacionRotacion(static_cast<TTransform*> (nuevoNodoRotacion->getEntity()));
	luz->setTransformacionTraslacion(static_cast<TTransform*> (nuevoNodoTraslacion->getEntity()));
	luz->setMiNodo(luzNode);

	//seteamos la entity
	luzNode->setEntity(luz);
	luzNode->setType(T_SUNLIGHT);

	//la a�adimos al sceneManager
	setSunLight(luz);


	return luz;
}

TPointLight * SceneManager::crearNodoPointLight(Vec3<float> posicion)
{
	TNode* luzNode;
	TNode * nuevoNodoRotacion;
	TNode * nuevoNodoTraslacion;

	//importante crear primero la entity y luego su nodo ya que tenemos que pasarle el id de la entity
	TPointLight* luz = new TPointLight(posicion);
	int id = luz->getID();

	//rotacion antes de traslacion
	nuevoNodoRotacion = crearNodoRotacion(scene, id);
	nuevoNodoTraslacion = crearNodoTraslacion(nuevoNodoRotacion, id);
	luzNode = new TNode(id, nuevoNodoTraslacion);

	//asignamos los hijos
	scene->addChild(nuevoNodoRotacion);
	nuevoNodoRotacion->addChild(nuevoNodoTraslacion);
	nuevoNodoTraslacion->addChild(luzNode);




	//asignamos matrices de transformacion
	luz->setTransformacionRotacion(static_cast<TTransform*> (nuevoNodoRotacion->getEntity()));
	luz->setTransformacionTraslacion(static_cast<TTransform*> (nuevoNodoTraslacion->getEntity()));
	luz->setMiNodo(luzNode);

	//seteamos la entity
	luzNode->setEntity(luz);
	luzNode->setType(T_POINTLIGHT);

	//la a�adimos al sceneManager
	vecPointLight.push_back(luz);


	return luz;
}

TFlashLight * SceneManager::crearNodoFlashLight(Vec3<float> posicion, Vec3<float> direccion, float radioIn, float radioEx)
{

	TNode* luzNode;
	TNode * nuevoNodoRotacion;
	TNode * nuevoNodoTraslacion;

	//importante crear primero la entity y luego su nodo ya que tenemos que pasarle el id de la entity
	TFlashLight* luz = new TFlashLight(posicion,direccion, radioIn, radioEx);
	int id = luz->getID();

	//rotacion antes de traslacion
	nuevoNodoRotacion = crearNodoRotacion(scene, id);
	nuevoNodoTraslacion = crearNodoTraslacion(nuevoNodoRotacion, id);
	luzNode = new TNode(id, nuevoNodoTraslacion);

	//asignamos los hijos
	scene->addChild(nuevoNodoRotacion);
	nuevoNodoRotacion->addChild(nuevoNodoTraslacion);
	nuevoNodoTraslacion->addChild(luzNode);




	//asignamos matrices de transformacion
	luz->setTransformacionRotacion(static_cast<TTransform*> (nuevoNodoRotacion->getEntity()));
	luz->setTransformacionTraslacion(static_cast<TTransform*> (nuevoNodoTraslacion->getEntity()));
	luz->setMiNodo(luzNode);

	//seteamos la entity
	luzNode->setEntity(luz);
	luzNode->setType(T_FLASHLIGHT);

	//la a�adimos al sceneManager
	vecFlashLight.push_back(luz);


	return luz;

}


TCamera * SceneManager::crearNodoCamara()
{
	TNode* cameraNode;
	TNode * nuevoNodoRotacion;
	TNode * nuevoNodoTraslacion;

	//importante crear primero la entity y luego su nodo ya que tenemos que pasarle el id de la entity
	TCamera* camara = new TCamera();
	int id = camara->getID();

	//rotacion antes de traslacion
	nuevoNodoRotacion = crearNodoRotacion(scene, id);
	nuevoNodoTraslacion = crearNodoTraslacion(nuevoNodoRotacion, id);
	cameraNode = new TNode(id, nuevoNodoTraslacion);

	//asignamos los hijos
	scene->addChild(nuevoNodoRotacion);
	nuevoNodoRotacion->addChild(nuevoNodoTraslacion);
	nuevoNodoTraslacion->addChild(cameraNode);




	//asignamos matrices de transformacion
	camara->setTransformacionRotacion(static_cast<TTransform*> (nuevoNodoRotacion->getEntity()));
	camara->setTransformacionTraslacion(static_cast<TTransform*> (nuevoNodoTraslacion->getEntity()));
	camara->setMiNodo(cameraNode);

	//seteamos la entity
	cameraNode->setEntity(camara);
	cameraNode->setType(T_CAMARA);

	//la a�adimos al vector de camaras
	vectorCamaras.push_back(camara);


	return camara;
}

