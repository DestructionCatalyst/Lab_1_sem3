#include "Timer.h"

void Timer::Start()
{
	if (!running)
	{
		startTime = clock();
		running = true;
	}	
}

void Timer::Pause()
{
	if (running)
	{
		clocks += clock() - startTime;
		running = false;
	}
}

int Timer::GetMS()
{
	if (running)
		clocks += clock() - startTime;

	return clocks;
}

