#pragma once
#include <unordered_map>
#include <string>
#include "TEntity.h"
#include "TModel.h"
#include <assimp/Importer.hpp>


class TAnimationGroupMesh;

class ResourceManager {
public:
	
	static ResourceManager& i() {
		static ResourceManager rm;
		return rm;
	}
	
	
	TMeshGroup* getMesh(const std::string& path, Shader* shader=NULL);
	Shader* getShader(const std::string& vertexShader, std::string fragmentShader="");
	Texture* getTexture(const std::string& path, const std::string& type, const std::string& directory);
	TAnimationGroupMesh* getAnimationMesh(const std::string& path, unsigned int numFrames, Shader* shader = NULL);
	void shutdown();
	
private:
	ResourceManager();

	std::unordered_map<std::string, TMeshGroup*> models;
	std::unordered_map<std::string, Shader*> shaders;
	std::unordered_map<std::string, Texture*> textures;
	std::unordered_map<std::string, TAnimationGroupMesh*> animations;
	

	GLint TextureFromFile(const char* path, std::string directory);

	
};

