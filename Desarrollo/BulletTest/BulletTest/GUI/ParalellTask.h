#pragma once
#include <future>

class ParalellTask {
public:
	ParalellTask();
	//virtual ~ParalellTask();

	void	Execute();
	void	RunInGame();
	void    write();
	bool	IsFinished();
	float	GetCompletion();
	std::future<void> f1;
	bool    mFinishedRunInGame;
private:
	void	RunTask();


	//sf::Thread                  mThread;

	bool	mFinished;
	bool	loading;
	


};