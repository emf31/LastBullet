#pragma once
#include <thread>

class ParalellTask {
public:
	ParalellTask();
	//virtual ~ParalellTask();

	void	Execute();
	void	RunInGame();
	void    write();
	bool	IsFinished();
	float	GetCompletion();
private:
	void	RunTask();


	//sf::Thread                  mThread;

	bool	mFinished;
	bool	loading;
	bool    mFinishedRunInGame;
	std::thread t1;

};