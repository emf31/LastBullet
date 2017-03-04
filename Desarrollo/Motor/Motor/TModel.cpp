#include "TModel.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>
#include "SceneManager.h"


TModel::TModel(GLchar * path, Shader* shaderPath) {
	/*Shader* shader;
	if (*shaderPath) {
		shader = ResourceManager::i().getShader(shaderPath);
	} else {
		shader = ResourceManager::i().getShader("assets/model_loading.vs", "assets/model_loading.frag");
	}*/


	// Carmamos el modelo
	this->loadModel(path);
	m_r = 1.f;
	m_g = 1.f;
	m_b = 1.f;
	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
}

TModel::~TModel() {
}

void TModel::beginDraw() {

	SceneManager &sm = SceneManager::i();
	glm::mat4 view = SceneManager::i().view;
	glm::mat4 projection = SceneManager::i().projection;
	glm::mat4 model= SceneManager::i().m_matrizActual;

	
	/*
	ESTO PUEDE SERVIR PARA HACER QUE LA PISTOLA GIRE CON LA CAMARA YA QUE SE PROCESARIA ANTES LO DE LA PISTOLA QUE LO DE LA CAMARA
		int tam = SceneManager::i().pilaMatrices.size();
	for (int i = 0; i < tam; i++) {
		model = SceneManager::i().pilaMatrices.front()*model;
		SceneManager::i().pilaMatrices.pop_front();
	}
	//por si dependemos de la transformacion del padre, tenemos que multiplicar nuestra modelo por la de los padres que es la actual.
	model = actual * model;
	//seteamos la matrizActual a la del modelo por si acaso tiene algun hijo que necesita su matriz modelo
	SceneManager::i().m_matrizActual = model;
	
	*/


	glm::mat4 modelview = projection * view * model;




	// Activamos el shader que tenemos guardado
	sm.shaderGeometria->Use();
	// Le pasamos las matrices
	//std::cout << "paso matriz modelview" << std::endl;
	//std::cout << "paso matriz model" << std::endl;
	//std::cout << "paso matriz objectColor" << std::endl;
	glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "modelview"), 1, GL_FALSE, glm::value_ptr(modelview));
	glUniformMatrix4fv(glGetUniformLocation(sm.shaderGeometria->Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
	//color
	glUniform3f(glGetUniformLocation(sm.shaderGeometria->Program, "objectColor"), m_r, m_g, m_b);
	/*
	ESTAMOS EN EL SHADER DE GEOMETRIA ASI QUE NO PASAMOS LUCES SOLO LA GEOMETRIA
	
	//numero luces
	glUniform1i(glGetUniformLocation(sm.shaderGeometria->Program, "num_pointlight"), sm.vecPointLight.size());
	glUniform1i(glGetUniformLocation(sm.shaderGeometria->Program, "num_flashlight"), sm.vecFlashLight.size());

	//camaras
	glUniform3f(glGetUniformLocation(sm.shaderGeometria->Program, "viewPos"), SceneManager::i().activeCameraPos.getX(), SceneManager::i().activeCameraPos.getY(), SceneManager::i().activeCameraPos.getZ());
	
	//LUZ SOLAR
	if (sm.sunlight != nullptr) {
		sm.sunlight->pasarDatosAlShader(sm.shaderGeometria);
	}
	//POINTLIGHT
	for (int i = 0; i < SceneManager::i().vecPointLight.size(); i++) {
		sm.vecPointLight[i]->pasarDatosAlShader(sm.shaderGeometria, i);
	}
	//LUZ LINTERNA
	for (int i = 0; i < SceneManager::i().vecFlashLight.size(); i++) {
		sm.vecFlashLight[i]->pasarDatosAlShader(sm.shaderGeometria, i);
	}
	
	*/
	

	//Dibujamos los hijos (Si los hay)
	for (GLuint i = 0; i < this->meshes.size(); i++)
		this->meshes[i]->beginDraw();
}

void TModel::loadModel(const string& path) {
	// Leemos con ASSIMP
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);
	// Miramos si hay algún error
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // Si no es 0
	{
		cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
		return;
	}
	// Cogemos el directorio del recurso
	this->directory = path.substr(0, path.find_last_of('/'));

	// Recorremos el nodo padre de ASSIMP recursivamente
	this->processNode(scene->mRootNode, scene);
}

void TModel::processNode(aiNode * node, const aiScene * scene) {
	// Procesamos cada malla
	for (GLuint i = 0; i < node->mNumMeshes; i++) {
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
		//Guardamos la malla en nuestro array de mallas
		this->meshes.push_back(this->processMesh(mesh, scene));
	}

	// Procesamos los hijos de este nodo (recursivamente)
	for (GLuint i = 0; i < node->mNumChildren; i++) {
		this->processNode(node->mChildren[i], scene);
	}
}

TMesh* TModel::processMesh(aiMesh * mesh, const aiScene * scene) {
	// Datos básicos de las mallas (vértices, índices y texturas)
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture*> textures;

	// Recorremos todos los vértices de la malla
	for (GLuint i = 0; i < mesh->mNumVertices; i++) {
		Vertex vertex;
		glm::vec3 vector;
		// Posiciones
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vertex.Position = vector;
		// Normales
		vector.x = mesh->mNormals[i].x;
		vector.y = mesh->mNormals[i].y;
		vector.z = mesh->mNormals[i].z;
		vertex.Normal = vector;
		// Coordenadas de textura
		if (mesh->mTextureCoords[0]) // Tiene coordenadas de texturas?
		{
			glm::vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		} else
			vertex.TexCoords = glm::vec2(0.0f, 0.0f); //Si no las tiene le ponemos unas por defecto
		vertices.push_back(vertex);
	}
	// Recorremos todas las caras de la malla (triángulos) y nos guardamos sus vertex index
	for (GLuint i = 0; i < mesh->mNumFaces; i++) {
		aiFace face = mesh->mFaces[i];
		// Nos guardamos todos los índices
		for (GLuint j = 0; j < face.mNumIndices; j++)
			indices.push_back(face.mIndices[j]);
	}
	// Materiales!
	if (mesh->mMaterialIndex >= 0) {
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		// Diffuse: texture_diffuseN
		//vector<Texture*> diffuseMaps;
		// Specular: texture_specularN
		//vector<Texture*> specularMaps;
		// Normal: texture_normalN
		//vector<Texture*> normalMaps;

		// 1. Diffuse maps
		this->loadMaterialTextures(textures, material, aiTextureType_DIFFUSE, "texture_diffuse");
		//textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		// 2. Specular maps
		this->loadMaterialTextures(textures, material, aiTextureType_SPECULAR, "texture_specular");
		//textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		//3. Normal maps
		this->loadMaterialTextures(textures, material, aiTextureType_NORMALS, "texture_normal");
		//textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
	}

	// Return del mesh preparado
	return new TMesh(vertices, indices, textures, SceneManager::i().shaderGeometria);
}

void TModel::loadMaterialTextures(vector<Texture*>& textVec, aiMaterial * mat, aiTextureType type, string typeName) {
	for (GLuint i = 0; i < mat->GetTextureCount(type); i++) {
		aiString str;
		mat->GetTexture(type, i, &str);
		// Miramos si se ha cargado la textura con anterioridad en el ResourceManager
		// Si no se ha cargado, el RM la carga. Si ya se había cargado, el RM nos da un puntero a ella :)
		ResourceManager rm = ResourceManager::i();
		Texture* text = rm.getTexture(str.C_Str(), typeName, this->directory);
		textVec.push_back(text);
	}
}


void TModel::endDraw() {
	//std::cout << u8"Adiós" << std::endl;
	//TEntity::endDraw();
}

void TModel::setPosition(Vec3<float> pos) {
	transTraslacion->setPosition(pos);
}

void TModel::updatePosition(Vec3<float> pos)
{
	transTraslacion->updatePosition(pos);
}

void TModel::setRotation(Vec3<float> rot) {
	transRotacion->setRotationDirection(rot);
}

void TModel::setRotationX(float angu) {
	transRotacion->setRotationX(angu);
}

void TModel::setRotationY(float angu) {
	transRotacion->setRotationY(angu);
}

void TModel::setRotationZ(float angu) {
	transRotacion->setRotationZ(angu);
}

void TModel::setScale(Vec3<float> esc) {
	transEscalado->setScale(esc);
}

void TModel::setTransformacionRotacion(TTransform * rot) {
	transRotacion = rot;
}

void TModel::setTransformacionEscalado(TTransform * esc) {
	transEscalado = esc;
}

void TModel::setTransformacionTraslacion(TTransform * tras) {
	transTraslacion = tras;
}



Vec3<float> TModel::getRotation() {
	return transRotacion->getRotation();
}

Vec3<float> TModel::getPosition()
{
	return transTraslacion->getPosition();
}

Vec3<float> TModel::getScale()
{
	return transEscalado->getScale();
}
