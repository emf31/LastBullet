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
	for (auto it = meshes.begin(); it != meshes.end(); ++it) {
		delete *it;
	}
	meshes.clear();

	paths.clear();
}

void TAnimationGroupMesh::processAnimations()
{
	//Cargamos el primero para obtener los materiales
	//y texturas
	AnimationMesh* fAnim = new AnimationMesh(paths.at(0));
	material = fAnim->getMaterials();

	//Procesamos el nodo con el material cargado
	fAnim->processNode(material);

	//Lo añadimos al vector de meshes
	meshes.push_back(fAnim);

	for (std::size_t i = 1; i < NumFrames; i++) {
		AnimationMesh* anim = new AnimationMesh(paths.at(0));
		anim->processNode(material);
		meshes.push_back(anim);
		anim->importer.FreeScene();
	}

	fAnim->importer.FreeScene();
}



void TAnimationGroupMesh::beginDraw() {

	//Dibujamos los hijos (Si los hay)
	for (GLuint i = 0; i < this->meshes.size(); i++) {
		this->meshes[i]->beginDraw();
	}

}

void TAnimationGroupMesh::endDraw()
{
}

