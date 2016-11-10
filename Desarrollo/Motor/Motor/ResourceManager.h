#pragma once
#include <unordered_map>
#include <string>
#include "TEntity.h"
#include "TModel.h"
class ResourceManager {
public:
	ResourceManager();
	static ResourceManager& i() {
		static ResourceManager rm;
		return rm;
	}
	~ResourceManager();
	//TODO Métodos para añadr resources, para buscar resources, meterlos al árbol de la escena...
	TModel* getMesh(std::string path, std::string shader="");
	Shader* getShader(std::string vertexShader, std::string fragmentShader="");
	void getTexture(std::string path);
private:
	std::unordered_map<std::string, TModel*> models;
	std::unordered_map<std::string, Shader*> shaders;
	//std::unordered_map<std::string, Texture> textures
};

