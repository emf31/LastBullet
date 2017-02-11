#include "TModel.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>


TModel::TModel(GLchar * path, Shader* shaderPath) {
	/*Shader* shader;
	if (*shaderPath) {
		shader = ResourceManager::i().getShader(shaderPath);
	} else {
		shader = ResourceManager::i().getShader("assets/model_loading.vs", "assets/model_loading.frag");
	}*/

	// Si no se especifica un shader se carga uno por defecto
	if (shaderPath == NULL) {
		this->shader = ResourceManager::i().getShader("assets/model_loading.vs", "assets/model_loading.frag");
	} else {
		this->shader = shaderPath;
	}
	// Carmamos el modelo
	this->loadModel(path);
}

TModel::~TModel() {
}

void TModel::beginDraw(glm::mat4 projection, glm::mat4 view, glm::mat4& matrizActual) {

	// Activamos el shader que tenemos guardado
	shader->Use();

	// Le pasamos las matrices
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(shader->Program, "model"), 1, GL_FALSE, glm::value_ptr(matrizActual));

	//Dibujamos los hijos (Si los hay)
	for (GLuint i = 0; i < this->meshes.size(); i++)
		this->meshes[i].beginDraw(projection, view, matrizActual);
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

TMesh TModel::processMesh(aiMesh * mesh, const aiScene * scene) {
	// Datos básicos de las mallas (vértices, índices y texturas)
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;

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
		// Specular: texture_specularN
		// Normal: texture_normalN

		// 1. Diffuse maps
		vector<Texture> diffuseMaps = this->loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
		// 2. Specular maps
		vector<Texture> specularMaps = this->loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		//3. Normal maps
		vector<Texture> normalMaps = this->loadMaterialTextures(material, aiTextureType_NORMALS, "texture_normal");
		textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
	}

	// Return del mesh preparado
	return TMesh(vertices, indices, textures, shader);
}

vector<Texture> TModel::loadMaterialTextures(aiMaterial * mat, aiTextureType type, string typeName) {
	vector<Texture> textures;
	for (GLuint i = 0; i < mat->GetTextureCount(type); i++) {
		aiString str;
		mat->GetTexture(type, i, &str);
		// Miramos si se ha cargado la textura con anterioridad en el ResourceManager
		// Si no se ha cargado, el RM la carga. Si ya se había cargado, el RM nos da un puntero a ella :)
		ResourceManager rm = ResourceManager::i();
		Texture text = rm.getTexture(str.C_Str(), typeName, this->directory);
		textures.push_back(text);
	}
	return textures;
}


void TModel::endDraw(glm::mat4& matrizActual) {
	//std::cout << u8"Adiós" << std::endl;
	//TEntity::endDraw();
}

void TModel::setPosition(Vec3<float> pos) {
	transformacion->setPosition(pos);
}

void TModel::setRotation(Vec3<float> rot) {
	transformacion->setRotation(rot);
}

void TModel::setScale(Vec3<float> esc) {
	transformacion->setScale(esc);
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
	return transformacion->getRotation();
}

Vec3<float> TModel::getPosition()
{
	return transformacion->getPosition();
}

Vec3<float> TModel::getScale()
{
	return transformacion->getScale();
}
