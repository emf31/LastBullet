#include "ResourceManager.h"



ResourceManager::ResourceManager() {
}


ResourceManager::~ResourceManager() {
	for (auto i = models.begin(); i != models.end(); ++i) { 
		delete i->second;
		models.erase(i->first);
	}
}

TModel* ResourceManager::getMesh(std::string path) {
	if (path != "") {
		if (models.find(path) != models.end()) {
			return models[path];
		} else {
			//TODO
			TModel *model = new TModel((GLchar*)path.c_str());
			models[path] = model;
			return models[path];
		}
		std::cout << "ERROR CARGANDO MESH: " << path << std::endl;
		return NULL;
	}
}

void ResourceManager::getTexture(std::string path) {
}
