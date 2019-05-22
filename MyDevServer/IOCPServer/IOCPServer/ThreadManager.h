#pragma once
#include "WorkerThread.h"
#include "AcceptThread.h"
#include "TimerThread.h"

class ThreadManager : public SingleTone<ThreadManager>
{
private:
	std::vector <MyThread*> threads;

	//std::vector <std::shared_ptr<std::thread>> threads;
	const int NUM_THREADS = 3;
public:
	explicit ThreadManager();
	virtual ~ThreadManager();
public:

	void CreateThreads();
	void AddThread(MyThread* myth);
	void JoinThreads();
	
	MyThread* FindThread(int TNum) {
		return threads[TNum];
	}
};