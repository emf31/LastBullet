#include "TCamera.h"
#include "SceneManager.h"



TCamera::TCamera() {
	setID(SceneManager::i().getEntityCount());
	SceneManager::i().aumentaEntityCount();
}


TCamera::~TCamera() {
}

void TCamera::beginDraw() {
}

void TCamera::endDraw() {
}
