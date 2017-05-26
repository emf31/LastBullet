#include "TAnimationGroupMesh.h"
#include "ResourceManager.h"
#include <glm/gtc/type_ptr.hpp>
#include "SceneManager.h"


TAnimationGroupMesh::TAnimationGroupMesh(const std::string & directory, unsigned int numAnimations) : 
	sm(SceneManager::i()), 
	NumFrames(numAnimations) 
{

	// Obtenemos los paths
	AnimationReader::LoadMeshesFromDirectory(directory, numAnimations, paths);

	processAnimations();

}

TAnimationGroupMesh::~TAnimationGroupMesh() {
	for (auto it = vectorModelos.begin(); it != vectorModelos.end(); ++it) {
		delete *it;
	}
	vectorModelos.clear();

	paths.clear();
}

void TAnimationGroupMesh::processAnimations()
{
	//Cargamos el primero para obtener los materiales y texturas

	for (std::size_t i = 0; i < NumFrames; i++) {
		AnimationMesh* anim = new AnimationMesh(paths.at(i));

		vectorModelos.push_back(anim);
	}

}



void TAnimationGroupMesh::draw() {

	//Dibujamos los hijos (Si los hay)
	for (std::vector<AnimationMesh*>::iterator it = vectorModelos.begin(); it != vectorModelos.end(); it++) {
		(*it)->draw();
	}
}


