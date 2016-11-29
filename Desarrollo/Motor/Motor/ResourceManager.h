#pragma once
#include <unordered_map>
#include <string>
#include "TEntity.h"
#include "TModel.h"
#include <assimp/Importer.hpp>
class ResourceManager {
public:
	ResourceManager();
	static ResourceManager& i() {
		static ResourceManager rm;
		return rm;
	}
	~ResourceManager();
	//TODO Métodos para añadr resources, para buscar resources, meterlos al árbol de la escena...
	TModel* getMesh(const std::string& path, Shader* shader=NULL);
	Shader* getShader(const std::string& vertexShader, std::string fragmentShader="");
	Texture getTexture(const std::string& path, const std::string& type, const std::string& directory);
private:
	std::unordered_map<std::string, TModel*> models;
	std::unordered_map<std::string, Shader*> shaders;
	std::unordered_map<std::string, Texture> textures;
};

