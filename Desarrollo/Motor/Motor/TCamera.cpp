#include "TCamera.h"
#include "SceneManager.h"

#define PI 3.141592654 



// Constructor with vectors

TCamera::TCamera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM) {

	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();

	//this->Position = position;
	//setPosition(Vec3<float>(position.x, position.y, position.z));
	this->WorldUp = up;
	this->Yaw = yaw;
	this->Pitch = pitch;
	direccion = glm::vec3(0.0f, 0.0f, -1.0f);
	derecha= glm::cross(direccion, this->WorldUp);
	derecha = glm::normalize(derecha);
	//this->updateCameraVectors();
}

// Constructor with scalar values

TCamera::TCamera(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat upX, GLfloat upY, GLfloat upZ, GLfloat yaw, GLfloat pitch) : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVTY), Zoom(ZOOM) {
	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();

	//this->Position = glm::vec3(posX, posY, posZ);
	//setPosition(Vec3<float>(posX, posY, posZ));
	this->WorldUp = glm::vec3(upX, upY, upZ);
	this->Yaw = yaw;
	this->Pitch = pitch;
	this->updateCameraVectors();
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
	GLfloat velocity = this->MovementSpeed * deltaTime;
	glm::vec3 result;
	std::cout << "Vector direccion: " << direccion.x << "," << "," << direccion.y << "," << direccion.z << std::endl;
	std::cout << "Vector derecha: " << derecha.x << "," << "," << derecha.y << "," << derecha.z << std::endl;
	std::cout << "Vector Front: " << Front.x << "," << "," << Front.y << "," << Front.z << std::endl;
	std::cout << "Vector Right: " << Right.x << "," << "," << Right.y << "," << Right.z << std::endl;
	//Front.y = -Front.y;
	//std::cout << "El vector direccion: " << Front.x << "," << Front.y << "," << Front.z<< "," << std::endl;
	if (direction == FORWARD) {
		result = direccion * velocity;
		//std::cout << "El vector resultado: " << result.x << "," << result.y << "," << result.z << "," << std::endl;
		updatePosition(Vec3<float>(result.x, result.y, result.z));
		//this->Position += this->Front * velocity;
	}
	if (direction == BACKWARD) {
		result = direccion * -velocity;
		//std::cout << "El vector resultado: " << result.x << "," << result.y << "," << result.z << "," << std::endl;
		updatePosition(Vec3<float>(result.x, result.y, result.z));
		//this->Position -= this->Front * velocity;
	}

	if (direction == LEFT) {
		result = derecha * -velocity;
		//std::cout << "El vector resultado: " << result.x << "," << result.y << "," << result.z << "," << std::endl;
		updatePosition(Vec3<float>(result.x, result.y, result.z));
		//this->Position -= this->Right * velocity;
	}

	if (direction == RIGHT) {
		result = derecha * velocity;
		//std::cout << "El vector resultado: " << result.x << "," << result.y << "," << result.z << "," << std::endl;
		updatePosition(Vec3<float>(result.x, result.y, result.z));
		//this->Position += this->Right * velocity;
	}

}

void TCamera::ProcessMouseMovement(GLfloat xoffset, GLfloat yoffset, GLboolean constrainPitch) {
	xoffset *= this->MouseSensitivity;
	yoffset *= this->MouseSensitivity;


	this->Yaw -= xoffset;
	this->Pitch += yoffset;
	//rotX = Yaw;
	//rotY = Pitch;
	//std::cout<< " rotX: " << Pitch <<" rotY: "<< Yaw << std::endl;
	//std::cout << " angulosX: " << Pitch*0.1f/ this->MouseSensitivity << " angulosY: " << Yaw*0.1f/this->MouseSensitivity << std::endl;
	//setRotationY(-Yaw*0.01);
	//setRotationX(Pitch*0.01);
	// Make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch) {
		if (this->Pitch > 89.0f)
			this->Pitch = 89.0f;
		if (this->Pitch < -89.0f)
			this->Pitch = -89.0f;
	}


	// Update Front, Right and Up Vectors using the updated Eular angles
	
	transRotacion->setRotationY(Yaw);
	transRotacion->setRotationX(Pitch);
	this->updateCameraVectors();
	//transRotacion->setRotationDirection(vecFront);
	//std::cout << "El vector rotacion es: " << vecFront.getX() << "," << vecFront.getY() << "," << vecFront.getZ() << "," << std::endl;
}

void TCamera::ProcessMouseScroll(GLfloat yoffset) {
	if (this->Zoom >= 1.0f && this->Zoom <= 45.0f)
		this->Zoom -= yoffset;
	if (this->Zoom <= 1.0f)
		this->Zoom = 1.0f;
	if (this->Zoom >= 45.0f)
		this->Zoom = 45.0f;
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
	//glm::vec4 origen = glm::vec4(0, 0, 0, 0);
	glm::vec4 destino = glm::vec4(0, 0, -1, 1);

	glm::mat4 rot = transRotacion->getRotation2();
	rot = glm::inverse(rot);
	//glm::mat4 tras = transTraslacion->getPosition2();

	//vista = tras * rot;

	//glm::vec4 origen2 = origen* vista;
	glm::vec4 destino2 = destino* rot;

	destino2 = glm::normalize(destino2);

	//glm::vec4 vecDir = destino2 - origen2;
	direccion = glm::vec3(destino2.x, destino2.y, destino2.z);

	derecha = glm::cross(direccion, this->WorldUp);
	derecha = glm::normalize(derecha);
	//std::cout << "Vector direccion: " << direccion.x << "," << "," << direccion.y << "," << direccion.z << std::endl;

	
	// Calculate the new Front vector
	
	glm::vec3 front;
	front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
	front.y = sin(glm::radians(this->Pitch));
	front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
	
	
	this->Front = glm::normalize(front);
	vecFront = Vec3<float>(Front.x, -Front.y, Front.z);
	//std::cout << "Vector direccion: " << Front.x << "," << "," << Front.y << "," << Front.z << std::endl;
	
	
	// Also re-calculate the Right and Up vector
	this->Right = glm::cross(this->Front, this->WorldUp);  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	//vecFront = Vec3<float>(Right.x, Right.y, Right.z);
	this->Right = glm::normalize(this->Right);
	this->Up = glm::normalize(glm::cross(this->Right, this->Front));
	
}