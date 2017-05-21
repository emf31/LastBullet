#include "AnimationMesh.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>
#include "SceneManager.h"


AnimationMesh::AnimationMesh(const std::string& path, Shader* shader) : 
	sm(SceneManager::i())
{

	// Carmamos el modelo
	this->loadModel(path);
}

AnimationMesh::~AnimationMesh() {
	for (auto it = meshes.begin(); it != meshes.end(); ++it) {
		delete *it;
	}
	meshes.clear();
}

void AnimationMesh::draw() {

	//Dibujamos los hijos (Si los hay)
	for (std::vector<TMesh*>::iterator it = meshes.begin(); it != meshes.end(); it++) {
		(*it)->draw();
	}

}

void AnimationMesh::loadModel(const std::string& path) {
	// Leemos con ASSIMP
	Assimp::Importer importer;
	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
	// Miramos si hay algún error
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // Si no es 0
	{
		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
		return;
	}
	// Cogemos el directorio del recurso
	this->directory = path.substr(0, path.find_last_of('/'));

	// Recorremos el nodo padre de ASSIMP recursivamente
	this->processNode(scene->mRootNode, scene);
}



void AnimationMesh::processNode(aiNode * node, const aiScene * scene) {
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

TMesh* AnimationMesh::processMesh(aiMesh * mesh, const aiScene * scene) {
	// Datos básicos de las mallas (vértices, índices y texturas)

	std::vector<Texture*> textures;
	int numIndices = 0;

	for (GLuint i = 0; i < mesh->mNumFaces; i++) {
		aiFace face = mesh->mFaces[i];
		// Nos guardamos todos los índices
		for (GLuint j = 0; j < face.mNumIndices; j++)
			numIndices++;
	}

	Vertex *vertices = new Vertex[mesh->mNumVertices];
	GLuint *indices = new GLuint[numIndices];

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
		if (mesh->mTangents != NULL) {
			//tangentes
			vector.x = mesh->mTangents[i].x;
			vector.y = mesh->mTangents[i].y;
			vector.z = mesh->mTangents[i].z;
			vertex.Tangent = vector;
		}
		if (mesh->mBitangents != NULL) {
			//bitangentes
			vector.x = mesh->mBitangents[i].x;
			vector.y = mesh->mBitangents[i].y;
			vector.z = mesh->mBitangents[i].z;
			vertex.Bitangent = vector;
		}
		// Coordenadas de textura
		if (mesh->mTextureCoords[0]) // Tiene coordenadas de texturas?
		{
			glm::vec2 vec;
			vec.x = mesh->mTextureCoords[0][i].x;
			vec.y = mesh->mTextureCoords[0][i].y;
			vertex.TexCoords = vec;
		}
		else {
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		}
		//Si no las tiene le ponemos unas por defecto
		vertices[i] = vertex;
	}
	// Recorremos todas las caras de la malla (triángulos) y nos guardamos sus vertex index
	int cont = 0;
	for (GLuint i = 0; i < mesh->mNumFaces; i++) {
		aiFace face = mesh->mFaces[i];
		// Nos guardamos todos los índices
		for (GLuint j = 0; j < face.mNumIndices; j++) {
			indices[cont] = face.mIndices[j];
			cont++;
		}
	}
	// Materiales!
	if (mesh->mMaterialIndex >= 0) {
		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

		// 1. Diffuse maps
		this->loadMaterialTextures(textures, material, aiTextureType_DIFFUSE, "texture_diffuse");
		// 2. Specular maps
		this->loadMaterialTextures(textures, material, aiTextureType_SPECULAR, "texture_specular");
		//3. Normal maps
		this->loadMaterialTextures(textures, material, aiTextureType_NORMALS, "texture_normal");
		//4.Tangent
		this->loadMaterialTextures(textures, material, aiTextureType_NORMALS, "texture_tangent");
		//5.Bitangent
		this->loadMaterialTextures(textures, material, aiTextureType_NORMALS, "texture_bitangent");
		//6.Emisivo
		this->loadMaterialTextures(textures, material, aiTextureType_EMISSIVE, "texture_emisivo");
	}

	// Return del mesh preparado
	return new TMesh(vertices, indices, textures, SceneManager::i().shaderGeometria, mesh->mNumVertices, numIndices);
}

void AnimationMesh::loadMaterialTextures(std::vector<Texture*>& textVec, aiMaterial * mat, aiTextureType type, const std::string& typeName) {
	for (GLuint i = 0; i < mat->GetTextureCount(type); i++) {
		aiString str;
		mat->GetTexture(type, i, &str);
		// Miramos si se ha cargado la textura con anterioridad en el ResourceManager
		// Si no se ha cargado, el RM la carga. Si ya se había cargado, el RM nos da un puntero a ella :)
		ResourceManager& rm = ResourceManager::i();
		Texture* text = rm.getTexture(str.C_Str(), typeName, this->directory);

		//if (text != nullptr) {
			textVec.push_back(text);
		//}
		
	}
}




