#include "ResourceManager.h"



ResourceManager::ResourceManager() {
}


ResourceManager::~ResourceManager() {
	/*for (auto i = models.begin(); i != models.end(); ++i) { 
		delete i->second;
		models.erase(i->first);
	}

	for (auto i = shaders.begin(); i != shaders.end(); ++i) {
		delete i->second;
		shaders.erase(i->first);
	}*/
}

TModel* ResourceManager::getMesh(std::string path,Shader* shader) {
	if (path != "") {
		if (models.find(path) != models.end()) {
			//Si ya esta en el mapa lo devolvemos al instante. No lo cargamos dos veces!
			return models[path];
		} else {
			//Creamos un modelo nuevo y le pasamos el path
			TModel *model = new TModel((GLchar*)path.c_str(), shader);
			//Guardamos el puntero en el mapa de models
			models[path] = model;
			//Devolvemos el puntero del modelo en el mapa
			return models[path];
		}
		std::cout << "ERROR CARGANDO MESH: " << path << std::endl;
		return NULL;
	}
	std::cout << "ERROR CARGANDO MESH: NO SE HA ESPECIFICADO UN MESH..." << std::endl;
	return NULL;
}

/*Si se pasan los dos paths, primero se busca por el vertexShader y lo devuelve si está en el mapa. Si no está, se crea
Si solo se pasa el vertex simplemente se busca en el mapa y se devuelve si está*/
Shader* ResourceManager::getShader(std::string vertexShader, std::string fragmentShader) {
	if (vertexShader != "" && fragmentShader != "") {
		if (shaders.find(vertexShader) != shaders.end()) {
			return shaders[vertexShader];
		} else {
			Shader *shader = new Shader((GLchar*)vertexShader.c_str(), (GLchar*)fragmentShader.c_str());
			shaders[vertexShader] = shader;
			return shaders[vertexShader];
		}
		std::cout << "Error al cargar shaders: " << vertexShader << " - " << fragmentShader << std::endl;
	} else if (fragmentShader == "") {
		if (shaders.find(vertexShader) != shaders.end()) {
			return shaders[vertexShader];
		}
	}
	return NULL;
}
void ResourceManager::getTexture(std::string path) {
}
