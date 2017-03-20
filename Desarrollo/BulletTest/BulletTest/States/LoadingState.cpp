#include "LoadingState.h"



LoadingState::LoadingState()
{
}

LoadingState::~LoadingState()
{
}

void LoadingState::Inicializar()
{
	loadingStateGUI.inicializar();
	task = new ParalellTask();
	task->Execute();

}

void LoadingState::Clear()
{
	loadingStateGUI.destroy();
}

void LoadingState::HandleEvent()
{

	if (Input::i().leftMouseDown()) {

	loadingStateGUI.injectLeftMouseButton();

	}
	else if (Input::i().leftMouseUp()) {

	loadingStateGUI.injectLeftMouseButtonUp();

	}


}

void LoadingState::Update(Time timeElapsed)
{
	loadingStateGUI.update();
	std::cout << "Updateando loadingstate" << std::endl;
	//if(task->mFinishedRunInGame)
	//task->f1.get();
}

void LoadingState::Render(float interpolation, Time elapsedTime)
{

	float mouseX = (float)Input::i().getMouseX();
	float mouseY = (float)Input::i().getMouseY();

	//GUI
	loadingStateGUI.injectMousePosition(mouseX, mouseY);

	GraphicEngine::i().renderAll();
}




