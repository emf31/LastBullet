#include "TCamera.h"
#include "SceneManager.h"

#define PI 3.141592654 



// Constructor with vectors

TCamera::TCamera() {

	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();

	//paramtros camara
	movementSpeed = SPEED;
	mouseSensitivity = SENSITIVTY;
	zoom=ZOOM;

	//rotacion y vectores iniciales
	rotX = 0.0f;
	rotY = 0.0f;
	direccion = glm::vec3(0.0f, 0.0f, -1.0f);
	worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	derecha= glm::cross(direccion, worldUp);
	derecha = glm::normalize(derecha);
}


TCamera::~TCamera() {
}


glm::mat4 TCamera::GetViewMatrix() {
	view = glm::mat4();
	glm::vec3 posCamara = calcularPosicionVista();
	
	//view = glm::translate(view, posCamara);
	//glm::rotate;
	view = glm::inverse(view);
	return view;
	//esto no se puede hacer aun pork necesitamos tener la rotacion del personaje desde el juego, si el personaje rota la camara al ser hija tendra que rotar en el mismo angulo, lo que significa 
	//coger la matriz de rotacion del personaje

	//return glm::lookAt(posCamara, posCamara + this->Front, this->Up);
	
}

void TCamera::ProcessKeyboard(Camera_Movement direction, GLfloat deltaTime) {
	GLfloat velocity = movementSpeed * deltaTime;
	glm::vec3 result;

	if (direction == FORWARD) {
		result = direccion * velocity;
		updatePosition(Vec3<float>(result.x, result.y, result.z));
	}
	if (direction == BACKWARD) {
		result = direccion * -velocity;
		updatePosition(Vec3<float>(result.x, result.y, result.z));
	}

	if (direction == LEFT) {
		result = derecha * -velocity;
		updatePosition(Vec3<float>(result.x, result.y, result.z));
	}

	if (direction == RIGHT) {
		result = derecha * velocity;
		updatePosition(Vec3<float>(result.x, result.y, result.z));
	}

}

void TCamera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset) {
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	this->rotY -= xoffset;
	this->rotX += yoffset;

	if (this->rotX > 89.0f)	  
		this->rotX = 89.0f;	  
	if (this->rotX < -89.0f)  
		this->rotX = -89.0f;
	


	// Update Front, Right and Up Vectors using the updated Eular angles
	
	transRotacion->setRotationY(rotY);
	transRotacion->setRotationX(rotX);
	this->updateCameraVectors();
	//transRotacion->setRotationDirection(vecFront);
	//std::cout << "El vector rotacion es: " << vecFront.getX() << "," << vecFront.getY() << "," << vecFront.getZ() << "," << std::endl;
}

void TCamera::ProcessMouseScroll(GLfloat yoffset) {
	if (zoom >= 1.0f && zoom <= 45.0f)
		zoom -= yoffset;
	if (zoom <= 1.0f)
		zoom = 1.0f;
	if (zoom >= 45.0f)
		zoom = 45.0f;
}

glm::vec3 TCamera::calcularPosicionVista()
{
	TNode* nodoActual = getMiNodo();
	Vec3<float> pos = Vec3<float>(0.0f, 0.0f, 0.0f);
	float rot = 0.0f;
	Vec3<float> aux ;
	TTransform* t;
	glm::mat4 tras;
	glm::mat4 rotmatrix;
	while ((nodoActual->getParentNode() != nullptr) && (nodoActual->getParentNode()->getNodeType()!=T_RAIZ)) {
		nodoActual = nodoActual->getParentNode();
		if (nodoActual->getNodeType() == T_TRASLACION) {

			t = static_cast<TTransform*> (nodoActual->getEntity());
			aux = t->getPosition();
			//std::cout << "ENTRO A UN NODO TRASLACION PADRE DE LA CAMARA" << std::endl;
			//std::cout << "La posicion es: " << aux.getX() << "," << aux.getY() << "," << aux.getZ() << "," << std::endl;
			tras = glm::translate(tras,glm::vec3(aux.getX(), aux.getY(), aux.getZ()));
			//pos += t->getPosition();

		}
		else if (nodoActual->getNodeType() == T_ROTACION) {
			t = static_cast<TTransform*> (nodoActual->getEntity());
			rotmatrix *= t->getRotation2();
			//std::cout << "MATRIZ VISTA ROTADA : " << std::endl;
			//for (int i = 0; i < rotmatrix.length(); i++) {
			//	for (int j = 0; j < rotmatrix[0].length(); j++) {
			//		std::cout << rotmatrix[i][j] << " ";
			//	}
			//	std::cout << std::endl;
			//}
		}
		
	}
	view = tras * rotmatrix;
	//delete nodoActual;

	//NOTA ERROR YA COMETIDO: ANTES HACIAMOS UN SET POSITION PERO CLARO ESTO NO PUEDE SER PORK ENTONCES SI EL MODELO ESTA EN LA 30 Y LA CAMARA EN LA 10, EL MODELO AVANZA 5, ENTONCES LA CAMARA AHORA ESTARIA 
	//EN LA 15 Y EL MODELO EN LA 35, PERO SI HACEMOS ESE SETPOSITION A LA CAMARA EN LA SIGUIENTE ITERACION SU TRANSFORMACION DEVUELVE QUE ESTA EN LA POS 35 Y LE VA A SUMAR DE NUEVO LA POS
	//DE SU TRANSFORMACION PADRE QUE SERA LA DEL MODELO Y PONDRIA QUE LA CAMARA ESTA EN EL 70
	//setPosition(pos);
	return glm::vec3(pos.getX(), pos.getY(), pos.getZ());
}



void TCamera::beginDraw() {

}

void TCamera::endDraw() {
}

void TCamera::setPosition(Vec3<float> pos)
{
	transTraslacion->setPosition(pos);
}

void TCamera::updatePosition(Vec3<float> pos) {
	transTraslacion->updatePosition(pos);
}

void TCamera::setRotationX(float angu) {
	transRotacion->setRotationX(angu);
}

void TCamera::setRotationY(float angu) {
	transRotacion->setRotationY(angu);
}

void TCamera::setRotationZ(float angu) {
	transRotacion->setRotationZ(angu);
}

void TCamera::setTransformacionRotacion(TTransform * rot) {
	transRotacion = rot;
}

void TCamera::setTransformacionTraslacion(TTransform * tras) {
	transTraslacion = tras;
}

glm::vec3 TCamera::getPositionglm() {
	return glm::vec3(transTraslacion->getPosition().getX(), transTraslacion->getPosition().getY(), transTraslacion->getPosition().getZ());
}

Vec3<float> TCamera::getPosition()
{
	return transTraslacion->getPosition();
}

Vec3<float> TCamera::getRotation() {
	return transRotacion->getRotation();
}

void TCamera::updateCameraVectors() {

	glm::vec4 destino = glm::vec4(0, 0, -1, 1);
	glm::mat4 rot = transRotacion->getRotation2();
	rot = glm::inverse(rot);
	destino = destino* rot;
	destino = glm::normalize(destino);
	direccion = glm::vec3(destino.x, destino.y, destino.z);
	derecha = glm::cross(direccion, worldUp);
	derecha = glm::normalize(derecha);

}