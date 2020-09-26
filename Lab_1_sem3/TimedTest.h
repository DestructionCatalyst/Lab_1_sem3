#pragma once

#include "UnitTest.h"
#include "TimedTestCase.h"

class TimedTest :
	public UnitTest
{
public:
	TimedTest(int id, string name, function<void(Timer&)> testFunction);
	TimedTest(string name, function<void(Timer&)> testFunction);
protected:
	string GenerateResultString(TestResult result) override;
	void PrintResult(TestResult result) override;
private:
	int GetTestTime();
};

