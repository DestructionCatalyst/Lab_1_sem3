#pragma once
#include <vector>

#include "UnitTest.h"

using std::vector;

class TestEnvironment
{
private:
	vector<UnitTest> tests{};
public:
	TestEnvironment& AddTest(UnitTest testToAdd);
	void RunAll();
private:
	void PrintResults(int testsPassed);
	
};

