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
	//Cargamos el primero para obtener los materiales
	//y texturas
	AnimationMesh* fAnim = new AnimationMesh(paths.at(0));
	material = fAnim->getMaterials();

	//Procesamos el nodo con el material cargado
	fAnim->processNode(material);

	//Lo añadimos al vector de meshes
	vectorModelos.push_back(fAnim);

	for (std::size_t i = 1; i < NumFrames; i++) {
		AnimationMesh* anim = new AnimationMesh(paths.at(i));
		anim->processNode(material);
		vectorModelos.push_back(anim);
		anim->importer.FreeScene();
	}

	fAnim->importer.FreeScene();
}



void TAnimationGroupMesh::beginDraw() {

	//Dibujamos los hijos (Si los hay)
	for (GLuint i = 0; i < this->vectorModelos.size(); i++) {
		this->vectorModelos[i]->beginDraw();
	}

}

void TAnimationGroupMesh::endDraw()
{
}

