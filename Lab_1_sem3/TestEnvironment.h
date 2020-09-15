#pragma once
#include <vector>

#include "UnitTest.h"

using std::vector;

class TestEnvironment
{
private:
	vector<UnitTest*> tests{};
public:
	TestEnvironment& AddTest(UnitTest* testToAdd);
	void Run(int testIndex);
	void RunAll();
public:
	static void Assert(int expression);
private:
	void PrintResults(int testsPassed);
public:
	~TestEnvironment();
	
};

