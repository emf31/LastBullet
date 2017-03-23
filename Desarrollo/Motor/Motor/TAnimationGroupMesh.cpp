#include "TAnimationGroupMesh.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>
#include "SceneManager.h"


TAnimationGroupMesh::TAnimationGroupMesh(const std::string & directory, unsigned int numAnimations) : sm(SceneManager::i()) {

	// Obtenemos los paths
	AnimationReader::LoadMeshesFromDirectory(directory, numAnimations, paths);

	processAnimations();

}

TAnimationGroupMesh::~TAnimationGroupMesh() {
	for (auto it = meshes.begin(); it != meshes.end(); ++it) {
		delete *it;
	}
	meshes.clear();
}

void TAnimationGroupMesh::processAnimations()
{
	//Cargamos el primero para obtener los materiales
	//y texturas
	AnimationMesh* fAnim = new AnimationMesh(paths.at(0));
	material = fAnim->getMaterials();
}



void TAnimationGroupMesh::beginDraw() {

	//Dibujamos los hijos (Si los hay)
	for (GLuint i = 0; i < this->meshes.size(); i++) {
		this->meshes[i]->beginDraw();
	}

}

