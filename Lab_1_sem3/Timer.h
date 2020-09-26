#pragma once
#include <ctime>

class Timer
{
private:
	clock_t startTime = 0;
	clock_t clocks = 0;
	bool running = false;
public:
	void Start();
	void Pause();
	int GetMS();
};

