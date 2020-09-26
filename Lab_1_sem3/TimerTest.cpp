#include "TimerTest.h"

void TestTimer()
{
	Timer t = Timer();

	t.Start();
	Sleep(1000);
	t.Pause();

	TestEnvironment::Assert((t.GetMS() > 950) && (t.GetMS() < 1050));
}