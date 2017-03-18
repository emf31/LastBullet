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
	std::thread t1;
private:
	void	RunTask();


	//sf::Thread                  mThread;

	bool	mFinished;
	bool	loading;
	bool    mFinishedRunInGame;


};