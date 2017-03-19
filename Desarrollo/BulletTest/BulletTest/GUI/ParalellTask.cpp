
#include <ParalellTask.h>
#include <StateStack.h>

ParalellTask::ParalellTask()
{
}

void ParalellTask::Execute()
{
	mFinishedRunInGame = false;
	f1 = std::async(std::launch::async,&ParalellTask::RunInGame, this);
	
}

void ParalellTask::RunInGame()
{	
	StateStack::i().GetState(States::ID::InGame)->Inicializar();
	StateStack::i().GetState(States::ID::Carga)->Clear();
	StateStack::i().SetCurrentState(States::ID::InGame);
	mFinishedRunInGame = true;

}

void ParalellTask::write()
{
	for (int i = 0; i < 30;i++) {
		std::cout << "Aqui deberia seguir el juego" << std::endl;
	}
}

bool ParalellTask::IsFinished()
{
	return false;
}

float ParalellTask::GetCompletion()
{
	return 0.0f;
}
