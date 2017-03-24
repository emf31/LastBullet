
#include <ParalellTask.h>
#include <GraphicEngine.h>

ParalellTask::ParalellTask()
{
}

void ParalellTask::Execute()
{
	mFinishedRunInGame = false;
	f1 = std::thread(&ParalellTask::RunInGame, this);
	
}

void ParalellTask::RunInGame()
{	
	//GraphicEngine::i().readAllAssets();
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
